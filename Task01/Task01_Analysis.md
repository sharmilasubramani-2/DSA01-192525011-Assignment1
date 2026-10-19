# Task 01: Object-Oriented Design Analysis

## 1. Problem Statement

The objective is to design an object-oriented model for a City Metro Smart-Card System. The system calculates metro fares based on the travel zone and peak-hour conditions. It checks whether a smart card has sufficient balance to complete a journey while maintaining a minimum remaining balance of Rs. 50.

The system should represent important entities as objects, protect the card balance from unauthorized modification, and separate fare calculation from balance management.

## 2. Identification of Objects

The following objects and classes are identified for the metro smart-card system.

| Object/Class   | Data Members                             | Member Functions / Responsibilities                                                   |
| -------------- | ---------------------------------------- | ------------------------------------------------------------------------------------- |
| SmartCard      | Balance in paise                         | `getBalance()`, `canTravel()`, `deductFare()`                                         |
| FareCalculator | Fare calculation rules                   | `calculateFare()`                                                                     |
| Trip           | Zone, peak-hour status, trip name        | Stores the details of an individual journey                                           |
| Zone           | Inner, Middle, Outer                     | Represents the zone in which the passenger travels                                    |
| Passenger      | Passenger details and passenger category | Can represent a passenger and their eligibility for concessions in an extended design |
| FareTable      | Base fares for different zones           | Stores and provides the applicable base fare                                          |

The current C++ implementation directly implements `SmartCard`, `FareCalculator`, `Trip`, and `Zone`. `Passenger` and `FareTable` are conceptual components that could be added to a more complete system.

## 3. Object-Oriented Programming Principles

### 3.1 Encapsulation

Encapsulation combines data and the operations performed on that data within a class.

In the `SmartCard` class, `balancePaise` is declared private. It cannot be modified directly from outside the class. The balance is accessed through `getBalance()` and updated through `deductFare()`.

This protects the card balance from unauthorized changes and helps maintain the minimum-balance rule.

### 3.2 Abstraction

Abstraction exposes essential operations while hiding implementation details.

The `FareCalculator` class provides the `calculateFare()` function. The main program can request a fare without repeating the zone-based calculation and peak-surcharge logic.

Similarly, the `SmartCard` class provides `deductFare()` without requiring the caller to manage the internal balance calculation.

### 3.3 Inheritance

Inheritance allows a derived class to reuse or extend the functionality of a base class.

The current implementation does not require inheritance because it supports a small set of basic entities. In a future version, passenger categories or fare policies could be represented using a suitable base class and derived classes, if their behaviour differs.

### 3.4 Polymorphism

Polymorphism allows the same interface to represent different behaviours.

The current implementation does not use runtime polymorphism. If the system later supports different fare policies, such as standard fares and concession fares, a common fare-policy interface could allow different implementations to calculate fares through the same interface.

Inheritance and polymorphism are possible extensions rather than requirements for the current implementation.

## 4. Procedural Programming vs Object-Oriented Programming

| Feature              | Procedural Approach                               | Object-Oriented Approach                                          |
| -------------------- | ------------------------------------------------- | ----------------------------------------------------------------- |
| Program organization | Functions and sequential steps                    | Classes and objects                                               |
| Data management      | Data may be shared across functions               | Data can be encapsulated within classes                           |
| Balance protection   | Requires manual checks and controlled access      | Private data and public member functions help protect the balance |
| Fare calculation     | Implemented using separate functions              | Encapsulated in `FareCalculator`                                  |
| Reusability          | Functions can be reused                           | Classes and their public interfaces can be reused                 |
| Maintenance          | Changes may affect several functions sharing data | Responsibilities are separated into classes                       |
| Suitability          | Suitable for small, simple programs               | Suitable for systems with multiple related entities and rules     |

### Procedural Alternative

A procedural version could use a global balance variable and separate functions such as `calculateFare()`, `canTravel()`, and `deductFare()`.

However, if multiple functions modify the global balance, maintaining the minimum-balance rule becomes more difficult. An object-oriented design keeps the balance and its related operations together in the `SmartCard` class.

## 5. System Invariants

An invariant is a condition that must remain true throughout the system's operation.

The important invariants are:

1. The smart-card balance must not become negative.
2. A journey can be completed only when the remaining balance is at least Rs. 50.
3. A denied journey must not reduce the card balance.
4. The fare must not be negative.
5. The base fares are Rs. 10 for Inner Zone, Rs. 20 for Middle Zone, and Rs. 30 for Outer Zone.
6. A peak-hour journey incurs a 20% surcharge on the base fare.
7. Money is represented in paise using integer arithmetic to avoid floating-point rounding errors.

The `canTravel()` function checks whether the fare can be deducted while preserving the minimum balance. The `deductFare()` function updates the balance only when this check succeeds.

## 6. Fare Calculation Logic

The base fare is selected according to the travel zone.

| Zone   | Base Fare | Peak Surcharge | Peak Fare |
| ------ | --------: | -------------: | --------: |
| Inner  | Rs. 10.00 |       Rs. 2.00 | Rs. 12.00 |
| Middle | Rs. 20.00 |       Rs. 4.00 | Rs. 24.00 |
| Outer  | Rs. 30.00 |       Rs. 6.00 | Rs. 36.00 |

The peak surcharge is calculated as:

Peak Surcharge = Base Fare × 20 / 100

Final Fare = Base Fare + Peak Surcharge

All calculations are performed in paise using integer arithmetic.

## 7. Pseudocode

```text
BEGIN

    CREATE SmartCard with initial balance of Rs. 100

    DEFINE trips:
        Inner Zone, off-peak
        Outer Zone, peak
        Middle Zone, off-peak

    FOR each trip in trips

        CALCULATE fare using zone and peak status

        IF balance after deducting fare is at least Rs. 50 THEN
            DEDUCT fare from smart-card balance
            DISPLAY fare
        ELSE
            DISPLAY journey denied
        END IF

        DISPLAY current balance

    END FOR

END
```

## 8. UML Class Diagram

```text
+---------------------------+
|         SmartCard         |
+---------------------------+
| - balancePaise: long long |
+---------------------------+
| + getBalance(): long long |
| + canTravel(fare): bool   |
| + deductFare(fare): bool  |
+---------------------------+

+--------------------------------+
|         FareCalculator         |
+--------------------------------+
| + calculateFare(zone, peak)    |
|   : long long                  |
+--------------------------------+

+--------------------------+
|           Trip           |
+--------------------------+
| zone: Zone               |
| peak: bool               |
| name: string             |
+--------------------------+

+--------------------------+
|           Zone           |
+--------------------------+
| Inner                    |
| Middle                   |
| Outer                    |
+--------------------------+
```

## 9. Complexity Analysis

Let `n` be the number of journeys processed.

### Time Complexity

* Fare calculation: O(1), because the zone selection uses a switch statement and the surcharge uses a fixed number of arithmetic operations.
* Balance validation: O(1), because it checks a fixed number of conditions.
* Fare deduction: O(1), because it performs a fixed number of operations.
* Processing `n` journeys: O(n), because each journey is processed once.

Therefore, the time complexity for processing all journeys is **O(n)**, while the processing time for an individual journey is **O(1)**.

### Space Complexity

The program stores a fixed number of variables and a fixed-size array containing three sample trips.

For the current implementation, auxiliary space is **O(1)**. If the program stores `n` journeys in an array, the storage required for that journey array is **O(n)**.

## 10. Limitations and Future Improvements

1. The current implementation supports only Inner, Middle, and Outer zones.
2. Student and senior-citizen concessions are not implemented because the concession amount and eligibility rules need to be specified.
3. The current program uses a simple sample trip list rather than accepting user input.
4. Invalid zone values are not explicitly handled.
5. The program does not yet implement recharge operations, journey history, monthly passes, or weekend discounts.
6. Future versions can introduce a passenger class, a configurable fare table, input validation, and separate fare policies.

## 11. Result

The City Metro Smart-Card System was modelled using object-oriented principles in C++. The implementation separates fare calculation from smart-card balance management, encapsulates the card balance, applies the peak-hour surcharge, and prevents a journey when the remaining balance would fall below Rs. 50. The program compiled and executed successfully using the C++17 compiler.

