Task 11 – Final Design Recommendation
Aim

To recommend a safe, maintainable, and scalable design for the Metro Smart-Card System.

1. Recommended Data Types
enum class: Represents metro zones safely.
long long: Stores fare values in paise and supports large totals.
bool: Represents journey approval and peak-hour status.
constexpr: Defines compile-time constants such as the minimum balance.
2. Object-Oriented Design

The SmartCard class stores the balance privately and provides methods to check travel eligibility and deduct fares.

The calculateFare() function calculates the fare based on the selected zone and peak-hour status.

3. Fare Rules
Zone	Base Fare
Inner	Rs. 10
Middle	Rs. 20
Outer	Rs. 30

Peak-hour surcharge: 20%.

Minimum remaining balance after a journey: Rs. 50.

4. Design Recommendations
Store monetary values as integer paise to avoid common floating-point rounding errors.
Keep the card balance private to prevent uncontrolled modifications.
Use enum class instead of unrestricted integer zone values.
Validate zone selections, balances, and other user inputs.
Keep fare calculations separate from card balance management.
Use a configuration file or database for fare changes in a larger deployed system.
5. Limitations
The current program demonstrates a simplified metro system.
Passenger and journey records are not stored persistently.
Student and senior concessions are not implemented because their discount rates are unspecified.
Airport fares, weekend discounts, and monthly passes are not included in this version.
Production deployment would require additional validation, transaction handling, and persistent storage.
6. Algorithm
Initialize the smart card with a balance.
Select a metro zone.
Calculate the base fare.
Apply the peak-hour surcharge when applicable.
Check whether the remaining balance will be at least Rs. 50.
Deduct the fare if the journey is approved.
Display the fare and remaining balance.
Result

The program demonstrates a modular, object-oriented design using private card balance, scoped zone values, integer monetary calculations, and a minimum-balance validation rule.

Complexity Analysis
Fare calculation: O(1).
Journey approval and fare deduction: O(1).
Auxiliary space: O(1).