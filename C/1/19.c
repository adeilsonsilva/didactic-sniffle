#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char line[], char reversed[], int len);

/* Remove trailing blanks and whitespaces, delete blank lines. */
main()
{
    int len, idx;    /* current line length */
    char line[MAXLINE];    /* current input line */
    char reversed[MAXLINE];    /* reversed input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, reversed, len);

        printf("READ: %04d; | %s\n", len, reversed);

        /* We need to clear out the reversed string. */
        for (idx = 0; idx < MAXLINE; idx++) {
            reversed[idx] = '\0';
        }
    }

    return 0;
}

/* getline:  read a line into s, return length  */
int getline(char s[],int lim)
{
    int c, i, last = 0;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    /* Because of operator precedence, we don't need to check if i < lim -1 */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    /* Adding the null character */
    s[i] = '\0';

    return i;
}

/**
 * Removes trailing blanks and tabs from a line
 * 
 * @param char line[]       String from input
 * @param char reversed[]   Array with result
 * @param int  len          String size
 * 
 * @return void
 */
void reverse(char line[], char reversed[], int len)
{
    int i = 0, j = 0;

    for (i = len-2; i >=0; i--, j++) {
        reversed[j] = line[i];
    }

    reversed[len] = '\0';
}
