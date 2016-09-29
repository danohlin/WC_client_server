#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Definition.h"
#include "ExternalVar.h"


struct fileWc requestedFileWc;
int responseWc = 1;
char returnMessage[256];

extern int WC(struct fileWc *ptr_requested);

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
int sockfd, newsockfd, portno;
socklen_t clilen;
char buffer[100];
struct sockaddr_in serv_addr, cli_addr;
int n;

if (argc < 2) {
	fprintf(stderr,"ERROR, no port provided\n");
	exit(1);
}
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
	error("ERROR opening socket");
bzero((char *) &serv_addr, sizeof(serv_addr));
portno = atoi(argv[1]);
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port = htons(portno);
if (bind(sockfd, (struct sockaddr *) &serv_addr,
	sizeof(serv_addr)) < 0)
	error("ERROR on binding");

//Run this in a loop if want server to accept one new client connection after another. Uncomment while loop to enable.
//while (1==1){
listen(sockfd,5);
printf("Server is waiting for connection...\n");
clilen = sizeof(cli_addr);
newsockfd = accept(sockfd,
	(struct sockaddr *) &cli_addr,
	&clilen);
if (newsockfd < 0)
	error("ERROR on accept");
bzero(buffer,100);
n = read(newsockfd,buffer,99);
if (n < 0) error("ERROR reading from socket");

// save filename from client input
char *token = strtok(buffer, "\n");
strcpy(requestedFileWc.filename, token);

printf("Counting words for file: %s\n",requestedFileWc.filename);

//count the file using WC
responseWc = WC(&requestedFileWc);

if (responseWc == 0) {
	//WC was successful in counting the file. Compile and send response message to client.
	bzero(returnMessage,256);
	snprintf(returnMessage, sizeof returnMessage, "%s contains %d words, %d characters, and %d lines", requestedFileWc.filename, requestedFileWc.wordCount, requestedFileWc.charCount, requestedFileWc.lineCount);
	n = write(newsockfd,returnMessage,sizeof(returnMessage));
} else if (responseWc == 1) {
        bzero(returnMessage,256);
        strcpy(returnMessage, "Error: file not available for Word Count.");
        n = write(newsockfd,returnMessage,sizeof(returnMessage));
}
if (n < 0) error("ERROR writing to socket");

//zero out requestedFileWC
bzero(requestedFileWc.filename, sizeof(requestedFileWc.filename));
requestedFileWc.wordCount = 0;
requestedFileWc.charCount = 0;
requestedFileWc.lineCount = 0;

close(newsockfd);
//} //end of loop

close(sockfd);
return 0;

}

