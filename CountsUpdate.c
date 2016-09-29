#include "Definition.h"
#include "ExternalVar.h"


extern int CountWord();

void CountsUpdate(int LineChars, int LineWords)
{
// Please implement your code here  
NChars += LineChars;
NWords += LineWords;
NLines++;

}

