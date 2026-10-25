# Task 09 – Fare Logic and Testing

## Aim

To test metro fare calculation, peak-hour boundaries, and minimum-balance validation.

## Fare Rules

| Zone   | Base Fare |
| ------ | --------: |
| Inner  |    Rs. 10 |
| Middle |    Rs. 20 |
| Outer  |    Rs. 30 |

Peak surcharge: 20%.

Peak hours: 8:00–9:59 AM and 5:00–7:59 PM.

Minimum remaining balance: Rs. 50.

## Testing Strategy

The program tests every zone, peak and off-peak journeys, peak-hour boundary values, and the minimum-balance condition.

## Test Cases

| Test | Input         | Expected Fare |
| ---- | ------------- | ------------: |
| 1    | Inner, 12:00  |        Rs. 10 |
| 2    | Middle, 12:00 |        Rs. 20 |
| 3    | Outer, 12:00  |        Rs. 30 |
| 4    | Inner, 8:00   |        Rs. 12 |
| 5    | Inner, 10:00  |        Rs. 10 |
| 6    | Inner, 17:00  |        Rs. 12 |
| 7    | Inner, 20:00  |        Rs. 10 |
| 8    | Outer, 18:00  |        Rs. 36 |

## Minimum-Balance Tests

| Initial Balance |   Fare | Remaining Balance | Expected Result |
| --------------- | -----: | ----------------: | --------------- |
| Rs. 60          | Rs. 10 |            Rs. 50 | Approved        |
| Rs. 59          | Rs. 10 |            Rs. 49 | Denied          |

## Algorithm

1. Select the base fare based on the zone.
2. Determine whether the hour is within peak hours.
3. Apply a 20% surcharge when required.
4. Check whether the balance after travel is at least Rs. 50.
5. Display the fare and test result.

## Result

The program tests base fares, peak-hour boundaries, and minimum-balance conditions. Successful fare checks display PASS.

## Complexity Analysis

* Fare calculation: O(1).
* Each test case: O(1).
* Total time complexity: O(t), where t is the number of test cases.
* Auxiliary space complexity: O(1).
