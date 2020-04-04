#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

/**
 * @brief Get a (possibly pushed-back) character
 *
 * @return int Read character
 */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/**
 * @brief Push-back a character to buffer
 *
 * @param c Character to be buffered
 */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/**
 * @brief get next float from input into *pn
 *
 * @param pn    Pointer to save read float at
 *
 * @return int  Operation status
 */
int getfloat(float *pn)
{
    int c, sign;
    float power;

    /* skip white spaces */
    while(isspace(c = getch()))
        ;

    /* skip invalid characters before signal character */
    while (!isdigit(c) && c != EOF && c != '+' && c != '-' && (c = getch()))
        ;

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    /* skip invalid characters after signal character */
    while (!isdigit(c) && c != EOF && c != '+' && c != '-' && (c = getch()))
        ;

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    /* read decimal part */
    if (c == '.') {
        c = getch();

        for (power = 10.0; isdigit(c); c = getch(), power *= 10.0) {
            *pn +=  (c - '0') / power;
        }
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

main()
{
    int n;
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {
        printf("Read: %g\n", array[n]);
    }
}
