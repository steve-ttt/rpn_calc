#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') // Check for '-' as well
        return c;    /* not a number */
    i = 0;
    
    
    if (c == '-') { // Handle negative sign
        c = getch(); // Get the next character
        if (!isdigit(c) && c != '.') { // If it's not a digit or '.', it's not a number
            ungetch(c); // Put the character back
            return '-'; // Return '-' as the operator
        } else {
            s[++i] = c;
            while(isdigit(s[++i] = c = getch()))
                ;
            printf("debug: %s", s);
        }
    }
    

    if (isdigit(c))  /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')  /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
  
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}