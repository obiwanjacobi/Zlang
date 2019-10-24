# Arithmetic Expressions

|Operator|Function
|--------|------
| + | Addition
| - | Subtraction
| * | Multiplication
| / | Division*
| % | Remainder (integer)
| ** | Power
| - | Negation

> *) Division for integer types are rounded towards zero.

Some examples:

```C#
a = 12 * 3   // 36
b = a / -3   // -12
c = 3 ** 3   // 27
d = 16 % 3   // 1

x = (2 + a) * (b / 3) + d
```

## Precedence

When using more than one operator in a single expression, some operators are processed before others: precedence.

The use of `()` indicates that everything inside the parentheses is processed before interacting with other parts of the expression.

## Overflow

Checked functions can be used to implement the operators that check for overflow. Overflow is a condition where the results exceeds the storage capacity of the data types used.
