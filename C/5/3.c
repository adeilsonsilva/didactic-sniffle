#include <stdio.h>

#define MAXSTR 1000

/**
 * @brief Copies the string s to the end of t.
 *
 * @param s Source string
 * @param t Target string
 */
void pstrcat(char *s, char *t)
{
    /* while *t is not '\0', go to the next char. */
    while (*t && t++)
        ;

    /**
     * That looks dangerous, we don't check for t's size.
     * But that's how they do it in the book, so we copy 's'
     * to the end of 't' while *s is not '\0'.
     */
    while ((*t++ = *s++))
        ;

}

/**
 * @brief Implementing a strcat function.
 */
main ()
{
    char t1[MAXSTR] = "The first string is";
    char s1[MAXSTR] = " IN NEED OF COMPLETION!";

    char t2[MAXSTR] = "Say what again, I da";
    char s2[MAXSTR] = "re you, I DOUBLE DARE YOU, MOTHERFUCKER!";

    printf("\"%s\"\t=>\t", t1);
    pstrcat(s1, t1);
    printf("\"%s\"\n", t1);

    printf("\"%s\"\t=>\t", t2);
    pstrcat(s2, t2);
    printf("\"%s\"\n", t2);
}
