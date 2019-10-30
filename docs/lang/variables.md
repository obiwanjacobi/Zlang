# Variables

Variables store values of a specific type by name. The name is the [Identifier](../lexical/identifier.md) of the variable.

Here is an example of a literal value being assigned to the variable `a`:

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

If no explicit type is given the initialization value is used to infer the smallest type from it. The `Bit` type is never considered.

These are not valid:

```C#
a: U8 = true    // error! Bool cannot be converted to U8
a: U8 = "zlang" // error! Str cannot be converted to U8
```

The names of a variable must be unique inside the root scope they're used in:

```C#
myFunc()            // root scope
    a: U8           // ok, a
    if true
        a: U8       // error! a is shadowed
```

Root scopes are usually function-scope or for 'global' variables it is file-scope.

## Pointers

A pointer variable contains a memory location of the thing it points to.

A specific parameterized type is used to express pointers: `Ptr<T>`:

```C#
a = 42      // U8
p = a#ptr   // p of type Ptr<U8> points to a
```

A pointer of any variable can be obtained by using the `ptr` compiler attribute and the `#` operator.

---

## Type Static, Constants and Globals

> TODO

- Constant, Readonly, Immutable. Whats the difference? When to use what term?

- Type Static
Are constants declared on a struct.
How to declare a const/static on a type?

- Globals
Do not exist in a sense that you cannot export variables. The lifetime of a variable can be global but the access is always limited to the file it is defined in.

