#include <stdio.h>

/**
 * A function that converts an ASCII character to lower case.
 * 
 * @param  int c The character to be converted
 * 
 * @return int   Resultant character
 */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

/**
 * A program to test bitcount.
 */
main()
{
    printf("lower('a')\t=>\t%c\n", lower('a'));
    printf("lower('b')\t=>\t%c\n", lower('b'));
    printf("lower('c')\t=>\t%c\n", lower('c'));
    printf("lower('d')\t=>\t%c\n", lower('d'));
    printf("lower('e')\t=>\t%c\n", lower('e'));
    printf("lower('A')\t=>\t%c\n", lower('A'));
    printf("lower('B')\t=>\t%c\n", lower('B'));
    printf("lower('C')\t=>\t%c\n", lower('C'));
    printf("lower('D')\t=>\t%c\n", lower('D'));
    printf("lower('E')\t=>\t%c\n", lower('E'));
    /** 
     * Following example only throws compiler warnings.
     * 'printf("lower(❤️)\t=>\t%c\n", lower("❤️"));'
     */
}