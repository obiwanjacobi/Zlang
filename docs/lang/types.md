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

> For something to be used quite often, should we not choose a symbol to make it shorter (like C/C++)?

```C#
// I like this best
ptr: Ptr<U8>        // typed
ptr: Ptr<U8>?       // typed, optional

ptr: *U8            // C/C++
ptr: *U8?           // C/C++, optional
ptr: U8*?

ptr: &U8            // alternative
ptr: &U8?           // alternative, optional
ptr: U8&?
```

> How to create a pointer

```C#
v = 42;

ptr = v#ptr         // meta attribute
ptr = &v            // C/C++
ptr = *v            // alternative
// I like this best
ptr = v.Ptr()       // conversion syntax
ptr = v.ref()       // explicit (Ref<T>)
```

> How to dereference a pointer?

```C#
ptr: Ptr<U8>

v: U8 = ptr         // auto unwrapping
v = ptr#val         // meta attribute
v = *ptr            // C/C++
v = ptr.U8()        // conversion syntax
v = U8.From(ptr)    // alt conversion syntax
// this is not symmetrical
v = ptr.deref()     // explicit

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
