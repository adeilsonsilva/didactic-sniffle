#include <stdio.h>

/**
 * Using a block structure removes warnings and allow us to use the same macro
 * with different types without redeclaring '_z' variable.
 */
#define swap(t, x, y) { t _z = x; x = y; y = _z; }

main()
{
    /**
     * Using separate scopes so we can put declarations after function calls.
     * ISO C90 forbids it and I don't wanna declare all variables
     * at the beginning of main. :D
     */
    {
        int a = 10, b = 20;

        printf("[*] %d %d\t=>\t", a, b);
        swap(int, a, b);
        printf("%d\t%d\n", a, b);
    }

    {
        float c = 35.62, d = 012.51;

        printf("[*] %g %g\t=>\t", c, d);
        swap(float, c, d);
        printf("%g\t%g\n", c, d);
    }

    {
        char i = '^', j = '~';

        printf("[*] '%c' '%c'\t=>\t", i, j);
        swap(char, i, j);
        printf("'%c'\t'%c'\n", i, j);
    }
}
