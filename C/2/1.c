#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * A program to print the range of basic data types.
 * 
 * Ps: Control characters for "printf" are much more meaningful
 * than it seems. Its definitely worth to check it out. Most of
 * the time this code produced wrong outputs was due to using
 * the wrong control character.
 * 
 * http://man7.org/linux/man-pages/man3/printf.3.html 
 */
main ()
{
    printf("[*] Data types ranges!\n");

    /* There is no 'UCHAR_MIN' defined, so we set manually to 0. */
    printf("\t[+] unsigned char: [%d, %d]\n", 0, UCHAR_MAX);
    printf("\t[+] char: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("\t[+] signed char: [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);

    printf("\t-------------------------------\n");

    printf("\t[+] unsigned short int: [%hu, %hu]\n", 0, USHRT_MAX);
    printf("\t[+] unsigned int: [%u, %u]\n", 0, UINT_MAX);
    printf("\t[+] unsigned long int: [%lu, %lu]\n", 0, ULONG_MAX);

    printf("\t[+] short int: [%hi, %hi]\n", SHRT_MIN, SHRT_MAX);
    printf("\t[+] int: [%i, %i]\n", INT_MIN, INT_MAX);
    printf("\t[+] long int: [%li, %li]\n", LONG_MIN, LONG_MAX);

    printf("\t-------------------------------\n");

    printf("\t[+] float: [%e, %e]\n", FLT_MIN, FLT_MAX);
    printf("\t[+] double: [%e, %e]\n", DBL_MIN, DBL_MAX);

    printf("\t[+] long double: [%Le, %Le]\n", LDBL_MIN, LDBL_MAX);
}