/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void printvar(){
  int var = 2;
  printf("var at %p\n",&var); //stack grows down
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p);
    printf ("Address of s is %p\n", s);
    void * c1 = malloc(8); //heap grows up
    printf ("Address of c1 is %p\n", c1);
    printvar();

    void * ch1 = malloc(8);
    void * ch2 = malloc(8);
    printf("Address diff is %p\n", ch2-ch1);

    return 0;
}
