#include <stdio.h>
#include <string.h>
#include <limits.h>

#define LIM 99999

/**
 * Q: In a two’s complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize-1)). Explain why not.
 *
 * A: The largest negative number doesn't fit into an int when its signal is
 * changed, i.e., it is greater than INT_MAX.
 */

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
 * Converts integer x to a string.
 *
 * @param int    x The integer to be converted
 * @param char[] s The resultant string
 *
 * @return void
 */
void itoa(int x, char s[])
{
    int i = 0;

    /**
     * We cast input int to a long to handle the case of INT_MIN.
     * Remember that int interval is [-2147483648, 2147483647].
     */
    long n = x;

    if (n < 0)  /* record sign */
        n = -n;          /* make n positive */

    /* generate digits in reverse order */
    do {
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */

    if (x < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

main()
{
    char result[LIM];

    itoa(958585, result);
    printf("itoa(958585) => '%s'\n", result);

    itoa(10, result);
    printf("itoa(10) => '%s'\n", result);

    itoa(958000, result);
    printf("itoa(958000) => '%s'\n", result);

    itoa(-914124, result);
    printf("itoa(-914124) => '%s'\n", result);

    itoa(INT_MIN+1, result);
    printf("itoa(INT_MIN+1) => '%s'\n", result);

    itoa(INT_MIN, result);
    printf("itoa(INT_MIN) => '%s'\n", result);
}
