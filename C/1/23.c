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
 * As stated in the book: "Don't forget to handle quoted strings and character
 * constants properly. C comments do not nest".
 */
/* /* */
#define TEST /

/**
 * A program to remove all comments from a C program.
 * 
 * CAVEAT: Ansi C does not support comments with double slashes ('//').
 */
main()
{
    int c, state = OUT;

    /* testing */
    c = 3 / 3;

    while ((c = getchar()) != EOF) {

        if (state == OUT) {
            if (c != '/') {
                if (
                    (c == '\'' || c == '\"')
                ) {
                    /* Start of a quoted string. */
                    state = QUOTED_STRING;
                } else if (c == '#') {
                    /**
                     * If we find a hash we are (most likely) in a define.
                     */
                    state = DEFINE;
                }
                putchar(c);
            } else {
                state = LEFT;
            }
        } else if (state == QUOTED_STRING) {

            if (
                (c == '\'' || c == '"')
            ) {
                /* If inside a quoted string and find its closing match. */
                state = OUT;
            }
            putchar(c);
        } else if (state == LEFT) {
            if (c == '*') {
                /**
                 * If one slash was found before and now we find an asterisk,
                 * we are inside a comment.
                 */
                state = IN;
            } else {
                state = OUT;
                printf("/%c", c);
            }
        }  else if (state == RIGHT) {
            if (c == '/') {
                /**
                 * If one asterisk was found before and now we find a slash,
                 * we are no longer in a comment.
                 */
                state = OUT;
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
            putchar(c);
        }
    }
}
