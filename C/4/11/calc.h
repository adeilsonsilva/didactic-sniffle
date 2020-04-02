#include <math.h>
#include <stdio.h>

#define NUMBER '0'         /* signal that a number was found */
#define LAST 'L'           /* signal that last value command was found */
#define SWAP '~'           /* signal that swap command was found */
#define DUPLICATE 'D'      /* signal that duplicate command was found */
#define CLEAR 'C'          /* signal that clear was found */

#define FAKE_DOUBLE_MIN -999999.0 /* set a minimum value for stack operands */

int getop(char []);

void push(double);
double pop(void);
double last(void);
void swap(void);
void duplicate(void);
void clear(void);

int getch(void);
void ungetch(int);
