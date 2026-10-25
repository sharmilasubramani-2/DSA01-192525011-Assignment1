# Task 05 – Operators and Expressions

## Aim

To study C++ operators, operator precedence, increment operators, ternary operator, integer division, remainder operator, loops, and metro fare calculation.

## 1. Arithmetic Operators

Arithmetic operators include `+`, `-`, `*`, `/`, and `%`.

* `10 / 3` produces `3` because both operands are integers.
* `10 % 3` produces `1`, the remainder.

## 2. Operator Precedence

Multiplication is evaluated before addition.

* `5 + 3 * 2 = 11`
* `(5 + 3) * 2 = 16`

Parentheses change the evaluation order.

## 3. Increment Operators

* `x++` uses the current value and then increments it.
* `++y` increments the value before using it.

## 4. Ternary Operator

The ternary operator selects one of two expressions:

`condition ? value_if_true : value_if_false`

It is used to select the maximum of two numbers and display whether a journey occurs during peak hours.

## 5. Integer Division and Remainder

* `10 / 3 = 3`
* `10 % 3 = 1`
* `-10 / 3 = -3`
* `-10 % 3 = -1`

C++ integer division truncates towards zero.

## 6. Loop

The loop adds `0`, `3`, `6`, and `9`.

Total: `18`

## 7. Metro Peak-Hour Fare

Peak hours are 8:00–9:59 AM and 5:00–7:59 PM.

The base fare for the Outer Zone is Rs. 30.00. A 20% peak surcharge adds Rs. 6.00, resulting in a fare of Rs. 36.00.

## Algorithm

1. Declare integer variables.
2. Evaluate arithmetic expressions and operator precedence.
3. Demonstrate post-increment and pre-increment.
4. Evaluate the ternary and remainder operators.
5. Execute a loop and calculate its sum.
6. Check whether the journey time falls within peak hours.
7. Calculate and display the final fare.

## Sample Output

```
11 16
9 6 4
6 4
3 1 -3 -1
18
Peak hour: Yes
Final fare: Rs.36.00
```

## Result

The program was compiled and executed successfully. The output demonstrates operator precedence, increment operators, ternary expressions, integer division, remainder operations, loop execution, and peak-hour fare calculation.

## Complexity Analysis

* Time Complexity: O(1) for the fixed operations and fixed loop.
* Auxiliary Space Complexity: O(1).
