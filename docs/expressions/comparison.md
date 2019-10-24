# Comparison Expressions

These operators are used to compare to values in different ways. The result is a boolean (`Bool`) value that can be used in a [Logical Expression](logical.md).

| Operator | Function
|-------|------
| = | Equal to
| <> | Not Equal to
| > | Greater than
| < | Smaller than
| >= | Greater or Equal
| <= | Smaller Equal

Here is an example of using several comparison expressions combined into a logical expression to build the condition of an `if` statement.

```C#
a = 42
if a > 10 and a <= 100 and a <> 42
    never_get_here
```

> Because both the `Equals` and the `Assignment` operators use the '`=`' symbol, it is not possible to assign values inside a comparison expression.

```C#
if a = myFunc()      // error!
    ...
```
