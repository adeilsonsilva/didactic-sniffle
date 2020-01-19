#include <stdio.h>

/* Outside a comment. */
#define OUT 0
/* Inside a comment. */
#define IN 1
/* Inside a quoted string */
#define QUOTED_STRING 2
/* Inside a symbolic constant definition */
#define DEFINE 3
/* Found first slash but no asterisks yet */
#define LEFT 4
/* Found closing asterisk but not closing slash */
#define RIGHT 5

/**
 * A program to check a C source file for rudimentary syntax errors.
 */
main()
{
    int c, state = OUT;

    int commentsCounter = 0, quotesCounter = 0,
        parenthesesCounter = 0, bracketsCounter = 0,
        bracesCounter = 0;

    while ((c = getchar()) != EOF) {

        /* putchar(c); */

        if (state == OUT) {
            if (c != '/') {
                if (c == '\'' || c == '"') {
                    /* Start of a quoted string. */
                    state = QUOTED_STRING;
                    quotesCounter++;
                } else if (c == '#') {
                    /**
                     * If we find a hash we are (most likely) in a define.
                     */
                    state = DEFINE;
                } else if (c == '(') {
                    parenthesesCounter++;
                } else if (c == ')') {
                    parenthesesCounter--;
                } else if (c == '{') {
                    bracketsCounter++;
                } else if (c == '}') {
                    bracketsCounter--;
                } else if (c == '[') {
                    bracesCounter++;
                } else if (c == ']') {
                    bracesCounter--;
                }
            } else {
                state = LEFT;
            }
        } else if (state == QUOTED_STRING) {
            if (c == '\'' || c == '"') {
                /* If inside a quoted string and find its closing match. */
                quotesCounter--;
                state = OUT;
            }
        } else if (state == LEFT) {
            if (c == '*') {
                /**
                 * If one slash was found before and now we find an asterisk,
                 * we are inside a comment.
                 */
                state = IN;
                commentsCounter++;
            } else {
                state = OUT;
            }
        }  else if (state == RIGHT) {
            if (c == '/') {
                /**
                 * If one asterisk was found before and now we find a slash,
                 * we are no longer in a comment.
                 */
                state = OUT;
                commentsCounter--;
            } else {
                state = IN;
            }
        } else if (state == IN) {
            if (c == '*') {
                /* If inside a comment and an closing asterisk is found. */
                state = RIGHT;
            }
        } else if (state == DEFINE) {
            if (c == '\n') {
                /**
                 * If in a define, and a newline is found, we are no longer
                 * in a define.
                 */
                state = OUT;
            }
        }
    }

    if (
        quotesCounter
        || commentsCounter
        || parenthesesCounter
        || bracketsCounter
        || bracesCounter
    ) {
        printf("Bad formatted characters: \n\t[+] ");
        printf(
            "\' | \": %d; /*: %d; (): %d; {}: %d; []: %d;\n", 
            quotesCounter, commentsCounter, parenthesesCounter,
            bracketsCounter, bracesCounter
        );
    } else {
        printf("Everything is okay!\n");
    }
}