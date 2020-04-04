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
 * @brief get next integer from input into *pn
 *
 * @param pn    Pointer to save read integer at
 *
 * @return int  Operation status
 */
int getint(int *pn)
{
    int c, sign;

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
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

main()
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        printf("Read: %d\n", array[n]);
    }
}
