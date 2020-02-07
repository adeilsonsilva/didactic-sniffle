#include <stdio.h>

#define LIM 999

/**
 * A program to read a line, without logical operators.
 */
main ()
{
    char s[LIM];
    int i = 0, c = 0;

    /**
     * "By definition, the numeric value of a relational or logical expression
     *  is 1 if the relation is true, and 0 if the relation is false."
     */
    for (i=0; ((i < LIM-1) + ((c=getchar()) != '\n') + (c != EOF)) == 3; ++i)
        s[i] = c;

    printf("%s\n", s);
}