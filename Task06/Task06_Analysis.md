# Task 06 – Control Structures

## Aim

To implement C++ control structures for metro smart-card fare calculation.

## Control Structures Used

1. **switch-case:** Selects the base fare according to the travel zone.
2. **if-else:** Checks peak-hour surcharge and minimum balance.
3. **for loop:** Processes multiple journeys.
4. **Functions:** `fare()` calculates the fare, and `canTravel()` checks travel eligibility.

## Fare Table

| Zone   | Base Fare |
| ------ | --------: |
| Inner  |    Rs. 10 |
| Middle |    Rs. 20 |
| Outer  |    Rs. 30 |

Peak-hour surcharge: 20%.

Minimum required balance after travel: Rs. 50.

## Algorithm

1. Initialize the balance to Rs. 100.
2. Process each journey.
3. Select the base fare using switch-case.
4. Add a 20% surcharge during peak hours.
5. Check whether the remaining balance is at least Rs. 50.
6. Deduct the fare if travel is permitted.
7. Otherwise, deny the journey.
8. Display the fare and remaining balance.

## Pseudocode

BEGIN

SET balance = 10000 paise

FOR each journey

```
SELECT base fare using SWITCH(zone)

IF peak hour
    ADD 20% surcharge
END IF

IF balance - fare >= 5000
    DEDUCT fare
    DISPLAY fare and balance
ELSE
    DISPLAY journey denied
END IF
```

END FOR

END

## Sample Output

```
Fare Rs. 10.00 | Balance Rs. 90.00
Fare Rs. 36.00 | Balance Rs. 54.00
Journey denied (low balance) | Balance Rs. 54.00
```

## Test Cases

| Test                             | Expected Result   |
| -------------------------------- | ----------------- |
| Inner zone, off-peak             | Fare Rs. 10       |
| Outer zone, peak                 | Fare Rs. 36       |
| Middle zone with Rs. 54 balance  | Journey denied    |
| Remaining balance exactly Rs. 50 | Journey permitted |

## Result

The program was compiled and executed successfully. It demonstrates switch-case, if-else, loops, functions, peak-hour fare calculation, and minimum-balance validation.

## Complexity Analysis

* Time Complexity: O(n), where n is the number of journeys.
* Auxiliary Space Complexity: O(1), excluding the journey array.
