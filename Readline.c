#include "Definition.h"
#include "ExternalVar.h"
#include <stdio.h>


int Readline(FILE *f)
{
//Please implement your code here
int i = 0;
int c;
while ( ( (c = fgetc(f)) != EOF ) && ( i < MaxLine - 1 ) )
	{
	Line[i] = (char)c;
	i++;
	if (c == '\n') break;
	if (i == MaxLine - 1) 
		{
		printf("current line: %s\n ", Line);
		printf("Input Error: Individual lines in file must be under %d characters long.\n", MaxLine);
		exit(1);
		}
	}

LineLength = i;
return i;

}

  

