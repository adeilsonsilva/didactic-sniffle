#include <stdio.h>

/**
 * Q: "When either a tab or a single blank would suffice to reach a tab stop, which
 * should be given preference?"
 *
 * A: I think a tab should be given preference if there's a need to keep the 
 * result consistent to a change in TABSTOP size. For examplem consider a 
 * TABSTOP of 8. If we are at position 7, either a blank or a tab would suffice
 * to reach the TABSTOP. But if we use a blank and increase TABSTOP value later,
 * our output would not lead to this new TABSTOP. Kinda confusing, I guess.
 */
#define TABSTOP 8

/* Inside a blank sequence. */
#define IN 1

/* Outside a blank sequence. */
#define OUT 0

/**
 * A program entab that replaces strings of blanks by the minimum number of tabs
 * and blanks to achieve the same spacing.
 */
main()
{
    int c, state = OUT, baseColumn = 0, currentColumn = 0;

    while ((c = getchar()) != EOF) {
        if (state == OUT) {
            if (c == ' ' || c == '\t') {
                /**
                 * When a tab character or a whitespace is found, it means we
                 * are at the start of a new sequence of blanks.
                 */ 
                state = IN;
                baseColumn = currentColumn;
            } else {
                putchar(c);
            }
            
        } else if (state == IN) {
            if (!(c == ' ' || c == '\t')) {
                state = OUT;

                /**
                 * If we are inside a sequence and a non-blank character is found,
                 * we calculate and print the right amount of tabs and whitespaces.
                 */
                if (c != '\n') {
                    int j = 0;

                    /**
                     * First we add as many tabs as possible. We do that by checking
                     * if, starting from the column where the blank sequence started,
                     * adding a tab will lead us to the current column.
                     */
                    for (j = baseColumn; j + (TABSTOP - j % TABSTOP) <= currentColumn; j+= (TABSTOP - j % TABSTOP)) {
                        putchar('\t');
                    }
                    
                    /**
                     * Then, if adding a tab will take as further than current column,
                     * we add whitespaces until we reach current column.
                     */
                    for (; (j + 1) <= currentColumn; j++) {
                        putchar(' ');
                    }
                }

                putchar(c);
            }
        }
        
        /**
         * Update current column number. 
         */
        if (c == '\t') {
            /**
             * If a tab is found, current column jumps to the next TABSTOP
             * multiple (that's the reason for % operator).
             */
            currentColumn += (TABSTOP - currentColumn % TABSTOP);
        } else if (c == '\n') {
            /* The counter is reset after a newline */
            currentColumn = 0;
        } else {
            currentColumn++;
        }
    }
}
