#include <stdio.h>

/**
 * Q: "When either a tab or a single blank would suffice to reach a tab stop, which
 * should be given preference?"
 *
 * A: I think a single blank should be chosen in this case, because the tabstop is
 * a value that might change. (i.e "hello['\t'|' ']world" with a tabstop of 3 VS with a tabstop of 4)
 */
#define TABSTOP 3

int round(double);

/**
 * A program entab that replaces strings of blanks by the minimum number of tabs
 * and blanks to achieve the same spacing.
 */
main()
{
    int c, i, j, blanksCounter = 0, blanksInserted = 0, tabsInserted = 0;

    while (1) {
        /* Read until next TABSTOP or EOF. */
        for (i = 0; i < TABSTOP && (c = getchar()) != EOF; i++) {
            /**
             * If a tab char is found, we need to print whitespaces until next tabstop.
             */
            if (c == ' ') {
                blanksCounter += 1;
            } else {
                printf("%c", c);
                if (c == '\n') {
                    /**
                     * The counter is reset after a newline (set to -1 because
                     * we are inside a for loop and will be updated).
                     */
                    i = -1;
                }
            }
        }

        /**
         * Break out of main loop if EOF has been reached.
         * (Continue if TABSTOP was reached).
         */
        if (c == EOF) {
            break;
        } else if (i == TABSTOP) {
            /**
             * We fill most of the space with 'blanksCounter / TABSTOP'
             * and what is left with 'blanksCounter % TABSTOP' blanks.
             */
            tabsInserted = round((double) blanksCounter / (double) TABSTOP); /* Truncated to int */
            blanksInserted = blanksCounter % TABSTOP;

            /*printf("%d %d %d %d", i, blanksCounter, tabsInserted, blanksInserted);*/

            for (j = 0; j < tabsInserted; j++) {
                printf("\\t");
            }

            /* We only need to use blanks if there are too much space to be filled */
            if (blanksCounter >= TABSTOP) {
                for (j = 0; j < blanksInserted; j++) {
                    printf(" ");
                }
            }

            blanksCounter = 0;
        }
    }
}

/**
 * In C, integer division is truncated to 0. We use this function to change this
 * behavior.
 *
 * There are some caveats about this function. It is being used here because I
 * don't wanna use "math.h" just yet.
 *
 * @param double    x   The double which will be converted to int
 *
 * @return int          Operation result
 */
int round(double x)
{
    if (x < 0.0)
        return (int)(x - 0.5);

    return (int)(x + 0.5);
}
