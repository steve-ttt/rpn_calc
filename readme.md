# Reverse Polish Notation (RPN) Calculator

This C program implements a simple Reverse Polish Notation (RPN) calculator for the command line.. RPN is a mathematical notation where operators follow their operands. For example, the expression "2 + 3" would be written as "2 3 +" in RPN.

## Features

* **Basic arithmetic operations:**
    * Addition (+)
    * Subtraction (-)
    * Multiplication (*)
    * Division (/)
    * Modulo (%)
* **Trigonometric functions:**
    * Sine (s)
    * Cosine (c)
    * Tangent (t)
* **Other function:**
    * Power (n, p)
    * Log10 (x)
* **Input and output:**
    * Takes RPN expressions as input.
    * Displays the calculated result.
* **Error handling:**
    * Detects and handles division by zero errors.
    * Detects and handles stack overflow and underflow errors.

## Usage

1. Download via git: `git clone `
2. Compile the program: `make`
3. Run the program: `./rpn_calc`
4. Enter an RPN expression, separating operands and operators with spaces.
5. Press Enter to calculate the result.
6. To quit the program, enter 'q' and press Enter.

## Example
Enter an RPN expression: 2 3 + 5 *

                                25
                                
nb. The equivelent in algebraic notation would be; (2 + 3 ) * 5 = 25                            
* also supports more than two operands ie: 1 2 3 4 5 + => 15 the same as [1 + 2 + 3 + 4 + 5 = 15]
## How it Works

The program uses a stack to store operands and intermediate results. It reads input characters one by one and performs the following actions:

* **Numbers:** Pushes the number onto the stack.
* **Operators:** Pops the required number of operands from the stack, performs the operation, and pushes the result back onto the stack.
* **Enter key:** Pops the top value from the stack and displays it as the result.

## Code Structure

The code is organized into the following functions:

* **`main()`:** The main function that controls the program flow.
* **`getop()`:** Reads the next character or numeric operand from the input.
* **`push()`:** Pushes a value onto the stack.
* **`pop()`:** Pops a value from the stack.

## Notes

* The program uses the `atof()` function from the `stdlib.h` library to convert strings to floating-point numbers.
* The `math.h` library is included for trigonometric and power functions.
* The `getch()` and `ungetch()` functions are used for input buffering.

## License

This code is released under the MIT License.
