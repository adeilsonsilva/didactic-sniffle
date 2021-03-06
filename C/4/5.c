#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <math.h>    /* for  sin(), exp() and pow() */

#define MAXOP 100      /* max size of operand or operator */
#define NUMBER '0'     /* signal that a number was found */
#define LAST 'L'       /* signal that last value command was found */
#define SWAP '~'       /* signal that swap command was found */
#define DUPLICATE 'D'  /* signal that duplicate command was found */
#define CLEAR 'C'      /* signal that clear was found */

int getop(char []);
void push(double);
double pop(void);
double last(void);
void swap(void);
void duplicate(void);
void clear(void);

/* reverse Polish calculator */
main()
{
    int type;
    double op2, aux;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int) pop() % (int) op2);
            else
                printf("error: zero divisor\n");
        case 'S':
            push(sin(pop()));
            break;
        case 'E':
            push(exp(pop()));
            break;
        case '^':
            op2 = pop();
            aux = pop();
            if (aux == 0.0 && op2 <= 0.0) {
                printf("error: pow(%f, %f) is not a valid operation.\n", aux, op2);
            } else {
                push(pow(aux, op2));
            }
            break;
        case LAST:
            printf("top value: %f\n", last());
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}

#define MAXVAL  100  /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push:  push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* return top value from stack without popping */
double last(void) {
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* duplicate top value from stack */
void duplicate(void) {
    if (sp > 0) {
        push(last());
    } else {
        printf("error: stack empty\n");
    }
}

/* swap top two values from stack */
void swap(void) {
    double aux1, aux2;

    if (sp >= 2) {
        aux1 = pop();
        aux2 = pop();
        push(aux1);
        push(aux2);
    } else {
        printf("error: can't swap with %d elements\n", sp);
    }
}

/* clear all stack */
void clear(void) {
    sp = 0;
}

#include <ctype.h>

int getch(void);

void ungetch(int);

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
