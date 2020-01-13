#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print all input lines that are longer than 80 characters. */
main()
{
    int len;    /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("SIZE: %04d | \"%s\"\n", len, line);
        }
    }

    return 0;
}

/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
    int c, i, last = 0;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n' && i < lim-1) {
        s[i] = c;
        ++i;
    }

    /* Avoiding the segmentation fault. */
    if (i < lim-1) {
        last = i;
    } else {
        last = lim -1;
    }

    /* Adding the null character */
    s[last] = '\0';

    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')
      ++i;
}
