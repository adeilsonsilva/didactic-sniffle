#include <stdio.h>

/**
 * Copy input to output, replacing each string of one or more blanks by a single blank.
 */
main()
{
    int input, blanks = 0;

    while ((input = getchar()) != EOF) {
        if (input != ' ' || blanks == 0) {
            printf("%c", input);
            blanks = 0;
        }

        if (input == ' ') {
            ++blanks;
        }
    }

}
