#include <stdio.h>

/**
 * A function that returns the value of the integer x rotated to the right by n
 * positions.
 *
 * @param unsigned x Number to have its bits rotated.
 * @param int      n Amount of bits to be rotated.
 *
 * @return unsigned  Number resultant from operation.
 */
unsigned rightrot(unsigned x, int n)
{
    int n_bits = 0;
    unsigned k = x;

    /**
     * We create a mask to keep rightmost n bits.
     */
    unsigned rightmostMask = ~(~0 << n);
    
    if (x == 0) {
        return 0;
    }

    /**
     * We nee to count how many bits 'x' uses.
     */
    while (k) {
        k /= 2;
        n_bits++;
    }

    /**
     * We apply the mask to keep rightmost n bits of x, then shift them left by
     * a factor of how many bytes were kept after the move (i.e. if x uses 7
     * bits and is shifted right by 3, we shift to the left by 3).
     */
    return ((x & rightmostMask) << (n_bits - (n % n_bits))) | (x >> n);
}

/**
 * A program to test changing bits.
 */
main()
{
    printf("rightrot(255, 1)\t=>\t%u\n", rightrot(255, 1));
    printf("rightrot(0, 4)\t\t=>\t%u\n", rightrot(0, 4));
    printf("rightrot(85, 4)\t\t=>\t%u\n", rightrot(85, 4));
    printf("rightrot(~0, 4)\t\t=>\t%u\n", rightrot(~0, 4));
    printf("rightrot(~0, 31)\t=>\t%u\n", rightrot(~0, 31));
    printf("rightrot(10, 3)\t\t=>\t%u\n", rightrot(10, 3));
}
