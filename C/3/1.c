#include <stdio.h>
#include <time.h> /* time measurements */

#define SIZE 999999

/**
 * This function performs a binary search.
 * 
 * @param int       x      Value to be searched for
 * @param int[]     v      Reference to the vector to search at
 * @param int       n      Size of the vector
 * 
 * @return int             Index of found value or -1
 */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/**
 * This function performs a binary search.
 * 
 * @param int       x      Value to be searched for
 * @param int[]     v      Reference to the vector to search at
 * @param int       n      Size of the vector
 * 
 * @return int             Index of found value or -1
 */
int binary_search(int x, int v[], int n)
{
    int low, high, mid;

    for (
        low = 0, high = n - 1, mid = high / 2; /* initialization */
        low <= high && x != v[mid];            /* condition */
        mid = (low + high) / 2                 /* increment */
    ) {
        
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x == v[mid]) {
        return mid;
    }

    return -1;
}

/**
 * A program to test binary search
 */
main()
{
    int idx, result;
    /**
     * Beware that, by using a constant size, this array is allocated at the
     * stack. It means SIZE can't be a very high value, because the OS will not
     * allow to allocate that much space on the stack. Things could be different
     * in the heap.
     */
    int v[SIZE];

    clock_t t;
    double time_taken;

    /* Initializing v */
    t = clock();
    for (idx = 0; idx < SIZE; idx++) { v[idx] = idx; }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Allocation took %f seconds\n", time_taken);

    /* binsearch (book version) */
    t = clock();
    result = binsearch(324781, v, SIZE);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("binsearch(324781, v, SIZE) => %i, %.10fs\n", result, time_taken);

    /* binary_search (improved version) */
    t = clock();
    result = binary_search(324781, v, SIZE);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("binary_search(324781, v, SIZE) => %i, %.10fs\n", result, time_taken);
}