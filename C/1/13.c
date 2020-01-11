#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT  0  /* outside a word */
#define MAX_LENGTH 1001 /* No words shall be greater than this number */

/**
 * A program that draws an histogram of the length of words from input.
 */
main()
{
    int c, i = 0, wordSize = 0, state = OUT;
    int histogram[MAX_LENGTH];

    /* Initialize word length vector */
    for (i = 0; i < MAX_LENGTH; histogram[i] = 0, i++);

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            /* The end of a word. */
            if (wordSize > 0 && wordSize < MAX_LENGTH) {
                histogram[wordSize] += 1;
            }
            wordSize = 0;
        } else if (state == OUT) {
            state = IN;
        }

        if (state == IN) {
            /* Start of a new word */
            wordSize++;
        }
    }

    /* Prints horizontal histogram */
    for (i = 0; i < MAX_LENGTH; i++) {
        int j = 0;

        if (histogram[i] > 0) {
            printf("%05d (%05d): ", i, histogram[i]);
            
            for (j = 0; j < histogram[i]; j++) {
                printf("|");
            }

            printf("\n");
        }
    }
}
