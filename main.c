#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>
#include "calc.h"

#define MAXOP 100       /* max size of operand or operator */

/* reverse Polish calculator */
int main() {
    int type;
    double op2, op1; // Store the first operand
    char s[MAXOP];
    extern int sp;

    printf("Simple RPN Calculator\n \
            Commands:\n \
            \t p \t power ( 2 8 p => 16)\n \
            \t s \t sin \n \
            \t c \t cos \n \
            \t t \t tan \n \
            \t S \t arc sin (in radians)\n \
            \t C \t arc cos (in radians)\n \
            \t T \t arc tan (in radians)\n \
            \t l \t log10(x) \n \
            \t + \t add \n \
            \t - \t subtract \n \
            \t * \t multiply \n \
            \t / \t divide \n \
            \t %% \t modulo \n \
            \t q \t quit \n \
            \t Enter \t calculate \n \
            ");

    printf("Enter an RPN expression: \n");
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                op2 = pop();
                op1 = pop(); // Get the first operand
                while (sp > 0) { // Keep popping and adding until the stack is empty
                    op1 += pop();
                }
                push(op1 + op2); // Add the last operand
                break;
            case '*':
                op2 = pop();
                op1 = pop(); // Get the first operand
                while (sp > 0) { // Keep popping and multiplying until the stack is empty
                    op1 *= pop();
                }
                push(op1 * op2); // Multiply the last operand
                break;
            case '-':
                op2 = pop();
                op1 = pop(); // Get the first operand
                while (sp > 0) { // Keep popping and subtracting until the stack is empty
                    op1 -= pop();
                }
                push(op1 - op2); // Subtract the last operand
                break;
            case '%':
                op2 = pop();
                op1 = pop(); // Get the first operand
                while (sp > 0) { // Keep popping and calculating modulo until the stack is empty
                    op1 = (int)op1 % (int)pop();
                }
                if (op2 != 0.0)
                    push((int)op1 % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '/':
                op2 = pop();
                op1 = pop(); // Get the first operand
                while (sp > 0) { // Keep popping and dividing until the stack is empty
                    op1 /= pop();
                }
                if (op2 != 0.0)
                    push(op1 / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 's': // sin
                push(sin(pop()));
                break;
            case 'c': // cos
                push(cos(pop()));
                break;
            case 't': // tan
                push(tan(pop()));
                break;
            case 'S': // arc sin
                push(asin(pop()));
                break;
            case 'C': // arc cos
                push(acos(pop()));
                break;
            case 'T': // arc tan
                push(atan(pop()));
                break;                
            case 'p': // pow
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'l': // log10(x)
                op1 = pop(); // Get the operand
                if (op1 > 0.0) { // Check if it's positive
                    push(log10(op1));
                } else {
                    printf("error: log10() requires a positive argument\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'q': // Quit
                printf("Exiting...\n");
                exit(0); // Use exit(0) to terminate the program
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
