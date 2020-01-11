#include <stdio.h>

/**
 * Converts Fahrenheit to Celsius.
 */
float fahr_to_celsius(float);

/**
 * Print Fahrenheit-Celsius Table with header.
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
    printf("|  Fahrenheit  |   Celsius     |\n");
    printf("|------------------------------|\n");

    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("|     %3.0f      |    %6.1f     |\n", fahr, celsius);
        fahr = fahr + step;
    }

    /* Print table footer */
    printf("|------------------------------|\n");
}

float fahr_to_celsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}