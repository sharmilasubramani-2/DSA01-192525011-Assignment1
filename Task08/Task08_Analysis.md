Task 08 – Safe Input and Output
Aim

To implement input validation and formatted output for a metro smart-card system.

1. Input Validation

The program validates the zone, hour, and balance before calculating the fare.

Zone must be between 1 and 3.
Hour must be between 0 and 23.
Balance must not be negative.
Invalid input is rejected before fare processing.
2. Fare Rules
Zone	Base Fare
Inner	Rs. 10
Middle	Rs. 20
Outer	Rs. 30

Peak hours: 8:00–9:59 AM and 5:00–7:59 PM.

Peak surcharge: 20%.

Minimum balance required after travel: Rs. 50.

3. Formatted Output

The program uses fixed and setprecision(2) to display monetary values with two decimal places.

Fare and balance calculations use integer paise to avoid floating-point rounding errors.

4. Algorithm
Read and validate the zone.
Read and validate the hour.
Read and validate the balance.
Determine the base fare.
Check whether the journey is during peak hours.
Apply the surcharge when required.
Verify the minimum-balance condition.
Deduct the fare if travel is permitted.
Display the fare and remaining balance.
5. Sample Input
1
9
100
6. Expected Output
Peak hour: Yes
Fare: Rs. 12.00
Journey approved
Remaining balance: Rs. 88.00
7. Test Cases
Test	Expected Result
Inner zone, hour 9, balance Rs. 100	Journey approved; fare Rs. 12
Outer zone, hour 12, balance Rs. 100	Journey approved; fare Rs. 30
Invalid zone 9	Invalid zone input
Invalid hour 25	Invalid hour input
Negative balance	Invalid balance input
Remaining balance would be below Rs. 50	Journey denied
Result

The program was compiled and executed successfully. It validates user input, calculates peak-hour fares, enforces the minimum-balance rule, and displays monetary values to two decimal places.

Complexity Analysis
Time Complexity: O(1).
Auxiliary Space Complexity: O(1).