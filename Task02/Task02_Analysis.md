# Task 02: Tokens, Keywords, Identifiers and Constants

## 1. Aim

To study and demonstrate C++ tokens, keywords, identifiers, constants, macros, `const`, `constexpr`, `enum`, and `enum class` in the Metro Smart-Card System.

## 2. Tokens in C++

Tokens are the smallest meaningful units of a C++ program.

The main categories of tokens are:

| Token Category         | Description                                    | Example                                   |
| ---------------------- | ---------------------------------------------- | ----------------------------------------- |
| Keywords               | Reserved words with predefined meanings        | `int`, `return`, `switch`                 |
| Identifiers            | Names given to variables, functions, and types | `baseFarePaise`, `getBaseFare`            |
| Constants and literals | Fixed values used in a program                 | `20`, `5000`, `"Metro Smart-Card System"` |
| Operators              | Symbols that perform operations                | `=`, `+`, `==`, `*`                       |
| Punctuators            | Symbols that structure the program             | `;`, `{}`, `()`, `,`                      |

The program uses these token categories to define fare rules, calculate fares, and display results.

## 3. Keywords and Identifiers

### Keywords

Keywords are reserved words in C++ and cannot be used as ordinary identifiers.

Examples used in this program include:

* `int`
* `long`
* `return`
* `switch`
* `case`
* `enum`
* `class`
* `auto`
* `const`
* `constexpr`

### Identifiers

Identifiers are names assigned to program elements.

Examples from the implementation include:

* `getBaseFare`
* `baseFarePaise`
* `peakFarePaise`
* `MIN_BALANCE_PAISE`
* `PEAK_SURCHARGE_PERCENT`
* `selectedZone`

Descriptive identifiers improve readability and make the fare calculation logic easier to maintain.

## 4. Constants and Macros

The program demonstrates three ways of representing fixed values.

### 4.1 Macro using `#define`

```cpp
#define LEGACY_PEAK_PERCENT 20
```

The preprocessor replaces occurrences of `LEGACY_PEAK_PERCENT` with `20` before the compiler processes the program.

A macro does not have a normal C++ type and does not follow ordinary variable scope rules.

### 4.2 Constant using `const`

```cpp
const std::string projectName = "Metro Smart-Card System";
```

The `const` qualifier prevents modification of the object through that name after initialization.

### 4.3 Compile-time constant using `constexpr`

```cpp
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;
```

`constexpr` specifies that a variable is intended to be usable in constant expressions and must satisfy the applicable compile-time constant-expression requirements.

These constants make the fare rules clearer and reduce repeated hard-coded values.

## 5. Comparison: `#define`, `const`, and `constexpr`

| Feature                   | `#define`                                              | `const`                                    | `constexpr`                                     |
| ------------------------- | ------------------------------------------------------ | ------------------------------------------ | ----------------------------------------------- |
| Mechanism                 | Preprocessor text substitution                         | C++ object declaration                     | C++ object declaration for constant expressions |
| Type checking             | No type associated with the macro itself               | Yes                                        | Yes                                             |
| Scope                     | Not governed by ordinary C++ block scope               | Follows C++ scope rules                    | Follows C++ scope rules                         |
| Value requirement         | Text replacement; no object initialization requirement | Initialized according to its declared type | Must satisfy constant-expression requirements   |
| Debugging and readability | Can be less transparent                                | Clear typed declaration                    | Clear typed declaration                         |
| Typical use               | Legacy code or conditional preprocessing               | Values that must not be modified           | Values needed in compile-time expressions       |

For the metro system, `constexpr` is a suitable choice for fixed fare percentages and the minimum balance. The macro is included to demonstrate the older preprocessor approach.

A macro do
