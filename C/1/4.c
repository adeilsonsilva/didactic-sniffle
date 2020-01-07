#include <stdio.h>

/**
 * Print Celsius-Fahrenheit Table with header.
 * for fahr = 0, 20, ..., 300;
 *
 * Floating-point version.
 */

main()
{
    float fahr, celsius;
    float lower, upper, step;

    /* lower limit of temperatuire scale */
    lower = 0;
    /* upper limit */
    upper = 300;
    /* step size */
    step = 20;
    fahr = lower;

    /* Print table header */
    printf("|------------------------------|\n");
    printf("|   Celsius     |  Fahrenheit  |\n");
    printf("|------------------------------|\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("|    %6.1f     |     %3.0f      |\n", celsius, fahr);
        fahr = fahr + step;
    }

    /* Print table footer */
    printf("|------------------------------|\n");
}
