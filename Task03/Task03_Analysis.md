# Task 03: Data Types and Type Selection

## 1. Aim

To study C++ data types, memory sizes, numeric limits, floating-point precision, and the selection of appropriate data types for the City Metro Smart-Card System.

## 2. Data Types Used

| Data Type      | Example                                    | Purpose in the Metro System                                                           |
| -------------- | ------------------------------------------ | ------------------------------------------------------------------------------------- |
| `bool`         | `bool peakHour = true;`                    | Represents whether a journey occurs during peak hours                                 |
| `char`         | `char zoneCode = 'O';`                     | Stores a single zone character                                                        |
| `int`          | `int innerFarePaise = 1000;`               | Stores a small fare value in paise                                                    |
| `long long`    | `long long dailyTransactions = 3000000LL;` | Represents large transaction counts or monetary totals                                |
| `unsigned int` | `unsigned int passengerCount = 500000U;`   | Represents a non-negative count within its supported range                            |
| `float`        | `float approximateFare = 36.5F;`           | Represents approximate floating-point values                                          |
| `double`       | `double measuredFare = 36.50;`             | Represents floating-point values with greater precision than `float` on this platform |
| `auto`         | `auto outerFarePaise = 3000;`              | Deduces the variable type from its initializer                                        |

The `auto` keyword does not introduce a separate numeric data type. In this example, the initializer `3000` has type `int`, so `outerFarePaise` is deduced as `int`.

## 3. Memory Size of Data Types

The program uses the `sizeof` operator to display the size of each data type.

### Observed Output

| Data Type      | Observed Size |
| -------------- | ------------: |
| `bool`         |        1 byte |
| `char`         |        1 byte |
| `int`          |       4 bytes |
| `long long`    |       8 bytes |
| `unsigned int` |       4 bytes |
| `float`        |       4 bytes |
| `double`       |       8 bytes |

These are the sizes observed on the compiler and platform used for this experiment. C++ does not require every platform to use these exact sizes for all these types. The `sizeof` operator reports the size for the current implementation.

## 4. Numeric Limits

The program uses `<climits>` to display the minimum and maximum values of selected integer types.

| Constant    |       Observed Value |
| ----------- | -------------------: |
| `INT_MIN`   |          -2147483648 |
| `INT_MAX`   |           2147483647 |
| `LLONG_MIN` | -9223372036854775808 |
| `LLONG_MAX` |  9223372036854775807 |
| `UINT_MAX`  |           4294967295 |

### Is `int` sufficient for 3 million transactions?

A signed 32-bit `int` can represent 3,000,000 because its maximum value is 2,147,483,647 on the tested platform.

However, the total value collected across a metro network can become much larger than the number of transactions. The maximum transaction count and total collection must be estimated before choosing the type.

For larger totals, `long long` provides a wider range on this platform. The program should also check for overflow when performing arithmetic with very large values.

## 5. Floating-Point Precision

The program uses `std::numeric_limits` to display the decimal precision associated with the floating-point types.

| Type     | Observed `digits10` |
| -------- | ------------------: |
| `float`  |                   6 |
| `double` |                  15 |

`float` generally provides less precision than `double`. Floating-point numbers use a binary representation, so some decimal fractions cannot be represented exactly.

This can lead to small rounding differences in financial calculations if floating-point values are used carelessly.

## 6. Representing Money in Paise

The program represents a fare of Rs. 36.50 as 3650 paise.

```cpp
long long farePaise = 3650;
```

The fare is displayed using integer division and the remainder operator:

```cpp
cout << "Fare: Rs. "
     << farePaise / 100 << "."
     << (farePaise % 100 < 10 ? "0" : "")
     << farePaise % 100 << '\n';
```

Integer paise representation avoids binary floating-point rounding issues when storing amounts that have whole-paise precision.

For the metro system, integer paise is preferable to storing money directly in `float` or `double`. However, the program must still prevent integer overflow and apply a clearly defined rounding policy when a fare calculation produces fractions of a paise.

## 7. Choosing Between `int`, `long long`, and `double`

| Type        | Advantages                                                | Limitations                                        | Recommended Use                                                     |
| ----------- | --------------------------------------------------------- | -------------------------------------------------- | ------------------------------------------------------------------- |
| `int`       | Efficient and sufficient for many ordinary integer values | Limited range compared with `long long`            | Small counters and individual fare values when their range is known |
| `long long` | Supports a wider range of integer values                  | Can still overflow                                 | Large transaction totals and monetary amounts stored in paise       |
| `double`    | Supports fractional values and a wide range               | Some decimal fractions are not represented exactly | Measurements and calculations that require floating-point values    |

The choice of type must be based on the required range, precision, and operations.

## 8. Program Logic

1. Declare variables using different C++ data types.
2. Initialize variables with representative metro-system values.
3. Display the variable values.
4. Use `sizeof` to display data type sizes.
5. Use `<climits>` to display integer limits.
6. Use `std::numeric_limits` to examine floating-point precision.
7. Represent Rs. 36.50 as 3650 paise.
8. Display the amount in rupees and paise using integer arithmetic.

## 9. Sample Output

```text
Peak hour: true
Zone code: O
Inner fare (paise): 1000
Daily transactions: 3000000
Passenger count: 500000
Approximate fare: 36.5
Measured fare: 36.5
Auto-deduced fare: 3000

--- Data Type Sizes ---
sizeof(bool): 1 byte(s)
sizeof(char): 1 byte(s)
sizeof(int): 4 byte(s)
sizeof(long long): 8 byte(s)
sizeof(unsigned int): 4 byte(s)
sizeof(float): 4 byte(s)
sizeof(double): 8 byte(s)

--- Numeric Limits ---
INT_MIN: -2147483648
INT_MAX: 2147483647
LLONG_MIN: -9223372036854775808
LLONG_MAX: 9223372036854775807
UINT_MAX: 4294967295

--- Floating-Point Precision ---
float precision digits: 6
double precision digits: 15

--- Money Representation ---
Fare: Rs. 36.50
```

## 10. Complexity Analysis

The program perfor
