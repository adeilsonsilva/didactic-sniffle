#include <stdio.h>

/**
 * The exercise asks: "Should n be a variable or a symbolic parameter?"
 *
 * IMHO, it should be a symbolic constant (in the pdf is written symbolic
 * parameter) because its value is known at compile time and this value
 * won't change throughout program execution. If it was in a variable, there
 * would be the need to access memory during execution to get TABSTOP value.
 */
#define TABSTOP 4

/**
 * A program 'detab' that replaces tabs in the input with the proper number of
 * blanks to space to the next tab stop. Basically, there is a tabstop every Nth
 * position in the input string and all we need to do is expand output with
 * whitespaces until the next tabstop every time a tab character (\t) is found
 * within length of the current tabstop. The concept of a tabstop makes more
 * sense in the context of typewriters and robust text editor (for alignment).
 *
 * For more info on tabstops check: https://en.wikipedia.org/wiki/Tab_stop
 */
main()
{
    int c, i = 0, j = 0;

    while (1) {
        /* Read until next TABSTOP or EOF. */
        for (i = 0; i < TABSTOP && (c = getchar()) != EOF; i++) {
            /**
             * If a tab char is found, we need to print whitespaces until next tabstop.
             */
            if (c == '\t') {
                for (j = (TABSTOP - i); j > 0; j--) {
                    printf(" ");
                }
                /**
                 * We are back at the beginning of a tabstop (set to -1 because
                 * we are inside a for loop and will be updated).
                 */
                i = -1;
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
        }
    }
}
