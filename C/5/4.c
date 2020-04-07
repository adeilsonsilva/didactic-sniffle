#include <stdio.h>
#include <string.h>

#define MAXSTR 1000

/**
 * @brief Checks if string t occurs at the end of the string s.
 *
 * @param s     String to be looked at
 * @param t     String to be searched for
 *
 * @return int  1 if occurs 0 otherwise
 */
int strend(char *s, char *t)
{
    int source_size = strlen(s);
    int target_size = strlen(t);

    /**
     * If t fits in s, jump to where t should start .
     */
    if (target_size <= source_size) {
        s += (source_size - target_size);

        /* Check if characters match */
        while ((*s == *t) && s++ && t++)
            ;

        /* If t ended, it is inside s */
        if (*t == '\0')
            return 1;
    }

    return 0;
}

/**
 * @brief Implementing a strend function.
 */
main ()
{
    char t1[MAXSTR] = "ABCDEF";
    char s1[MAXSTR] = "The alphabet is ABCDEF";

    char t2[MAXSTR] = "lorem ipsum";
    char s2[MAXSTR] = "lorem ipsum doler sit amet";

    printf("Checking for \"%s\" at the end of \"%s\"\t=>\t%d\n", t1, s1, strend(s1, t1));
    printf("Checking for \"%s\" at the end of \"%s\"\t=>\t%d\n", t2, s2, strend(s2, t2));
}
