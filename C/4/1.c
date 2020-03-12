#include <stdio.h>

/* Maximum input line length */
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

/* Pattern to be searched for. */
char pattern[] = "ould";

/**
 * A program to find all lines matching pattern.
 */
main()
{
    char line[MAXLINE];

    int pos = 0;

    while (getline(line, MAXLINE) > 0) {
        pos = strindex(line, pattern);
        printf("[*] Rightmost position of '%s' in '%s' is: '%d'\n", pattern, line, pos);
    }

    return 0;
}

/**
 * A function to read a line into s.
 *
 * @param char[] s      A string to save the read line at.
 * @param int    lim    Maximum length of a line.
 *
 * @return int Length of read string.
 */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/**
 * A function to check for the rightmost occurence of t in s.
 *
 * @param char[] s The string to be searched at
 * @param char[] t The pattern to be searched for
 *
 * @return int      Position of rightmost occurrence .
 */
int strindex(char s[], char t[])
{
    int i, j, k, rightmost = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') {
            rightmost = i;
        }
    }

    return rightmost;
}