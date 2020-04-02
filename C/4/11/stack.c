#include "calc.h"

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
