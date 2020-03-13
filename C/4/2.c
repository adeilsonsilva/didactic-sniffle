#include <stdio.h>
#include <ctype.h>

/**
 * Converts a string to double
 *
 * @param char[] s The string to be converted
 *
 * @return double  Value of input string
 */
double atof(char s[])
{
    double val, power, result;
    int i, j, sign, sci_sign, sci_value = 0;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* decimal part */
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    result = sign * val / power;

    /* Checking for scientific notation. */
    if (s[i] == 'e')
        i++;
    sci_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (sci_value = 0; isdigit(s[i]); i++)
        sci_value = 10 * sci_value + (s[i] - '0');

    while (sci_value > 0) {
        if (sci_sign == -1) {
            result /= 10;
        } else {
            result *= 10;
        }

        sci_value--;
    }

    return result;
}

/**
 * A program to test string to double conversion.
 */
main ()
{
    printf("'%s' => %f\n", "123.45e-6", atof("123.45e-6"));
    printf("'%s' => %f\n", "123.45e6", atof("123.45e6"));
    printf("'%s' => %f\n", "145e-6", atof("145e-6"));
    printf("'%s' => %f\n", "145e6", atof("145e6"));
    printf("'%s' => %f\n", "895.56", atof("895.56"));
}