# Assignment Expressions

| Operator | Function
|-------|------
| = | Assign value
| := | Assign copy

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

Some complex types like the `Array` cannot be assigned to. For this case the copy assignment operator `:=` can be used to produce a copy of the complex type.

```C#
arr1 = [1, 2, 3, 4, 5, 6]
arr2 = arr1         // error! cannot assign an array
arr2 := arr1        // ok, arr2 is a duplicate of arr1
```

The copy assignment has been made explicit to inform the reader that a copy is taking place.
