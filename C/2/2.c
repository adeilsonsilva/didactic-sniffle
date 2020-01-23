#include <stdio.h>

/**
 * A program to read a line, without logical operators.
 */
main ()
{
    const int lim = 999;
    char s[lim];
    int i = 0, c = 0;

    /**
     * "By definition, the numeric value of a relational or logical expression
     *  is 1 if the relation is true, and 0 if the relation is false."
     */
    for (i=0; ((i < lim-1) + ((c=getchar()) != '\n') + (c != EOF)) == 3; ++i)
        s[i] = c;

    printf("%s\n", s);
}