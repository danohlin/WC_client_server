#include "Definition.h"
#include "ExternalVar.h"
#include <stdio.h>
#include <string.h>


extern int Readline(FILE *f),CountWord(),CountsUpdate(int LineChars,int LineWords);

char Line[MaxLine];  /* one line from the file */

int NChars = 0,  /* number of characters seen so far */
    NWords = 0,  /* number of words seen so far */
    NLines = 0,  /* number of lines seen so far */
    LineLength;  /* length of the current line */ 

char folder[9] = "Files/"; //name of subfolder containing actual files to WC
char path[115];


int *WC(struct fileWc *r)
{
	struct fileWc temp;
	strcpy(temp.filename, r->filename);
	//attempt to open the file
	memset(path, '\0', sizeof(path));
	snprintf(path, sizeof path, "%s%s", folder, temp.filename);
        FILE *fileToWc;
	fileToWc = fopen(path, "r");

	if (fileToWc == NULL){
		printf("Unable to open file: %s\n", temp.filename);
		return 1;
	}

	LineLength = 0;
	int LineChars = Readline(fileToWc);
	int LineWords;
	while (LineChars > 0){
        	
	       LineWords = CountWord();
	       CountsUpdate(LineChars, LineWords);
	       LineChars = 0;
	       LineWords = 0;

//uncomment below listed ToString() function call, to print the text of the file to the screen
//ToString();

        	LineChars = Readline(fileToWc);
        }

        fclose(fileToWc);

	temp.charCount = NChars;
        temp.wordCount = NWords;
        temp.lineCount = NLines;
	*r = temp;

	NChars = 0;
	NWords = 0;
	NLines = 0;

	return 0;
}
