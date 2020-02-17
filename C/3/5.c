#include <stdio.h>
#include <string.h>
#include <limits.h>

#define LIM 99999

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/**
 * Converts integer x to a string with the number converted to base b.
 *
 * @param int    x The integer to be converted
 * @param char[] s The resultant string
 * @param int    b The base to be changed to
 *
 * @return void
 */
void itob(int x, char s[], short int b)
{
    /* Set of possible characters */
    char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    /* Handling int overflow */
    long n = x;

    if (b < 0 || b > 36) {
        s[0] = '\0';
        printf("Invalid radix: %hi!\n", b);
        return;
    }

    if (n < 0)
        n = -n;

    do {
        /**
         * The remainder of the division of and and the base is a number in base
         * 10 (because n is base 10). We use it as the position in our set of
         * possible characters.
         */
        s[i++] = characters[n % b];
    } while((n /= b) > 0);
    s[i] = '\0';

    reverse(s);
}

main()
{
    char result[LIM];

    itob(10, result, 2);
    printf("itob(10, 2) => '%s'\n", result);

    itob(15, result, 16);
    printf("itob(15, 16) => '%s'\n", result);

    itob(32, result, 2);
    printf("itob(32, 2) => '%s'\n", result);

    itob(2130440, result, 10);
    printf("itob(2130440, 10) => '%s'\n", result);

    itob(128, result, 16);
    printf("itob(128, 16) => '%s'\n", result);

    itob(INT_MAX, result, 2);
    printf("itob(INT_MAX, 2) => '%s'\n", result);

    itob(INT_MIN, result, 2);
    printf("itob(INT_MIN, 2) => '%s'\n", result);

    itob(INT_MIN, result, 16);
    printf("itob(INT_MIN, 16) => '%s'\n", result);
}
