#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100                   /* max size of operand or operator */

/* reverse Polish calculator */
main()
{
    int type, _last_read_variable = 0, i = 0;
    double op2, aux, _lp = 0.0;
    char s[MAXOP];
    double variables[26]; /* keeps track all variable values */

    /* init variables value */
    for (i = 0; i < 26; i++)
        variables[i] = FAKE_DOUBLE_MIN;

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
        case '\n':
            _lp = pop();
            printf("\t%.8g\n", _lp);
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

    return 0;
}
