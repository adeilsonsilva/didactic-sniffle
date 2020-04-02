#include <stdio.h>

#define MAX 11
#define MAX_STR 99999

/**
 * @brief Converts an integer into a string recursively.
 *
 * @param n     Number to be converted
 * @param s     Array of characters to be filled
 *
 * @return int  Number of characters inserted into the string
 */
int itoa(int n, char s[])
{
    int pos = 0;

    if (n / 10) {
        pos = itoa(n / 10, s);
    } else {
        if (n < 0) {
            s[pos++] = '-'; /* We add a sign at the first position, in case its a negative number */
        }
    }

    if (n < 0) {
        n = -n;
    }

    s[pos++] = (n % 10) + '0';
    s[pos] = '\0';

    return pos;
}

main()
{
    char result[MAX_STR] = "";

    int i = 0;
    int numbers[] = {
        23123,
        -53352,
        24,
        12,
        0,
        -516361361,
        123632,
        236,
        352,
        1412,
        -12414
    };

    for (i = 0; i < MAX; i++) {
        itoa(numbers[i], result);
        printf("\t[*] %d => \"%s\"\n", numbers[i], result);
    }
}
