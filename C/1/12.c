#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT  0  /* outside a word */

/**
 * A program that prints its input one word per line.
 */
main()
{
    int c, blanks = 0, state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (blanks == 0) { printf("\n"); blanks++; } /* avoids printing lots of whitespaces */
        } else if (state == OUT) {
            state = IN;
        }

        if (state == IN) {
            printf("%c", c);
            blanks = 0;
        }
    }

}
