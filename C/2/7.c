#include <stdio.h>

/**
 * A function that returns x with the n bits that begin at position p inverted
 * (i.e., 1 changedinto 0 and vice versa), leaving the others unchanged.
 *
 * @param unsigned x Number to have its bits inverted.
 * @param int      p Position of the first bit to be inverted.
 * @param int      n Amount of bits to be inverted.
 *
 * @return unsigned  Number resultant from operation.
 */
unsigned invert(unsigned x, int p, int n)
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
     * We start by shifting our mask to position p, and taking its
     * one-complement (everything will be 0 from p to p - n). Now, we just have
     * to apply (x & shifted_mask) to set bits from x (from p to p-n) to 0.
     *
     * It means we have all original bits of x, with the ones that will be set
     * zeroed out.
     */
    unsigned maskedX = x & (~(mask << shift));

    /**
     * This variable holds the only the flipped bits from x at position p.
     *
     * We do this by shifting them right and applying a mask [(x >> shift) & mask],
     * to keep only the original bits from x. Then we flip them and apply the mask
     * again, to keep only flipped bits as the rightmost bits. After that, we just
     * have to shift them left again to position p.
     */
    unsigned flippedBits = (~((x >> shift) & mask) & mask) << shift;

    /**
     * Now we just apply (maskedX | flippedBits) to set the zeroed-out bits of x
     * to whatever flippedBits has on that position (inclusive or).
     */
    return maskedX | flippedBits;
}

/**
 * A program to test changing bits.
 */
main()
{
    printf("invert(255, 1, 2)\t=>\t%u\n", invert(255, 1, 2));
    printf("invert(0, 4, 3)\t\t=>\t%u\n", invert(0, 4, 3));
    printf("invert(85, 4, 3)\t=>\t%u\n", invert(85, 4, 3));
    printf("invert(~0, 4, 5)\t=>\t%u\n", invert(~0, 4, 5));
    printf("invert(~0, 31, 31)\t=>\t%u\n", invert(~0, 31, 31));
    printf("invert(0, 15, 4)\t=>\t%u\n", invert(0, 15, 4));
}
