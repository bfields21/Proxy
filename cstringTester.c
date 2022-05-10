#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "csapp.h"
#include "cstring.h"

//main function to test the two functions in cstring.c

int main()
{

   assert(indexOf("http://student2.cs.appstate.edu/~can", '/', 1) == 5);
   printf("Test: (indexOf(\"http://student2.cs.appstate.edu/~can\", '/', 1) == 5) passed\n");
   assert(indexOf("http://student2.cs.appstate.edu/~can", '/', 2) == 6);
   printf("Test: (indexOf(\"http://student2.cs.appstate.edu/~can\", '/', 2) == 6) passed\n");
   assert(indexOf("http://student2.cs.appstate.edu/~can", '/', 3) == 31);
   printf("Test: (indexOf(\"http://student2.cs.appstate.edu/~can\", '/', 3) == 31) passed\n");
   assert(indexOf("http://student2.cs.appstate.edu/~can", '*', 1) == -1);
   printf("Test: (indexOf(\"http://student2.cs.appstate.edu/~can\", '*', 1) == -1) passed\n");

   char host[MAXLINE];
   int firstIdx = indexOf("http://student2.cs.appstate.edu/~can", '/', 2);
   int lastIdx = indexOf("http://student2.cs.appstate.edu/~can", '/', 3);
   buildCString(host, "http://student2.cs.appstate.edu/~can", firstIdx + 1, lastIdx - 1);
   assert(strcmp(host, "student2.cs.appstate.edu") == 0);
   printf("Test: buildCString(host, \"http://student2.cs.appstate.edu/~can\", firstIdx + 1, lastIdx - 1); passed\n");

   firstIdx = indexOf("http://localhost:8080/index.html\r\n", '/', 2);
   lastIdx = indexOf("http://localhost:8080/index.html\r\n", ':', 2);
   buildCString(host, "http://localhost:8080/index.html\r\n", firstIdx + 1, lastIdx - 1);
   assert(strcmp(host, "localhost") == 0);

   char path[MAXLINE];
   firstIdx = indexOf("http://student2.cs.appstate.edu/~can\r\n", '/', 3);
   lastIdx = indexOf("http://student2.cs.appstate.edu/~can\r\n", '\r', 1);
   buildCString(path, "http://student2.cs.appstate.edu/~can", firstIdx, lastIdx - 1);
   assert(strcmp(path, "/~can") == 0);
   printf("Test: buildCString(path, \"http://student2.cs.appstate.edu/~can\\r\\n\", firstIdx, lastIdx - 1); passed\n");

   //third parameter should be greater than first parameter; return empty string
   char bad[MAXLINE];
   buildCString(bad, "hello world", 4, 3);  
   assert(strcmp(bad, "") == 0);
   printf("Test: buildCString(bad, \"hello world\", 4, 3) passed\n");

   printf("\nAll tests passed.\n");
   return 0;
}
