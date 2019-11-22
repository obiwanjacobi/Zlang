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

> `Array`s are fixed length, are `Str`'s also fixed length?

> Make a `Ptr<U8>` to point to fixed (null-terminated) strings? And use `Str` for dynamic string?

> What if `Str` is part of structure? Can the entire structure still be allocated on the stack?

### Boolean

The boolean data type is defined as:

```C#
Bool
```

### Bits

The `Bit` type is parameterized to specify the number of bits the value contains.

Here the example declares a `Bit` type that contains 4 bits (nibble):

```C#
Bit<4>
```

When `Bit`s are stored, the closest fitting data type is used. So a `Bit<6>` would take up a single byte `U8`, while a `Bit<12>` would take up two bytes `U16`. `Bit`s are always interpreted as unsigned and stored in the lower bits of the storage type. The upper unused bits are reset to zero.

## Data Types

There is an easy way to create data types to differentiate data at a type level. By using different types the purpose of the data become even more clear.

```C#
Age: U8
PersonName: Str

a: Age = 42
name: PersonName = "John"
```

You do have to use the explicit type on the variable declaration, using defaults will yield standard types (U8 and Str).

The way data types differ from using aliases is in the use of type bound functions.

> Can data types have more fields? If so, how do they differ from structs?

> Is it possible to restrict the valid data for a data type? For instance `0 <= Age <= 130`. Could we use ranges?

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

Assigning a new value to the pointed-to-storage:

```C#
changeByRef(Ptr<U8> ptr)
    ptr.U8(42)          // conversion with new value

    v = ptr.U8()        // how is the link maintained?
    v = 42
```

Template Access

```C#
changeByRef<T>(Ptr<T> ptr)
    x = ptr.T()         // don't know the type

    x = ptr.get<T>()    // ptr.U8() is simply: ptr.get<U8>()
    ptr.set<T>(42)      // error when no conversion from U8 to T
```

Casting

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

### Pointer to Arrays

The pointer to an Array is not expressed with the `Ptr<T>` type. Instead the `Slice<T>` type is used for this.

> TODO: `Slice<T>`

### Pointer Arithmetic

> There is no pointer arithmetic.

Typically a `Slice<T>` should be used to index into a pointer.

> TBD: Syntax for pointing to members of structures?

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

Same as declaring a new type, just without any additions.

```C#
MyType: OtherType<Complex<U8>, Str>
```

## Templates

Templates are processed at compile time.

### Template Structures

```C#
MyStruct<T>
    f: T

s = MyStruct<U8>
```

> This should also work:

```C#
MyStruct<T>: T
    ...

s = MyStruct<OtherStruct>
```

### Template Functions

```C#
typedFn<T>(p: T)
    ...

typedFn(42)         // type inferred and checked
typedFn<U8>(42)     // type explicit
```

### Restricting Template Type Parameters

```C#
MyStruct
    ...
OtherStruct: MyStruct       // derive from MyStruct
    ...

typedFn<T: MyStruct>(p: T)  // accept type (derived from) MyStruct
    ...

o = OtherStruct             // instantiate
    ...

typedFn(o)                  // type inferred and checked
typedFn<OtherStruct>(o)     // type explicit
```

> This too??

```C#
FixedArray<T, count: U8>    // non-type template params?
    arr: Array<T>(count)
```

### Template Specialization

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

Unions

```C#
MyStruct: Struct1 | Struct2
```

Multiple Inheritance (type addition)

```C#
MyStruct: Struct1 & Struct2
```

Type difference (inverse union)

```C#
Difference: Struct1 ^ Struct2
```

---

> This too?

How do you know what type is active?
(hidden id?)
Pattern matching?

Variant

```C#
OneOrTheOther: Struct1 or Struct2
OneOfThese: Struct1 or Struct2 or Struct3 or Struct4
```

---

> Look into data types like C++ implementations of (physical) units. Make it impossible to assign kg to length - that sort of thing.
