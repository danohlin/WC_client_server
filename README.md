# WC_client_server
Client-Server word count in C

The sourcecode for program "server" will compile (using the included Makefile) into a properly running executable called server. server should reside in the directory that contains the subdirectory called Files. client.c will compile using command: "gcc client.c -o client".


client sends one specific filename to the server and prints out the results returned from the server.

server receives one file name from client and peforms a count of words, chars and lines. It then returns this info to client.

Server

run as:
'''./server port_number'''
e.g. 
~~~~
./server 2540
Server is waiting for connection…
Counting words for file: Japan_earthquake.txt
~~~~

Client

run as:
'''./client hostname port_number'''
e.g. 
~~~~
./client example.com 2540
Please enter the file name: Japan_earthquake.txt
Japan_earthquake.txt contains # words, # characters and # lines
~~~~
