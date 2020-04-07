#include <stdio.h>

#define MAXSTR 1000

/**
 * @brief Copies at most n chars from string s to t.
 *
 * @param s Source string
 * @param t Target string
 * @param n Number of characters
 */
void pstrncpy(char *s, char *t, int n)
{
    int i = 0;

    while (i++ < n && (*t++ = *s++))
        ;
}

/**
 * @brief Copies at most n chars from string s to the end of t.
 *
 * @param s Source string
 * @param t Target string
 * @param n Number of characters
 */
void pstrncat(char *s, char *t, int n)
{
    int i = 0;

    /* while *t is not '\0', go to the next char. */
    while (*t && t++)
        ;

    /**
     * That looks dangerous, we don't check for t's size.
     * But that's how they do it in the book, so we copy 's'
     * to the end of 't' while *s is not '\0'.
     */
    while ((*t++ = *s++) && i++ < n)
        ;

}

/**
 * @brief Compares at most n chars from string s and t.
 *
 * @param s     Source string
 * @param t     Target string
 * @param n     Number of characters to be matched
 *
 * @return int  1 if they match, 0 otherwise
 */
int pstrncmp(char *s, char *t, int n)
{
    int i = 0;

    /* Check if characters match */
    while ((*s++ == *t++) && ++i != n)
        ;

    /* If i == n all chars are matched */
    if (i == n)
        return 1;

    return 0;
}

/**
 * @brief Implementing a strcat function.
 */
main ()
{
    char t1[MAXSTR] = "The first string is";
    char s1[] = " IN NEED OF COMPLETION!";

    char t2[MAXSTR] = "abcdef678910";
    char s2[MAXSTR] = "12345";
    char s3[MAXSTR] = "123456789";

    printf("\"%s\"\t(pstrncat)=>\t", t1);
    pstrncat(s1, t1, 24);
    printf("\"%s\"\n", t1);

    printf("\"%s\"\t(pstrncpy)=>\t", t2);
    pstrncpy(s2, t2, 5);
    printf("\"%s\"\n", t2);

    printf("\"%s\"\tpstrncmp\t\"%s\"=>\t%d\n", s2, s3, pstrncmp(s2, s3, 5));
    printf("\"%s\"\tpstrncmp\t\"%s\"=>\t%d\n", t1, s2, pstrncmp(t1, s2, 5));
}
