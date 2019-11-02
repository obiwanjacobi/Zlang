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

The template type `Ptr<T>` is used to represent a pointer.

```C#
ptr: Ptr<U8>        // pointer to an U8
```

Create a pointer:

```C#
v = 42;
ptr = v.Ptr()       // explicit call
```

Dereferencing a pointer is done by using [Conversion](./conversion.md) functions. The pointer will be dereferenced implicitly.

```C#
ptr: Ptr<U8>
v = ptr.U8()        // conversion call
```

[Conversion](./conversion.md) to other types is only allowed if the target type has the exact same number of bits as the `T` of the pointer.

```C#
ptr: Ptr<U8>
v = ptr.I8()        // ok, unsigned to signed conversion
v = ptr.U16()       // error! U16 is too big
b = ptr.Bit<4>([4..8])  // error! Bit<4> is too small
```

This also works with structures:

```C#
MyStruct: OtherStruct
    ....

ptr: Ptr<MyStruct>
s = ptr.OtherStruct()   // can convert to base type
```

### Optional

```C#
ptr: Ptr<U8>?       // an optional pointer to U8
ptr: Ptr<U8?>       // pointer to an optional U8
```

### Pointer to Pointer

Should be no different than creating that initial pointer.

```C#
pp: Ptr<Ptr<U8>>        // ptr to ptr to U8
opp: Ptr<Ptr<U8>>?      // optional ptr to a ptr to U8
pop: Ptr<Ptr<U8>?>      // ptr to optional ptr to U8
```

### Casting

To change the type of a pointer:

```C#
MyStruct : OtherStruct
    ...

ptr = Ptr<MyStruct>
cast = ptr.Ptr<OtherStruct>()   // ok, cast to derived type
p = cast.Ptr<MyStruct>()        // ok, is original type
```

```C#
MyStruct : OtherStruct
    ...
MyStruct2: OtherStruct
    ...
ptr = Ptr<MyStruct>
cast = ptr.Ptr<OtherStruct>()
p2 = cast.Ptr<MyStruct2>()        // error, is not original type

```

If the original type is lost, casting up the inheritance hierarchy will always fail.

## Aliases

```
MyType = OtherType<Complex<U8>, Str>
```

## Templates

Templates are resolved at compile time.

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

typedFn(42)         // type inferred and checked
typedFn<U8>(42)     // type explicit
```

restriction

```C#
typedFn<T: >(p: T)
    ...

typedFn(42)         // type inferred and checked
typedFn<U8>(42)     // type explicit
```

specialization

```C#
typedFn<T>(p: T)
    ...
typedFn<Bool>(p: Bool)
    ...

typedFn(42)         // generic typedFn<T> called
typedFn(true)       // specialization typedFn<Bool> called
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
