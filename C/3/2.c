#include <stdio.h>

/* Defining a maximum size to strings */
#define SIZE 999

/**
 * A function that converts characters like newline and tab into visible escape
 * sequences like \n and \t as it copies the string t to s.
 *
 * @param char[] s String to be copied to
 * @param char[] t Source string
 *
 * @return void
 */
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    char c;

    while ((c = t[i++]) != '\0') {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
    }

    /* Adding null character */
    s[j] = '\0';

    return;
}

/**
 * A function that converts visible escape sequences like \n and \t into
 * characters like newline and tab as it copies the string t to s.
 *
 * @param char[] s String to be copied to
 * @param char[] t Source string
 *
 * @return void
 */
void escape_back(char s[], char t[])
{
    int i = 0;
    int j = 0;
    char c;

    while ((c = t[i++]) != '\0') {
        switch (c) {
            case '\\':
                if (t[i] == '\\' && t[i+1] == 'n') {
                    s[j++] = '\n';
                } else if (t[i] == '\\' && t[i+1] == 't') {
                    s[j++] = '\t';
                }
                i += 2;
                break;
            default:
                s[j++] = c;
                break;
        }
    }

    /* Adding null character */
    s[j] = '\0';

    return;
}

/**
 * A program to test string copying.
 * For the sake of simplicity, we assume only '\t' and '\n' can be scaped.
 */
main()
{
    char input1[SIZE] = "A \n test \t whatever.";
    char output1[SIZE];
    char output2[SIZE];

    escape(output1, input1);

    printf("escape('%s') => '%s'\n", input1, output1);

    escape_back(output2, output1);

    printf("escape_back('%s') => '%s'\n", output1, output2);
}
