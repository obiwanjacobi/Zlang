# Operators

Most operators are syntactic sugar over a set of wellknown functions.

Of these wellknown functions there are two flavors: unchecked and checked implementations. The unchecked flavor is used in the final program and its implementation is optimized to the fullest extend. The checked version implements extra validation and 'checking' to help make sure the code is correct.

Operators never allocate memory!

## Operator Symbols

| Operator | Description
|---|---
| + | Addition
| - | Subtraction / Negation
| * | Multiplication
| / | Division
| % | Remainder
| ** | Power
| = | Equals
| <> | Not Equals
| > | Greater than
| < | Smaller than
| >= | Greater or Equal
| <= | Smaller or Equal
| ? : | Unary Comparison
| and | Logical And
| or | Logical Or
| not | Logical Negation
| & | Bitwise And
| \| | Bitwise Or
| ^ | Bitwise Exclusive Or
| ~ | Bitwise Negation (invert)
| >> | Bitwise Shift Right
| << | Bitwise Shift Left
| >\| | Bitwise Rotate Right
| \|< | Bitwise Rotate Left
| = | Value Assignment
| [ ] | Slice / Range

## Other Symbols

| Symbol | Description
|---|---
| _ | Unused / Discard
| . | Members Access
| : | (Sub)Type Specifier
| < > | Type Parameter
| ( ) | Function
| " " | String
| ' ' | Character
| ! | Possible Error (on return type)
| ? | Optional variable or parameter/return value
| \| \| | Optional fallback (or ??)
| # | Pragma / Attribute Access
| #! | Compile-Time Code
