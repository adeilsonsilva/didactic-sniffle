/**
 * As stated in the book: " This is a bare-bones version of the UNIX program wc."
 *
 * The exercise asks "How would you test the word count program?
 * What kinds of input are most likely to uncover bugs if there are any?"
 *
 * That's a tricky question because the problem is not at the code per se. The definition
 * of a word is what makes this program problematic. As it only treats spaces/newlines/tabs
 * as separators, sequences such as "a#jfa%    kdfd*#ad" are counted as two words, even tough
 * they have no meaning.
 */

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT  0  /* outside a word */

/* count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}
