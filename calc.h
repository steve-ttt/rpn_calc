#ifndef CALC_H
#define CALC_H

#define NUMBER '0'      /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */


#endif





int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);