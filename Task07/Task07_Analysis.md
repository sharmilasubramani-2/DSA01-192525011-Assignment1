Task 07 – Procedural Programming vs Object-Oriented Programming
Aim

To compare procedural and object-oriented programming approaches for a metro smart-card system.

1. Procedural Approach

The procedural approach organizes the program using functions. The calculateFare() function calculates the fare based on the travel zone and peak-hour status.

Advantages
Simple for small programs.
Functions can be reused.
Easy to understand for basic calculations.
Limitations
Data and functions are maintained separately.
Protecting and validating card balance requires additional care as the program grows.
2. Object-Oriented Approach

The object-oriented approach uses a SmartCard class to combine balance data and related operations.

The class contains:

Private balance data.
canTravel() to check the minimum-balance rule.
deductFare() to deduct an approved fare.
getBalance() to retrieve the current balance.
3. Comparison
Feature	Procedural	Object-Oriented
Main structure	Functions	Classes and objects
Data handling	Separate variables	Encapsulated private data
Reusability	Function-based	Class and object-based
Balance validation	Must be implemented separately	Included in SmartCard
Suitability	Small calculations	Larger smart-card systems
4. Fare Rules
Zone	Base Fare
Inner	Rs. 10
Middle	Rs. 20
Outer	Rs. 30

Peak-hour surcharge: 20%.

Minimum balance after travel: Rs. 50.

5. Algorithm
Calculate a fare using the procedural function.
Create a SmartCard object with Rs. 100.
Calculate the Inner Zone fare.
Check travel eligibility.
Deduct the fare when permitted.
Attempt an expensive journey.
Display the final balance.
6. Sample Output
PROCEDURAL APPROACH
Outer peak fare: Rs. 36

OBJECT-ORIENTED APPROACH
Journey approved
Fare: Rs. 10
Remaining balance: Rs. 90
Second journey denied
Final balance: Rs. 90
Result

Both approaches calculate metro fares. The object-oriented approach combines card balance and validation operations in a class, helping maintain the minimum-balance rule.

Complexity Analysis
Fare calculation: O(1).
Balance validation and deduction: O(1).
Auxiliary space per card: O(1).