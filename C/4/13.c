#include <stdio.h>
#include <string.h>

/**
 * @brief Reverses a string s in place.
 *
 * @param s The string to be reversed.
 */
void reverse (char s[])
{
    static int begin = 0; /* Index of start of the string s. */
    static int end = 1;   /* Index of end of the string s. */

    /* If we are in the first run of this function */
    if (begin == 0) {
        end = strlen(s) - 1; /* Compute string size, excluding null character */
    }

    /* If begin overlap end, we reached base case. */
    if (begin >= end) {
        /* Resetting static variables */
        begin = 0;
        end = 1;
    } else {
        int _c = 0; /* Temporary variable to perform the swap. */

        /* Swap values */
        _c = s[begin];
        s[begin++] = s[end];
        s[end--] = _c;

        /* Call reverse recursively */
        reverse(s);
    }
}

main()
{
    char first[] = "Socorram-me, subi no onibus em Marrocos!";
    char second[] = "ovo";
    char third[] = "Lorem ipsum";

    printf("[*]\"%s\" =>\n", first);
    reverse(first);
    printf("\t\t\"%s\"\n\n", first);

    printf("[*]\"%s\" =>\n", second);
    reverse(second);
    printf("\t\t\"%s\"\n\n", second);

    printf("[*]\"%s\" =>\n", third);
    reverse(third);
    printf("\t\t\"%s\"\n\n", third);
}
