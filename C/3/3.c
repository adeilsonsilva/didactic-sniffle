#include <stdio.h>

/* Control string size */
#define LIMIT 999

/**
 * A function that expands shorthand notations like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2.
 *
 * @param char[] s1 The string with the shorthand notation
 * @param char[] s2 The expanded string
 *
 * @return void
 */
void expand(char s1[], char s2[])
{
    int i = 0, j = 0, c = 0, first = -1, last = -1;

    /* Dealing with leading dash. */
    if (s1[0] == '-') {
        i++;
    }

    while(s1[i] != '\0') {
        /* Find first character of sequence. */
        first = s1[i++];
        /**
         * If we are on a dash and the char after the dash is greater than the
         * character before, we have a range.
         */
        last = (s1[i] == '-' && s1[i+1] > s1[i-1])? s1[++i] : -1;

        /* If a range could be defined. */
        if (first != -1 && last != -1) {
            for (c = first; c <= last; j++, c++) {
                s2[j] = c;
            }
            s2[j] = '\0';
            first = last = -1;
        }
    }

    return;
}

/**
 * A program to test string expansion.
 */
main()
{
    char input1[] = "a-z";
    char output1[LIMIT];

    char input2[] = "a-b-c";
    char output2[LIMIT];

    char input3[] = "a-z0-9";
    char output3[LIMIT];

    char input4[] = "-a-z";
    char output4[LIMIT];

    expand(input1, output1);
    printf("expand('%s') => '%s'\n", input1, output1);

    expand(input2, output2);
    printf("expand('%s') => '%s'\n", input2, output2);

    expand(input3, output3);
    printf("expand('%s') => '%s'\n", input3, output3);

    expand(input4, output4);
    printf("expand('%s') => '%s'\n", input4, output4);
}
