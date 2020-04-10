/**
 * The time results are about the same as in v1.
 */

#include <stdio.h>
#include <string.h>

#define     MAXLINES    5000  /* Maximum number of lines to be sorted */
#define     MAXLEN      1000  /* Maximum length of a input line */

/**
 * @brief Read and store lines from input
 *
 * @param lineptr  Array of pointers to lines
 * @param lines    2D array to store lines values at
 * @param maxlines Maximum number of lines to be read
 *
 * @return int     Number of read lines (success) or -1 (failure)
 */
int readlines(char *lineptr[], char lines[MAXLINES][MAXLEN], int maxlines);

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
    char *lineptr[MAXLINES];      /* Array of pointers to lines */
    char lines[MAXLINES][MAXLEN]; /* 2D Array of text lines */
    int nlines;                   /* Number of read lines */

    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
    } else {
        printf("[*]\tError:\tInput too big to sort!\n");
        return -1;
    }

    return 0;
}

/**
 * @brief Read a line into s
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
 * HINT: 'lines' is declared like this because we know its size at compile time.
 *       'lineptr', at the other hand, is an array of pointers where each
 *       position points to  an char array of unknown size (dinamically
 *       allocated). In this exercise we are not allocating dinamically, we use
 *       'lines' to hold our read lines and 'lineptr' points to it. Sorting
 *       is easier this way.
 */
int readlines(char *lineptr[], char lines[MAXLINES][MAXLEN], int maxlines)
{
    int len, nlines = 0;
    char line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;

        strcpy(lines[nlines], line);        /* Copy to permanent storage */
        lineptr[nlines++] = lines[nlines]; /* Assign its pointer */
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
