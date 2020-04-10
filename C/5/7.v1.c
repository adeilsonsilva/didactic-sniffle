/**
 * This file contains the version implemented in the book. As the exercise asks
 * for time comparison between versions, I decided to keep it.
 */

#include <stdio.h>
#include <string.h>

/* Maximum number of lines to be sorted */
#define     MAXLINES    5000

/* Array of pointers to lines */
char *lineptr[MAXLINES];

/**
 * @brief Read and store lines from input
 *
 * @param lineptr  Array of pointers to save lines at
 * @param maxlines Maximum number of lines to be read
 *
 * @return int     Number of read lines (success) or -1 (failure)
 */
int readlines(char *lineptr[], int maxlines);

/**
 * @brief Write sorted lines to output.
 *
 * @param lineptr Array of pointer to sorted lines
 * @param nlines  Number of lines to be printed
 */
void writelines(char *lineptr[], int nlines);

/**
 * @brief Sort an array of text lines.
 *
 * @param lineptr Input array to be sorted
 * @param left    Index of first position to start sorting
 * @param right   Index of last position to sort
 */
void qsort(char *lineptr[], int left, int right);

/* Sort input lines */
main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
    } else {
        printf("[*]\tError:\tInput too big to sort!\n");
        return -1;
    }

    return 0;
}


/* Maximum length of a input line */
#define     MAXLEN      1000

/**
 * @brief: Read a line into s
 *
 * @param s     Pointer to character array where line will be saved
 * @param lim   Max number of characters read per line
 *
 * @return int  Length of s
 */
int getline(char *s, int lim)
{
    char *aux = s;
    int c, n = 0;

    while (n < lim && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        n += 1;
    }

    *s = '\0';

    return s - aux;
}

/**
 * @brief Allocate memory and return its address
 *
 * @param n      Number of bytes to be allocated
 *
 * @return char* Address of allocated memory space
 */
char *alloc(int n);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len+1)) == NULL)
            return -1;

        strcpy(p, line);        /* Copy to permanent storage */
        lineptr[nlines++] = p; /* Assign its pointer */
    }

    return nlines;
}

void writelines (char *lineptr[], int nlines)
{
    int i = 0;

    while (nlines-- > 0)
        printf("[%4d]\t=>\t\"%s\"\n", i++, *lineptr++);
}

void qsort(char *v[], int left, int right)
{
    int i, last;

    /**
     * Forward declaration in old C style (pre-C90). We could just define swap
     * function before qsort.
     */
    void swap(char *v[], int i, int j);

    /* Do nothing if there are less than two elements */
    if (left >= right)
        return;

    swap(v, left, (left + right)/2);

    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    }

    swap(v, left, last);

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* Size of available space */
#define     ALLOCSIZE   MAXLINES*MAXLEN

/* Buffer for alloc */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    /* If n fits into available space */
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }

    return NULL;
}
