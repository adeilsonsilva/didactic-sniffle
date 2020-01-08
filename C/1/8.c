#include <stdio.h>

/**
 * Counting blanks, tabs and newlines from stdin.
 */
main()
{
    int input, blanks = 0, tabs = 0, nls = 0;

    while ((input = getchar()) != EOF) {
        switch (input){
            case ' ':
                ++blanks;
                break;
            case '\t':
                ++tabs;
                break;
            case '\n':
                ++nls;
                break;
            default:
                break;
        }
    }

    printf("\n==============================================\n");
    printf("Blanks: %d; Tabs: %d; Newlines: %d\n", blanks, tabs, nls);
}
