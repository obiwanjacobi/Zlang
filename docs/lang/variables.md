# Variables

Variables store values of a specific type by name. The name is the [Identifier](../lexical/identifier.md) of the variable.

Here is an example of a literal value being used to initialize the variable `a`:

```C#
a = 42
```

A variable is never uninitialized, even if no explicit value is assigned:

```C#
a               // error! a variable must have type
a: U8           // a is of type U8 and has value 0 (default)
a: U8 = 42      // a is of type U8 and has value 42
a = 42          // a is of type U8 (inferred) and has value 42
a = 0x4242      // a is of type U16 (inferred) and has value 0x4242 (hex)
a = -12345      // a is of type I16 (inferred) and has value -12345 (dec)
s = "zlang"     // s is of type Str and has value 'zlang'
b = true        // b is of type Bool and has value true
```

If no explicit type is given the initialization value is used to infer the smallest type from it. The `Bit<T>` type is never considered.

These are not valid:

```C#
a: U8 = true    // error! Bool cannot be 'converted' to U8
a: U8 = "zlang" // error! Str cannot be 'converted' to U8
```

The names of a variable must be unique inside the root scope they're used in:

```C#
myFunc: ()          // root scope
    a: U8           // ok, a
    if true
        a: U8       // error! a is shadowed
```

Root scopes are usually function-scope or for 'global' variables it is file-scope.

---

## Pointer Variables

A pointer variable contains a memory location of the thing it points to.

A specific parameterized type is used to express pointers: `Ptr<T>`:

```C#
a = 42          // U8
p = a.Ptr()     // p of type Ptr<U8> points to a
```

A pointer of any variable can be obtained by using the `Ptr()` conversion function.

```C#
a = 42          // U8
p = a.Ptr()     // p of type Ptr<U8> points to a
b = p()         // b = 42

p() = 101       // a = 101, b = 42
```

See also [Pointers](./pointers.md).

---

## Immutable Variables

When variables are immutable they cannot be changed during their lifetime - their value is constant.

An immutable variable is initialized when declared (not assigned to later).

```C#
c: Imm<U8> = 10  // c has value 10 and cannot be changed

c = 42          // error! cannot change value
a = c           // now a is immutable as well (??)

v = 42          // mutable U8
c: Imm<U8> = v  // ok, immutable copy of v
```

See also [Immutable Types](types.md#Immutable-Types).

---

## Global Variables

Because only immutable variables can be exported, only immutable variable can be thought of as being accessible globally.

The lifetime of any variable can be global, in the sense that the variable maintains its state, but always within the scope of the file it is defined in.

> TBD: in file scope or module (multiple files) scope?
