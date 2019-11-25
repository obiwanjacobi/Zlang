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

```C#
z: MyStruct
    field1 = 42     // inline assignment
```

> Because both the `Equals` and the `Assignment` operators use the '`=`' symbol, it is not possible to assign values inside a comparison expression.

```C#
if a = myFunc()      // error!
    ...
```

---

## Atomic Assignment

protect from (non-maskable) interrupts.

> TBD: A way to ensure an assignment operation is uninterrupted.

- unconditional
- conditional (exchange-if)

> volatile / locking...

---

> TBD

## Deconstructing

deconstructing an array

```C#
[a, b, ...rest] = [1, 2, 3, 4, 5]

// a: U8 = 1
// b: U8 = 2
// rest: Array<U8> = [3, 4, 5]
```

Deconstructing function parameters

```C#
func(p: U8)
    ...

arr = [1, 2, 3, 4, 5]

func(...arr)    // called 5 times
```

Deconstructing a structure:

```C#
MyStruct
    field1: U8
    field2: U8
    field3: U8

s = MyStruct
    ...

[field1, field2] = s
// field1: U8 = <value of s.field1>
// field2: U8 = <value of s.field2>

[a, b] = s      // error! field names must match
```

Swap variables (unlike structs)

```C#
x = 42
y = 101

[x, y] = [y, x]

// x = 101
// y = 42
```
