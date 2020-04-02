#include <string.h>    /* for  strlen() */
#include <ctype.h>
#include "calc.h"

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static int buffered = EOF;

    if (buffered != EOF) {
        c = buffered;
        buffered = EOF;
    }

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';

    if (c != EOF)
        buffered = c;

    return NUMBER;
}
