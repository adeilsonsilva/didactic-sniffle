#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * A function which converts a string of hexadecimal digits (including an optional
 * 0x or 0X) into its equivalent integer value. The allowable digits are 0 through
 * 9, a through f, and A through F.
 * 
 * @param char s[]          An array of hexadecimal digits
 * 
 * @return long double      Integer result of operation
 */
long int htoi(char s[])
{
    int i = 0;
    int _size = strlen(s);
    long double result = 0;

    /* Dealing with leading '0x' */
    if (_size > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    int base = (_size - i) - 1;
    int value = 0;

    /* If the number is too long, it will overflow anyway... */
    if (pow(16, base) > LONG_MAX) {
        return -1;
    }
    
    for (; i < _size; i++, base--) {
        if (s[i] >= '0' && s[i] <= '9') {
            value = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            value = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            value = s[i] - 'A' + 10;
        } else {
            result = -1;
            break;
        }
        result += value * pow(16, base);
    }
    
    return result;
}

/**
 * A program to convert hex to integer.
 */
main ()
{
    char hexA[] = "0x7DE";
    char hexB[] = "7DE";
    char hexC[] = "0X45eFa56";
    char hexD[] = "45eFa56";
    char hexE[] = "ffffffffff";
    char hexF[] = "0X0a";

    printf("%s : %.2f\n", hexA, htoi(hexA));
    printf("%s : %.2f\n", hexB, htoi(hexB));
    printf("%s : %.2f\n", hexC, htoi(hexC));
    printf("%s : %.2f\n", hexD, htoi(hexD));
    printf("%s : %.2f\n", hexE, htoi(hexE));
    printf("%s : %.2f\n", hexF, htoi(hexF));
}

