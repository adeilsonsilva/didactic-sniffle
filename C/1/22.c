#include <stdio.h>

/* The number of characters allowed before the "fold". */
#define N 50

/**
 * We define a hard limit for our prints. We must break the line at the last
 * non-blank character before N-th column. As we are indexing from 0, we
 * subtract 1 from our limit. As the last character of the line will always be
 * the '\n' we insert, we subtract one more. Hence, N-2.
 * 
 * TODO: think about the cases when N < 10
 */
#define HARD_LIMIT N-2

/* Dealing tab characters */
#define TABSTOP 4

/* Inside a blank sequence. */
#define IN 1

/* Outside a blank sequence. */
#define OUT 0

/**
 * A function to apply the optimal amount of blank characters between two columns
 * 
 * @param int  start  The base column before whitespace sequence
 * @param int  end    The end column after whitespace sequence
 * 
 * @return void
 */
void entab (int start, int end)
{
    int j = start;

    /**
     * First we add as many tabs as possible. We do that by checking
     * if, starting from the column where the blank sequence started,
     * adding a tab will lead us to the current column.
     */
    for (; j + (TABSTOP - j % TABSTOP) <= end; j+= (TABSTOP - j % TABSTOP)) {
        putchar('\t');
    }

    /**
     * Then, if adding a tab will take as further than current column,
     * we add whitespaces until we reach current column.
     */
    for (; (j + 1) <= end; j++) {
        putchar(' ');
    }
}

/**
 * A program to "fold" long input lines into two or more shorter lines after
 * the last non-blank character that occurs before the n-th column of input.
 */
main()
{
    int c, state = OUT, baseColumn = 0, currentColumn = 1;

    while ((c = getchar()) != EOF) {

        if (currentColumn < HARD_LIMIT) {
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
                if (
                    !(c == ' ' || c == '\t')
                ) {
                    /**
                     * If we are inside a sequence and a non-blank character is found,
                     * we need to entab and print the read char.
                     */
                    state = OUT;

                    if (c != '\n') {
                        entab(baseColumn, currentColumn);
                    }

                    putchar(c);
                }
            }
        } else if (currentColumn == HARD_LIMIT) {
            /**
             * If we are at the last possible column of the line and we read a
             * non-blank, entab if needed and print it.
             */
            if (!(c == ' ' || c == '\t' || c == '\n')) {
                if (state == IN) {
                    entab(baseColumn, currentColumn);
                }
                putchar(c);
            }

            state = OUT;
            currentColumn = 0;
            putchar('\n');
        }

        if (c == '\n') {
            currentColumn = 0;
        } else if (c == '\t') {
            /**
             * If a tab is found, current column jumps to the next TABSTOP
             * multiple (that's the reason for % operator).
             */
            currentColumn += (TABSTOP - currentColumn % TABSTOP);
        } else {
            currentColumn++;
        }
    }
}
