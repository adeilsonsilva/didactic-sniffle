#include <stdio.h>
#include <ctype.h>

/**
 * A function which returns the first location in a string s1 where any
 * character from thestring s2 occurs, or -1 if s1 contains no characters
 * from s2.
 *
 * @param char[] s1 String to be searched at
 * @param char[] s2 String to be checked against
 *
 * @return int
 */
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s2[i] != '\0'; i++) {
        for (j = 0; s1[j] != '\0'; j++) {
            if (s2[i] == s1[j]) {
                return j;
            }
        }
    }

    return -1;
}

/**
 * A program to test string searching.
 */
main ()
{
    char vowels[] = "aeiou";
    char a[] = "*****a*****.";
    char e[] = "******e******.";
    char i[] = "*******i*******.";
    char o[] = "********o********.";
    char u[] = "*********u********.";

    printf("\t%d %d %d %d %d \n", any(a, vowels), any(e, vowels), any(i, vowels), any(o, vowels), any(u, vowels));
}

