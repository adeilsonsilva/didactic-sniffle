#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */

int getline(char line[], int maxline);
int trim(char line[], int len);

/* Remove trailing blanks and whitespaces, delete blank lines. */
main()
{
    int len, newSize;    /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        newSize = trim(line, len);

        if (newSize > 0) {
            printf("READ: %04d; NEW SIZE: %04d | %s\n", len, newSize, line);
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
 * @param char line[]   String from input
 * @param int  len      String size
 * 
 * @return int          New string size
 */
int trim(char line[], int len)
{
    int i = len - 1; /* Last character is always '\0' */

    /* We need to delete entirely blank lines */
    if ((len == 1) && line[0] == '\n') {
        line[0] = '\0';
        return 0;
    }

    while (i > 0 && (line[i] == '\t' || line[i] == ' ' || line[i] == '\n')) {
        line[i] = '\0';       
        --i;         
    }

    return i+1;
}
