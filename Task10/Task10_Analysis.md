Task 10 – Data Types, Fare Precision and Performance
Aim

To analyse numeric data types, monetary precision, and fare collection totals for different metro journey volumes.

1. Data Types
int: Suitable for ordinary counters within its range.
long long: Suitable for large journey counts and total fare values in paise.
double: Supports fractional values but may introduce floating-point representation errors.
constexpr: Defines compile-time constants where applicable.
2. Integer Paise

The system stores fares in paise instead of rupees as floating-point values.

For example:

Rs. 30 = 3000 paise.
3 journeys at Rs. 30 = 9000 paise = Rs. 90.

Integer arithmetic avoids common floating-point rounding issues when representing monetary amounts.

3. Fare Collection Analysis
Journeys	Fare per Journey	Total Collection
20,000	Rs. 30	Rs. 6,00,000
500,000	Rs. 30	Rs. 1,50,00,000
3,000,000	Rs. 30	Rs. 9,00,00,000

Total collection is calculated by multiplying the number of journeys by the fare in paise.

4. Type Selection
Requirement	Suggested Type	Reason
Zone number	int or enum	Small set of values
Journey count	long long	Supports large counts
Fare in paise	long long	Exact integer arithmetic
Display in rupees	double for formatting	Convenient decimal display

An int can store a count of three million on common platforms, but the total fare should be calculated using a sufficiently wide integer type.

5. Algorithm
Define the fare in paise.
Store the journey counts.
Calculate the total fare for each count.
Display the totals in rupees.
Display the numeric limits of int and long long.
Compare integer monetary arithmetic with floating-point arithmetic.
Result

The program calculates total fare collections for 20,000, 500,000, and 3,000,000 journeys. It demonstrates the use of integer paise and wider integer types for monetary totals.

Complexity Analysis
Time Complexity: O(n), where n is the number of journey-volume cases.
Auxiliary Space Complexity: O(1), excluding the fixed-size journey array.