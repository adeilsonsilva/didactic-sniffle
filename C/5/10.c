#include <stdio.h>
#include <stdlib.h>    /* for  atof() */
#include <math.h>      /* for  sin(), exp() and pow() */

#define MAXOP 100          /* max size of operand or operator */
#define NUMBER '0'         /* signal that a number was found */
#define LAST 'L'           /* signal that last value command was found */
#define SWAP '~'           /* signal that swap command was found */
#define DUPLICATE 'D'      /* signal that duplicate command was found */
#define CLEAR 'C'          /* signal that clear was found */

#define FAKE_DOUBLE_MIN -999999.0 /* set a minimum value for stack operands */

int getop(char [], char *);
void push(double);
double pop(void);
double last(void);
void swap(void);
void duplicate(void);
void clear(void);

/* reverse Polish calculator */
main(int argc, char *argv[])
{
    int type, _last_read_variable = 0, i = 0;
    double op2, aux, _lp = 0.0;
    char s[MAXOP];
    double variables[26]; /* keeps track all variable values */

    if (argc < 2)
        printf("Usage: %s <EXPRESSION>\n", argv[0]);
    else {
        /* init variables value */
        for (i = 0; i < 26; i++)
            variables[i] = FAKE_DOUBLE_MIN;

        while (--argc > 0 && (type = getop(s, *++argv)) != EOF) {

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
                _lp = last();
                printf("top value: %f\n", _lp);
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
            case '_':
                push(_lp);
                break;
            case '=':
                variables[_last_read_variable] = pop();
                break;
            case '?':
                /* print all variables that were set */
                for (i = 0; i < 26; i++) {
                    if (variables[i] != FAKE_DOUBLE_MIN)
                        printf("'%c' == %.8g\n", ('a' + i), variables[i]);
                }
                break;
            default:
                /* variable was found */
                if (type >= 'a' && type <= 'z') {
                    _last_read_variable = type - 'a';
                    /* if variable had a value assigned before, push it to stack */
                    if (variables[_last_read_variable] != FAKE_DOUBLE_MIN)  {
                        push(variables[_last_read_variable]);
                    } else {
                        /* if variable wasn't used before, initialize it to 0 */
                        variables[_last_read_variable] = 0.0;
                    }
                } else {
                    printf("error: unknown command %s\n", s);
                }

                break;
            }
        }

        _lp = pop();
        printf("\t%.8g\n", _lp);
    }

    return _lp;
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
#include <string.h>    /* for  strlen() */

/* getop:  get next character or numeric operand */
int getop(char s[], char *next)
{
    int i, c;

    while ((s[0] = c = *(next++)) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = *(next++)))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = *(next++)))
            ;
    s[i] = '\0';

    return NUMBER;
}

