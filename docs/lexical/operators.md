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
| ? : | Ternary Comparison
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
| .. | Range operator
| ... | Spread operator

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
| @ | Disable String formatting features
| { } | String formatting parameter / Code Decorator
| [ ] | Index / Slice / Range
| ! | Possible Error (on return type)
| ? | Optional variable or parameter/return value
| \| \| | Optional fallback (or `??`)
| # | Pragma / Attribute Access
| #! | Compile-Time Code

---

> What if operators cause overflow (or underflow)? A bitwise shift `<<` can shift out bits - sort of the point. Does every operator determine for itself if overflow is a problem or is there a general principle?

---

> TBD

```csharp
fld1: Str?  // optional string field

// assign fld1 to x when set,
// otherwise assign empty string
x = fld1 ?? ""

// if fld1 is not set assign empty string
fld1 ??= ""
```
