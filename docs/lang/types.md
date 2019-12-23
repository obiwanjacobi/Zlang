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

```C#
U8 U16 U24 U32
I8 I16 I24 I32
```

`U8` is default for when the integer data type is not explicitly specified.

### Floating Point

The floating point data types are:

```C#
F16 F32
```

### Strings

A 'string' of characters of text.

```C#
Str
```

A string is an `Array` of characters. There is no character data type, so `U8` is used as a character byte. Assumed here is that characters are ASCII based.

An `Array` is fixed length, therefor `Str`'s are also fixed length, meaning that when a `Str` is constructed its length is known.

### Text

Just like `Str` is syntactic sugar for an `Array<U8>` in that same way `Text` is synonym for `List<U8>`. This means that the content data - the text itself - is stored using an allocator in some 'external' memory. The reference to that memory and some bookkeeping variables are stored on the stack in the Text structure.

```C#
Text
```

> Conversion between Text and Str will be common. Aim to overload most Str/Text bound functions.

> A TextBuilder will probably be required to efficiently create longer texts.

> We could introduce a type that holds concatenated strings/texts as separate parts and read them using an iterator appearing to be one continuous text. That way no extra memory allocation is required putting the parts together - only some extra processing during read. An additional 'build' function could do all the allocations and return a single text at any point in time.

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

The way data types differ from using aliases is in the use of type-bound functions.

> Can data types have more fields? If so, how do they differ from structs?

> Is it possible to restrict the valid data for a data type? For instance `0 <= Age <= 130`. Could we use ranges?

> overload value setter to do custom validation?

## Variant Type

> Do we need a variant type?

```C#
funcAny(): Any
    ...

a = funcAny()   // a => Any
v = match a
    n: U8 => n
    _ => Error("Unsupported")

// v => U8!
```

See also Union Types.

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
    ptr.value(42)       // same (uses Ptr type: U8)
    ptr.value<U8>(42)   // same, explicit

    v = ptr.U8()        // v is a local copy
    v = 42              // does NOT change ptr value!
```

Template Access

```C#
changeByRef<T>(Ptr<T> ptr, val: T)
    x = ptr.value<T>()  // compatibility checked at compile time
    ptr.value<T>(val)
```

### Static Ptr Helper

```C#
a = 42
ptr = Ptr.to(a)

ptr = Ptr.to(42)    // ptr to literal is immutable
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

p: Ptr<U8>              // Ptr<U8>
pp = p.Ptr()            // Ptr<Ptr<u8>>
```

> Only two levels allowed?

### Pointer to Arrays

The pointer to an Array is not expressed with the `Ptr<T>` type. Instead the `Slice<T>` type is used for this.

> TODO: `Slice<T>`

### Pointer to Immutable

> TBD: A pure reference.

```C#
// literals are immutable by default
x = 42#imm      // or x: Imm<U8> = 42
p = x.Ptr()     // Ptr<Imm<U8>>
p.value(101)      // error! immutable
```

### Pointer Arithmetic

> There is no pointer arithmetic.

Typically a `Slice<T>` should be used to index into a pointer. See Pointer to Arrays.

> TBD: Syntax for pointing to members of structures?

Needs an offset (compile time) from a runtime Ptr.

```C#
MyStruct
    field1: U8
    field2: U16

s = MyStruct
    ...
p = s.Ptr()
pFld2 = p#offset(MyStruct.field2)
```

> What about pointing to bit-field members?

### Casting

Type compatibility.

```C#
ptr: Ptr<U8>
v = ptr.I8()        // ok, unsigned to signed conversion
v = ptr.U16()       // error! U16 is too big
b = ptr.Bit<4>([4..8])  // error! Bit<4> is too small
```

Custom structures must use the value accessor:

```C#
MyStruct : OtherStruct
    ...

ptr = Ptr<MyStruct>
cast = ptr.value<OtherStruct>()     // ok, cast to derived type
p = cast.value<MyStruct>()          // ok, is original type
```

```C#
MyStruct : OtherStruct
    ...
MyStruct2: OtherStruct
    ...
ptr = Ptr<MyStruct>
cast = ptr.value<OtherStruct>()
p2 = cast.value<MyStruct2>()        // error, is not original type
```

If the original type is lost or cannot be determined at compile time, casting up the inheritance hierarchy will always fail.

## Aliases

Same as declaring a new type, just without any additions.

```C#
// a real new type (struct)
MyType: OtherType<Complex<U8>, Str> _   // _ to indicate no fields

// another name for the same type (alias)
MyType = OtherType<Complex<U8>, Str>
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
// non-type template params?
FixedArray<T, count: U8>
    arr: Array<T>(count)

// restricting on metadata?
TemplateType<T#bits=8>  // '=' conflicts with parameter default
    field: T
```

### Template Parameter Defaults

```C#
TemplateType<T=U8>
    field1: T

t = TemplateType
    field1 = 42         // U8
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

> How are shared fields (locations) initialized when two structs have different default values? Or simply init to zero-always.

> What happens if -part of- a field is accessed through another -incompatible- type? For instance: `Str|U8` write `Str="42"` and read through `U8`. (also a problem in C)

```C#
MyStruct: Struct1 | Struct2

MyUnion             // all fields share the same memory
    fld1: U8 |
    fld2: U16 |
    fld3: Str |     // trailing | ok?
```

> Because there is no `union` keyword, anonymous unions are not possible.

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

Variant (constrained)

```C#
OneOrTheOther: Struct1 or Struct2
OneOfThese: Struct1 or Struct2 or Struct3 or Struct4

s = OneOfThese
    ...

v = match s
    s1: Struct1 => s1.fld1
    s2: Struct2 => s2.val2
    s3: Struct3 => s3.bla
    s4: Struct4 => s4.myfld
```

---

> Look into data types like C++ implementations of (physical) units. Make it impossible to assign kg to length - that sort of thing.

> Should dynamic types be taken into account? How would the syntax look and what semantics are attached?

```C#
d: Dyn              // dynamic type
d.prop1 = 42        // creates a new field (fixed type)

SomeFunction(self: Dyn, p1: U8): Bool
    // does prop1 exist
    if self#prop1
    if self?prop1
        return self.prop1 = 42
    return false

if d.MyFunc(42)
    ...
```
