#include "Definition.h"
#include "ExternalVar.h"
#include <ctype.h>

int CountWord()
{

//Please implement your code here
int WordCount = 0;
int i;
 
for (i = 1; i <= LineLength; i++)
	{
	if ( ( isspace(Line[i-1]) == 0 ) && ( isspace(Line[i]) ) )
		{
		WordCount++;
		}
	}

return WordCount; 
}
