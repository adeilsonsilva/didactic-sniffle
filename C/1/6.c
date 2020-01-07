#include <stdio.h>

/**
 * Verify that the expression getchar() != EOF is 0 or 1.
 *
 * Try sending EOF too (Ctrl+D on linux).
 */
main()
{
    int c, i;

    for (i = 0; i < 10; i++) {
        c = getchar() != EOF;
        printf("%d\n", c);
    }

}
