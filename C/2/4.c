#include <stdio.h>
#include <ctype.h>


/**
 * A function to find a character inside a string.
 *
 * @param char[] s  The null-terminated string to be searched
 * @param int    c  The character to be searched for
 *
 * @return int      A "boolean" indicating if the character was found or not.
 */
int find (char s[], int c)
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c)
            return 1;
    }

    return 0;
}

/**
 * A function that deletes each character in s1 that matches any character in
 * the strings2.
 *
 * @param char[] s1 String to be squeezed
 * @param char[] s2 String to be checked against
 *
 * @return void
 */

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (!find(s2, s1[i]))
            s1[j++] = s1[i];
    s1[j] = '\0';
}

/**
 * A program to test string squeezing.
 */
main ()
{
    char first[] = "A string with multiple characters.";
    char second[] = "aeiou";

    printf("*** BEFORE ***\n");

    printf("\t'%s'\n\t'%s'\n", first, second);

    printf("\n*** AFTER ***\n");

    squeeze(first, second);

    printf("\t'%s'\n\t'%s'\n", first, second);
}

