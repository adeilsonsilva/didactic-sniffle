#include <stdio.h>

#define MAX_LENGTH 1001 /* No words shall be greater than this number */

/**
 * A program that draws an histogram of the frequencies of chars from input.
 */
main()
{
    int c, i = 0;
    int histogram[MAX_LENGTH];

    /* Initialize word length vector */
    for (i = 0; i < MAX_LENGTH; histogram[i] = 0, i++);

    while ((c = getchar()) != EOF) {
        histogram[c] += 1;
    }

    /* Prints horizontal histogram */
    for (i = 0; i < MAX_LENGTH; i++) {
        int j = 0;

        if (histogram[i] > 0) {
            printf("%c (%05d): ", i, histogram[i]);
            
            for (j = 0; j < histogram[i]; j++) {
                printf("|");
            }

            printf("\n");
        }
    }
}
