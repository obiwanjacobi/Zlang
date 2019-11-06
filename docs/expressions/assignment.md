# Assignment Expressions

| Operator | Function
|-------|------
| = | Assign value

> The left operand of an assignment expression can not be a literal value.

Here 42 is assigned to the variable `a`.
```C#
a = 42
```

The receiving (left) operand can also be a path to a field.

```C#
MyStruct
    field1: U8

s: MyStruct
s.field1 = 42
```

> Because both the `Equals` and the `Assignment` operators use the '`=`' symbol, it is not possible to assign values inside a comparison expression.

```C#
if a = myFunc()      // error!
    ...
```
