#include <stdio.h>

/**
 * A function that counts the number of 1-bits in its integer argument.
 * 
 * @param unsigned x Number to have its 1-bits counted
 * 
 * @return int       Number of 1-bits
 */
int bitcount(unsigned x)
{
    int b = 0;

    /**
     * Q: Why operation (x &= (x-1)) deletes the rightmost 1-bit in x?
     * 
     * A: Because subtracting 1 turns off the rightmost bit in x, and applying
     * bitwise and guarantees that we are not adding new bits to x (after all,
     * we want to count how many there are).
     * 
     * We keep on counting while x is greater than zero and the assignment
     * operation returns greater than or equals to zero because the last
     * operation (the one that turns x into 0) is also a deletion of the
     * rightmost bit and needs to be counted (think of x = 8).
     */
    while (x > 0 && (x &= (x-1)) >= 0) {
        b++;
    }
    
    return b;
}

/**
 * A program to test bitcount.
 */
main()
{
    printf("bitcount(255)\t=>\t%u\n", bitcount(255));
    printf("bitcount(56452)\t=>\t%u\n", bitcount(56452));
    printf("bitcount(0)\t=>\t%u\n", bitcount(0));
    printf("bitcount(~0)\t=>\t%u\n", bitcount(~0));
    printf("bitcount(10)\t=>\t%u\n", bitcount(10));
    printf("bitcount(32)\t=>\t%u\n", bitcount(32));
    printf("bitcount(16)\t=>\t%u\n", bitcount(16));
    printf("bitcount(8)\t=>\t%u\n", bitcount(8));
    printf("bitcount(4)\t=>\t%u\n", bitcount(4));
    printf("bitcount(2)\t=>\t%u\n", bitcount(2));
    printf("bitcount(1)\t=>\t%u\n", bitcount(1));
}