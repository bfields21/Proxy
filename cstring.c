#include <string.h>
#include "csapp.h"
#include "cstring.h"

//
// Takes as input a C-string, a character, and a count
// and returns the index of appearance number count of that
// character in C-string. -1 is returned if the character
// doesn't appear that number of times.
//
// Example: indexOf("student2.cs.appstate.edu", '.', 1) returns 8
//          because cstr[8] is '.'
// Example: indexOf("student2.cs.appstate.edu", '.', 2) returns 11
//          because cstr[10] is '.'
// Example: indexOf("student2.cs.appstate.edu", '.', 4) returns -1
//          because '.' isn't in the cstr four times
int indexOf(char * cstr, char whatChar, int whichCt)
{
    //look for the whichCt occurance of whatChar in cstr
    int count = 0;
    int end = strlen(cstr);
    int i;
    for (i = 0; i != end; i++)
    {
        if (cstr[i] == whatChar)
        {
            count ++;
            if (count == whichCt)
            {
                return i;
            }
        }
    }    
    return -1;  //not found
}

//
// Copies characters cstr[startIdx] through cstr[endIdx] into result
// and places a NULL character ('\0') after the last character so that
// result holds a C-string.
//
// Example: buildCstring(result, "http://localhost:8080/index.html", 7, 16)
//          will set result to "localhost"
//
void buildCString(char result[MAXLINE], char * cstr, int startIdx, int endIdx)
{

    //build a string out of cstr[startIdx] .. cstr[endIdx]
    int index = 0;
    int i;
    for (i = startIdx; i <= endIdx; i++)
    {
        result[index] = cstr[i];
        index++;
    }
    result[index] = '\0';
}
    
