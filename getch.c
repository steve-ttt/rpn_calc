#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100
int bufp = 0;       /* next free position in buf */
char buf[BUFSIZE];  /* buffer for ungetch */

int getch(void) /* get a (possibly pushed−back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}