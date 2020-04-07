#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

/**
 * @brief: Read a line into s
 *
 * @param s     Pointer to character array where line will be saved
 * @param lim   Max number of characters read per line
 *
 * @return int  Length of s
 */
int getline(char *s, int lim)
{
    char *aux = s;
    int c, n = 0;

    while (n < lim && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        n += 1;
    }

    *s = '\0';

    return s - aux;
}

/**
 * @brief Reverses string s in place.
 *
 * @param s String to be reversed.
 */
void reverse(char *s)
{
    int c = 0, size = strlen(s);
    char *end = s + size - 1;

    while (s < end)
    {
        c = *s;
        *s++ = *end;
        *end-- = c;
    }
}

/**
 * @brief A function to check for the rightmost occurence of t in s.
 *
 * @param char* s   The string to be searched at
 * @param char* t   The pattern to be searched for
 *
 * @return int      Position of rightmost occurrence .
 */
int strindex(char *s, char *t)
{
    char *s_aux = s;
    char *t_aux = t;

    int i = 0, rightmost = -1;

    for (i = 0; *s != '\0'; s++, i++) {
        for (s_aux = s, t_aux = t; *t_aux != '\0' && *s_aux==*t_aux; s_aux++, t_aux++);

        if (t_aux > t && *t_aux == '\0') {
            rightmost = i;
        }

    }

    return rightmost;
}

main ()
{
    int n = 0;
    char input[MAXSTR];

    char numbers[] = "12345";

    printf("Enter a line to be read:\n");

    n = getline(input, MAXSTR);
    printf("%d characters were read:\t\"%s\"\n", n, input);

    reverse(input);
    printf("Check it reversed:\t\"%s\"\n", input);

    reverse(input);
    printf("Check it reversed back:\t\"%s\"\n", input);

    printf("The rightmost index of \"%s\" inside \"%s\" is %d\n", numbers, input, strindex(input, numbers));

}
