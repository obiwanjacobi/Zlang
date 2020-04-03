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

> Zero terminated strings provide different advantages as to a pointer-length one. Zero-terminated requires less housekeeping and the zero-sentinel is well established. A pointer-length may be very convenient for sub-strings and splitting parts. If there would be a way to transparently use one or the other - interchangeably.

### Boolean

The boolean data type is defined as:

```C#
Bool
```

It can only have one of two values: `true` or `false`.

### Bits

The `Bit` type is parameterized to specify the number of bits the value contains.

Here the example declares a `Bit` type that contains 4 bits (nibble):

```C#
Bit<4>
```

When `Bit`s are stored, the closest fitting data type is used. So a `Bit<6>` would take up a single byte `U8`, while a `Bit<12>` would take up two bytes `U16`. `Bit`s are always interpreted as unsigned and stored in the lower bits of the storage type. The upper unused bits are reset to zero.

## Optional and Error Types

> The optional and error types can be thought of as constrained variant types.

```csharp
Opt<T>: T or Nothing _
Err<T>: T or Error _
```

`Nothing` is an no-value indication for the compiler and is never available to the program.

`Error` is discussed [here](../Types/Error.md).

### Operators

```csharp
o: U8?  // optional U8
e: U8!  // U8 or error
x: U8!? // optional U8 or Error
```

## Data Types

> Look into data types like C++ implementations of (physical) units. Make it impossible to assign kg to length - that sort of thing.

(Constrained Types?)

There is an easy way to create data types to differentiate data at a type level. By using different types the purpose of the data become even more clear.

```csharp
Age: U8 _           // no rules
PersonName: Str
    #length < 100   // rules
    #length > 0
```

```csharp
Age: U8 _
PersonName: Str _

a: Age = 42
name: PersonName = "John"
```

Use `_` to differentiate from variable declarations. Without the trailing `_` it would be variable not a Type.

You do have to use the explicit type on the variable declaration, using defaults will yield standard types (U8 and Str).

Here's an example of the use of data types.

```csharp
MetricLength: U16 _
ImperialLength: U16 _

ml: MetricLength = 200      // 200 meter
il: ImperialLength = 200    // 200 feet

loa = ml + il               // error: cannot add different data types
```

Operators of the underlying type can **NOT**  be used. Data Types are always more specific and restrictive than the underlying type. New operator implementations have to created using the dedicated function names mapped to each operator. It is a compile error if such a function is not found for the operator in use.

```csharp
Age: U8 _
a: Age = 42
// use conversion to get to underlying types
u = a.U8()      // u: U8
```

The way data types differ from using aliases is in the use of type-bound functions.

```csharp
Alias = U16
DataType: U16 _

baseFn(self: U16, p: U8)
    ...
aliasFn(self: Alias, p: U8)
    ...
typeFn(self: DataType, p: U8)
    ...

a: U16 = 0x4242
a.baseFn(42)        // U16 = Alias
a.aliasFn(42)       // Alias = U16
a.typeFn(42)        // error! U16 != DataType

d: DataType = 0x4242
d.baseFn(42)        // error! DataType more specific than U16
d.aliasFn(42)       // error! same reason
d.typeFn(42)        // ok
```

> Can data types cannot have any fields. A struct can be composed of fields using only data types.

> It is possible to restrict the valid data for a data type. For instance `0 <= Age <= 130`. Could we use ranges? Perhaps make an `or` type with literals and or range expressions?

```C#
Age: U8
    0
    2..100
Mode: Str
    "A"
    "B"
    "C"
```

> overload/override value setter (assignment operator?) to do custom validation?

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

See also Union/Constrained Variant Types.

## Pointer Types

The template type `Ptr<T>` is used to represent a pointer. Z# reserves characters like `*` -commonly used in other languages to indicate pointer types- for operators.

> The number of bits used for a pointer into memory depends on the memory model: 16, 20, 24 ...?
When bank switching and extended memory is worked out this number is configured for the compiler to use.

```C#
ptr: Ptr<U8>        // pointer to an U8
```

Create a pointer:

```C#
v = 42;
ptr = v.Ptr()       // explicit call to make ptr
```

Dereferencing a pointer is done by using [Conversion](./conversion.md) functions. The pointer will be dereferenced implicitly.

> TODO: do not do anything implicitly!

```C#
ptr: Ptr<U8>
v = ptr.U8()        // conversion deref call
```

[Conversion](./conversion.md) to other types is only allowed if the target type has the exact same number of bits as the `T` of the pointer.

> Do we want that? Two actions in one: deref and conversion.

Assigning a new value to the pointed-to-storage:

```C#
changeByRef(Ptr<U8> ptr)
    ptr.U8(42)          // conversion with new value
    ptr.value(42)       // same (uses Ptr type: U8)
    ptr.value<U8>(42)   // same, explicit

    v = ptr.U8()        // v is a local copy
    v = 42              // does NOT change ptr value!
```

> Alternate Syntax

```C#
ptr: Ptr<U8>        // must be initialized or optional
v = ptr()           // deref? v => U8
ptr() = 42          // change pointed to value?
```

This does align nicely with ptr-to-fn syntax and how to call a function using a ptr-to-fn: `retval = ptr_to_fn(param1)`

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

> Pointer variables need to be initialized when declared or they must be made optional.

```csharp
p: Ptr<U8>      // error! must have value or be optional
p: Ptr<U8>?     // ok, no value - so optional

a = 42;
p: Ptr<U8> = a.Ptr()    // ok, ptr has value
```

> How does writing to an optional ptr work?

```csharp
a: U8?                      // now _
p: Ptr<U8?> = a.Ptr()

// how does the instance in memory know it's no longer _ ??
p() = 42
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

> Do we need a generic `object` type as a 'void' pointer?

---

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

---

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

// type inferred and checked
typedFn(42)

// type explicit
typedFn<U8>(42)
// new forms of casting?
typedFn(42: U8)
typedFn(x: U8)

// return values
typedRet<T>(): T
    ...

x = typedRet<U8>()
x = typedRet(): U8
y: U8 = typedRet()  // type forwarding?
z = typedRet()      // Error! cannot determine type
```

> Are template parameters simply normal parameters know at compile time?

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
typedFn<MyStruct>(o)        // base type explicit
typedFn<OtherStruct>(o)     // derived type explicit
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

## TBD

Ideas...

### Unions

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

### Type commonality

Common fields in all types.

```C#
MyStruct: Struct1 & Struct2
```

Error if no fields are common?

### Type difference

Think of this as an inverse union.

```C#
Difference: Struct1 ^ Struct2
```

The `|`, `&` and `^` operators act on the memory of a type (sort of).

`and` and `or` operate on the logical type.

### Multiple Inheritance

Type addition.

```C#
MyStruct: Struct1 and Struct2
```

Laid out in memory in order.

> How to move the 'this' pointer?

```csharp
structFn(self: Struct2, U8)
    ...

s: MyStruct
    ...

s.structFn(42)      // the 'reference' to the structFn has to go past Struct1
// Also goes for Ptr's to sub-parts

// explicit offset? (verbose!)
structFn(s#offset(Struct2), 42)
```

## Type Manipulation

```C#
MyStruct
    fld1: U8
    fld2: U16

MyOptionalStruct: MyStruct#opt
MyOptionalStruct: MyStruct?     // language supported?
// fld1: U8?
// fld2: U16?

// make type read-only
MyReadOnlyStruct: MyStruct#imm
MyReadOnlyStruct: Imm<MyStruct>
    fld1 = 42           // have to init right away
    fld2 = 0x4242
```

```csharp
// make an instance read-only
s = MyStruct
    fld1 = 42
    fld2 = 0x4242

// using a conversion to make immutable
r = s.Imm()
r.fld1 = 101        // error! field is read-only
```

```csharp
// make an instance optional
s = MyStruct
    fld1 = 42
    fld2 = 0x4242

// using a conversion to make optional
r = s.Opt()
r.fld1 = _        // field is 'nulled'
```

## Constrained Variant

```C#
OneOrTheOther: Struct1 or Struct2
OneOfThese: Struct1 or Struct2 or Struct3 or Struct4

s: OneOfThese
    ...

v = match s
    s1: Struct1 => s1.fld1
    s2: Struct2 => s2.val2
    s3: Struct3 => s3.bla
    s4: Struct4 => s4.myfld
```

> The type-id is stored with the instance. Access with `#varId` or something?

A Ptr should still point to the payload of the variant so perhaps store the var-type in front of the main payload.

A variant instance cannot change type during its lifetime.

---

## Opaque Type Reference

A way to export a handle to an instance of a private type.

```csharp
// both ok
export outFn(p: U8): Otr<MyStruct>
export outFn(p: U8): Otr<Ptr<MyStruct>>
    s: MyStruct
        ...
    return s.Otr()  // cast/convert

export inFn(p: Otr<MyStruct>): U8
export inFn(p: Otr<Ptr<MyStruct>>): U8
    s = p.value<MyStruct>()
    s = p.value<OtherStruct>()  // error! not the correct type
    ...

// usage
import outFn // pseudo
import inFn // pseudo

o = outFn(42)   // o => Otr?
o.x             // error! Otr does not allow member access

a = inFn(o)     // Otr as parameter
```

---

## Dynamic Type

> Should dynamic types be taken into account? How would the syntax look and what semantics are attached?

```csharp
d: Dyn              // dynamic type
d.prop1 = 42        // creates a new field (fixed type)

MyFunction(self: Dyn, p1: U8): Bool
    // does field exist
    if self?prop1
        return self.prop1 = 42

    // does function exist
    if self?getMagicValue
        return self.getMagicValue() = 42
    return false

if d.MyFunc(42)
    ...
```

> Do we need (global!) event handlers for Dynamic-Not-Found events?

```csharp
FieldNotFound(self: Dyn, Str name)
FunctionNotFound(self: Dyn, Str name)
```
