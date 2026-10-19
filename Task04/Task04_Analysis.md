# Task 04: Type Conversions and Casting in C++

## 1. Aim

To study implicit type conversions, integer division, explicit type casting, character promotion, Boolean conversion, and signed-versus-unsigned comparisons in C++.

## 2. Concepts Studied

### 2.1 Implicit Type Conversion

Implicit conversion occurs automatically when a value is converted from one data type to another.

Example:

```cpp
int number = 5;
double value = number;
```

Here, the integer value is automatically converted to a double value.

### 2.2 Integer Division

When two integers are divided, the fractional part is discarded.

Example:

```cpp
int a = 7, b = 2;
double c = a / b;
```

The expression `a / b` evaluates to `3` because both operands are integers. The result is then converted to `3.0` when assigned to `c`.

### 2.3 Explicit Type Casting

Explicit casting converts a value to a specified data type.

Example:

```cpp
double d = static_cast<double>(a) / b;
```

Here, `a` is converted to `double` before division. Therefore, the result is `3.5`.

### 2.4 Character Promotion

A character can participate in arithmetic operations through integer promotion.

Example:

```cpp
char ch = 'A' + 2;
```

On the target system, this produces the character `C`. In `ch + 1`, the character is promoted to an integer, producing `68` on an ASCII-compatible system.

### 2.5 Boolean Conversion

In C++, zero converts to `false`, while a non-zero value converts to `true`.

Example:

```cpp
bool flag = 5;
```

The value of `flag` becomes `true`. By default, a Boolean value is printed as `1` or `0`. Using `std::boolalpha` prints `true` or `false`.

### 2.6 Signed and Unsigned Comparison

Signed and unsigned integers can behave unexpectedly when compared.

Example:

```cpp
unsigned int u = 1;
int s = -1;
```

In the comparison `s < u`, the signed value is converted to an unsigned value. On a system with 32-bit `unsigned int`, `-1` converts to `4294967295`.

Therefore, the comparison is false, and the program prints `s >= u`.

This comparison also produces a compiler warning because the operands have different signedness.

## 3. Algorithm

1. Start the program.
2. Declare two integer variables with values 7 and 2.
3. Perform integer division and assign the result to a double variable.
4. Convert an integer explicitly to double and perform floating-point division.
5. Display both division results.
6. Perform arithmetic using a character and display the results.
7. Convert a non-zero integer to Boolean and display it with and without `boolalpha`.
8. Compare a signed integer with an unsigned integer.
9. Display the comparison result.
10. Stop the program.

## 4. Pseudocode

```text
BEGIN
    DECLARE a = 7, b = 2
    COMPUTE c = a / b
    COMPUTE d = CAST a TO double / b
    DISPLAY c, d

    DECLARE ch = 'A' + 2
    DISPLAY ch, ch + 1

    DECLARE flag = 5 AS bool
    DISPLAY flag
    ENABLE boolalpha
    DISPLAY flag

    DECLARE u = 1 AS unsigned int
    DECLARE s = -1 AS int
    IF s < u THEN
        DISPLAY "s < u"
    ELSE
        DISPLAY "s >= u"
    END IF
END
```

## 5. Sample Output

```text
3 3.5
C 68
1 true
s >= u
```

## 6. Output Explanation

* `3 3.5`: Integer division produces 3, while explicit casting produces 3.5.
* `C 68`: Character arithmetic produces `C`; adding 1 to the character produces integer value 68 on the target system.
* `1 true`: The non-zero value 5 converts to true. The output format changes after enabling `boolalpha`.
* `s >= u`: The signed value -1 converts to a large unsigned value, making the comparison false.

## 7. Safe Conversion Practices

* Use `static_cast` when an explicit conversion is required.
* Avoid accidental integer division when fractional results are needed.
* Use consistent signedness when comparing integers.
* Use brace initialization where appropriate to detect narrowing conversions.
* Enable compiler warnings using `-Wall -Wextra` to identify potential problems.

## 8. Complexity Analysis

The program performs a fixed number of arithmetic operations, conversions, and comparisons.

* Time Complexity: O(1)
* Auxiliary Space Complexity: O(1)

## 9. Result

The program was compiled and executed successfully. The output demonstrated integer division, explicit casting, character promotion, Boolean conversion, and signed-versus-unsigned comparison. The compiler issued a signedness warning for the intentional comparison.
