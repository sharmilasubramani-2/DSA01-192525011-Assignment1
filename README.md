# Metro Smart-Card System — DSA 0111 Assignment 1

**Student Name:** Sharmila Subramani
**Register Number:** 192525011
**Project:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System
**Language:** C++
**Standard:** C++17
**Compiler:** GCC (g++)

## Project Overview

This assignment implements and analyses a metro smart-card fare system using C++. It covers object-oriented programming, data types, type conversions, operators, control structures, input validation, fare testing, precision, and system design.

The advanced implementation also considers an Airport zone, weekend discounts, and monthly passes.

## Repository Structure

Each task has its own folder containing the C++ source code and analysis document.

* `Task01/` — Object-oriented design analysis
* `Task02/` — C++ tokens and constants
* `Task03/` — Data types and numeric limits
* `Task04/` — Type conversions
* `Task05/` — Operators and expressions
* `Task06/` — Control structures
* `Task07/` — Procedural programming versus OOP
* `Task08/` — Safe input and output
* `Task09/` — Fare logic testing
* `Task10/` — Fare precision and performance
* `Task11/` — Final design recommendations
* `Task12/` — Advanced metro fare system

Each task includes its source file and corresponding analysis document.

## Fare Rules

| Zone    | Base Fare |
| ------- | --------: |
| Inner   |       ₹10 |
| Middle  |       ₹20 |
| Outer   |       ₹30 |
| Airport |       ₹60 |

* Peak-hour surcharge: 20%.
* Peak periods: 8:00–10:00 AM and 5:00–8:00 PM.
* Minimum required remaining card balance after a regular journey: ₹50.
* Advanced task: 10% weekend discount, not combined with the peak surcharge.
* Advanced task: Monthly pass covers two selected zones.

## Requirements

* A C++ compiler supporting C++17.
* GCC (`g++`) and a terminal.
* Visual Studio Code is recommended.

## Compile and Run

Open the terminal in the repository root.

Example for Task01:

```powershell
g++ -std=c++17 -Wall -Wextra Task01/Task01.cpp -o Task01/Task01.exe
.\Task01\Task01.exe
```

Replace `Task01` with the required task number to compile and run another task.

For example, Task12:

```powershell
g++ -std=c++17 -Wall -Wextra Task12/Task12.cpp -o Task12/Task12.exe
.\Task12\Task12.exe
```

## Testing

Task09 contains fare-logic tests covering:

* Inner, Middle, and Outer zone fares.
* Peak-hour boundary conditions.
* Peak surcharge calculations.
* Minimum balance requirements.
* Insufficient balance rejection.

The advanced implementation in Task12 demonstrates Airport fares, weekend discounts, and monthly-pass zone coverage.

## Design Considerations

* Use integer paise for reliable monetary calculations.
* Use `enum class` to represent metro zones.
* Keep smart-card balance private and validate deductions.
* Use constants for fare rules and minimum balance requirements.
* Validate user input before calculating fares.
* Test boundary conditions and invalid inputs.

## Limitations

The implementation is an academic simulation. A production metro system would require persistent card records, secure payment processing, transaction logging, concurrency handling, and configurable fare policies.

Student and senior concessions require a clearly defined concession policy before they can be implemented and validated.

## Conclusion

The assignment demonstrates C++ programming concepts through a metro smart-card scenario, progressing from basic language features to fare validation, testing, and an extended fare system.
