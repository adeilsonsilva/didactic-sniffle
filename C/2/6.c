#include <stdio.h>

/**
 * A function that returns x with the n bits that begin at position p set to
 * the rightmost n bits of y, leaving the other bits unchanged.
 *
 * @param unsigned x Number to have its bits set.
 * @param int      p Position of the first bit to be set.
 * @param int      n Amount of bits to be set.
 * @param unsigned y Number to have its bits used to set.
 *
 * @return unsigned  Number resultant from operation.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /**
     * Shifting factor to be applied. In this exercise righmost bit index is 0,
     * hence why we add 1.
     */
    int shift = (p - n + 1);

    /**
     * We create a mask with rightmost n bits being 1 and everything else 0.
     *
     * That's done by using 0's one-complement (all bits set to 1), shifting
     * it left by n bits (creating n 0 bits), and taking one-complement of
     * it all, leading to the desired mask.
     */
    unsigned mask = ~(~0 << n);

    /**
     * We apply (y & mask) in order to keep only the righmost bits of y.
     * Then we shift it to align the those bits to position p.
     */
    unsigned maskedY = (y & mask) << shift;

    /**
     * We start by shifting our mask to position p, and taking its
     * one-complement (everythin will be 0 from p to p - n). Now, we just have
     * to apply (x & shifted_mask) to set bits from x (from p to p-n) to 0.
     *
     * It means we have all original bits of x, with the ones that will be set
     * zeroed out.
     */
    unsigned maskedX = x & (~(mask << shift));

    /**
     * Now we just apply (maskedX | maskedY) to set the zeroed-out bits of x
     * to whatever maskedY has on that position (inclusive or).
     */
    return maskedX | maskedY;
}

/**
 * A program to test changing bits.
 */
main()
{
    printf("setbits(0, 4, 3, 5)\t=>\t%u\n", setbits(0, 4, 3, 5));
    printf("setbits(0, 4, 3, ~0)\t=>\t%u\n", setbits(0, 4, 3, ~0));
    printf("setbits(85, 4, 3, 2)\t=>\t%u\n", setbits(85, 4, 3, 2));
    printf("setbits(~0, 4, 5, 0)\t=>\t%u\n", setbits(~0, 4, 5, 0));
    printf("setbits(~0, 31, 31, 0)\t=>\t%u\n", setbits(~0, 31, 31, 0));
    printf("setbits(0, 15, 4, 10)\t=>\t%u\n", setbits(0, 15, 4, 10));
}
