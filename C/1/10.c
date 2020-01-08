#include <stdio.h>

/**
 * Copy input to output, replacing each tab by \t, each backspace by \b,
 * and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
 */
main()
{
    int input, blanks = 0;

    while ((input = getchar()) != EOF) {
        switch (input) {
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("\\\\"); /* escaping the escape! */
                break;
            default:
                printf("%c", input);
                break;
        }
    }

}
