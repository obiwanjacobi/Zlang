# Types

## Built-in data types

The built-in data type form the basic building blocks for creating structures.

> **_All type names start with a capital letter_**

There are built-in types for integers, floating point, string and boolean.

### Integers

The type names have been shortened to an absolute minimum. First:

- U - unsigned integer
- I - signed integer

followed by the width in the number of bits.

- 8
- 16
- 24
- 32

```
U8 U16 U24 U32
I8 I16 I24 I32
```

`U8` is default for when the integer data type is not explicitly specified.

### Floating Point

The floating point data types are:

```
F16 F32
```

### Strings

A 'string' of characters of text.

```
Str
```

A string is an `Array` of characters. But there is no character data type, so `U8` is used as a byte. Assumed here is that characters are ASCII based.

### Boolean

The boolean data type is defined as:

```
Bool
```

### Bits

The `Bit` type is parameterized to specify the number of bits the value contains.

Here the example declares a `Bit` type that contains 4 bits (nibble):

```
Bit<4>
```

When `Bit`s are stored, the closest fitting data type is used. So a `Bit<6>` would take up a single byte `U8`, while a `Bit<12>` would take up two bytes `U16`. `Bit`s are always interpreted as unsigned and stored in the lower bits of the storage type. The upper unused bits are reset to zero.

## Pointer Types

> Call them 'pointers' or 'references'?

The template type `Ptr<T>` is used to represent a pointer.

```C#
ptr: Ptr<U8>        // pointer to an U8
ptr: Ptr<U8>?       // an optional pointer to U8
ptr: Ptr<U8?>       // pointer to an optional U8
```

Create a pointer:

```C#
v = 42;
ptr = v.ref()       // explicit call
```

Dereference a pointer:

```C#
ptr: Ptr<U8>
v = ptr.deref()     // explicit call
```

### Optional

```C#
p: Ptr<U8?>     // ptr to optional U8
```

### Pointer to Pointer

Should be no different than creating that initial pointer.

```C#
pp: Ptr<Ptr<U8>>        // ptr to ptr to U8
opp: Ptr<Ptr<U8>>?      // optional ptr to a ptr to U8
pop: Ptr<Ptr<U8>?>      // ptr to optional ptr to U8
```

> unique and shared/borrowed pointers?

Do we want to go the C++ way?

## Aliases

```
MyType = OtherType<Complex<U8>, Str>
```

## Generics / Templates

> TODO

Can generic be resolved at compile time? What scenarios are not possible if we do? Are those templates (as in C++)?

Structs

```C#
MyStruct<T>
    f: T

s = MyStruct<U8>
```

functions

```C#
typedFn<T>(p: T)
    ...

s = typedFn(42)         // type inferred and checked
s = typedFn<U8>(42)     // type explicit
```

restriction

```C#
typedFn<T: >(p: T)
    ...

s = typedFn(42)         // type inferred and checked
s = typedFn<U8>(42)     // type explicit
```

---

> Not implemented yet

Ideas...

## Unions

```
MyStruct: Struct1 | Struct2
```

## Multiple Inheritance

```
MyStruct: Struct1 & Struct2
```

---

> This too?

```
OneOrTheOther: Struct1 or Struct2
```

How do you know what type is active?
(hidden id?)
Pattern matching?
