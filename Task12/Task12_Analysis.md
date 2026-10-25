Task 12 – Advanced Metro Smart-Card System
Aim

To extend the metro fare system with an Airport zone, weekend discounts, and a monthly pass covering two selected zones.

1. New Requirements
Airport zone base fare: Rs. 60.
Weekend discount: 10%.
Weekend discount and peak-hour surcharge must not be combined.
Monthly pass permits unlimited journeys in two selected zones.
The existing minimum-balance rule applies to journeys charged to the card.
2. Updated Fare Table
Zone	Base Fare
Inner	Rs. 10
Middle	Rs. 20
Outer	Rs. 30
Airport	Rs. 60
3. Fare Calculation Rules
Determine the base fare using the selected zone.
If it is a weekend, apply a 10% discount.
Otherwise, if it is peak hour, apply a 20% surcharge.
Do not combine the weekend discount and peak surcharge.
Check whether the card can pay the fare while retaining the required minimum balance.
Example Calculations
Airport regular fare: Rs. 60.
Airport peak fare: Rs. 72.
Airport weekend fare: Rs. 54.
4. Monthly Pass

The smart card stores two selected pass zones.

If a journey belongs to either covered zone, the fare is not deducted. Journeys outside those zones use the normal fare calculation and balance validation.

5. Design Changes
Added Airport to the Zone enumeration.
Updated the fare calculation switch statement.
Added weekend discount logic.
Added monthly pass status and two covered zones to SmartCard.
Added a method to check whether a zone is covered by the pass.
6. Test Cases
Test	Input	Expected Result
Inner regular	Inner, off-peak weekday	Rs. 10
Outer peak	Outer, peak weekday	Rs. 36
Airport regular	Airport, off-peak weekday	Rs. 60
Airport peak	Airport, peak weekday	Rs. 72
Airport weekend	Airport, weekend	Rs. 54
Pass-covered journey	Inner zone, pass covers Inner	No fare deducted
Pass-covered journey	Middle zone, pass covers Middle	No fare deducted
Outside pass zones	Outer zone, pass covers Inner and Middle	Normal fare rules apply
7. Limitations
The example uses a predefined card and pass configuration.
Monthly pass validity dates, renewal, and expiry are not implemented.
Persistent storage and transaction records are not implemented.
Student and senior concessions are not implemented because their discount rates were not specified.
The example demonstrates the rules but is not a complete production ticketing system.
Result

The program demonstrates the extended metro fare system with the Airport zone, weekend discounts that do not combine with peak surcharges, and a monthly pass covering two selected zones.

Complexity Analysis
Fare calculation: O(1).
Monthly pass zone check: O(1).
Journey approval and fare deduction: O(1).
Auxiliary space: O(1).