# Types

There are built-in types that define the basic data storage widths and semantics.

Several flavors of custom types can be defined:

- [Enumeration](./emums.md). A grouped set of named values.
- (Custom) Data Types. Types that restrict the built-in data types further.
- [Structures](./structures.md). A group of data fields always together.
- Related Types. Types that are based on existing types but differ in a small way. For instance a read-only version of a structure or the common fields from multiple other types.

There is a basic syntax that all types declarations follow:

```csharp
TypeName: BaseType
    #meta = value   // data type constraints (#)
    Enum = value    // enum named values
    Field: Type     // struct fields
```

`TypeName`: The name of the type.

`BaseType`: (optional) the name of the type this new type is based on (derives from).

Then each type has its own way of specifying its implementation:

`#meta` refers to a compile-time meta property that can be used in a DataType rule to restrict the value range of the defined type. See 'Custom Data Types' further down.

`Enum` is used to define a named value type. It is optional to specify an explicit value. See also [Enums](enums.md).

`Field` sets the defined type up as a data structure containing one or more fields. See also [Structures](structures.md).

## Built-in Types

The built-in data type form the basic building blocks for creating structures.

> **_All type names start with a Capital letter_**

There are built-in types for integers, floating point, string and boolean.

### Integers

The type names have been shortened to an absolute minimum. First:

- U - unsigned integer
- I - signed integer

> TBD: Or should we use 'S' for signed integers?

followed by the width in the number of bits.

- 8
- 16
- 24
- 32

```C#
U8 U16 U24 U32
I8 I16 I24 I32
```

> TBD: Do we want an autoscaling `Int`eger type?

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

A string is an `Array` of characters. There is no character data type, so `U8` is used as a character byte. Assumed here is that characters are ASCII based (see note below).

An `Array` is fixed length, therefor `Str`'s are also fixed length, meaning that when a `Str` is constructed its length is known.

---

> String Encoding is skipped over at this moment and ASCII is assumed. However eventually it _has_ to be addressed.

I am thinking of making each encoding available in a dedicated type which can be converted to one another.

```csharp
StrUtf7
StrUtf8     // most common
StrUtf16
StrWin1251
StrWin1252
StrIso8859
```

Similar types would exist for `Text`.

Encoding (decoding) is the act of interpreting an array of bytes into a string of characters using a specific set of rules (UTF8 etc).

```csharp
buffer: Array<U8>   // byte array
// interpret at UTF8
str = StrUtf8.Encode(buffer)    // option #1
str = buffer.ToUtf8()           // option #2
// str: StrUtf8

// do we need allocation?
str = buffer.ToUtf8(alloc)      // option #2
```

### Text

Just like `Str` is syntactic sugar for an `Array<U8>` in that same way `Text` is synonym for `List<U8>`. This means that the content data - the text itself - is stored using an allocator in some 'external' memory. The reference to that memory and some bookkeeping variables are stored on the stack in the Text structure.

```C#
Text
```

> Conversion between Text and Str will be common. Aim to overload most Str/Text bound functions.

> A TextBuilder will probably be required to efficiently create longer texts.

> We could introduce a type that holds concatenated strings/texts as separate parts and read them using an iterator appearing to be one continuous text. That way no extra memory allocation is required putting the parts together - only some extra processing during read. An additional 'build' function could do all the allocations and return a single text at any point in time.

> Zero terminated strings provide different advantages as to a pointer-length one. Zero-terminated requires less housekeeping and the zero-sentinel is well established. A pointer-length may be very convenient for sub-strings and splitting parts. If there would be a way to transparently use one or the other - interchangeably.

---

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

### Function Type

The function type `Fn<T>` is used when the type of a function is used in code but no [Function Interface](interfaces.md#Function-Interface) is available.

```csharp
// returns a void function (fn: ())
makeFn(p: U8): Fn
    ...

f = makeFn(42)
f()         // call returned function
```

Note that the type of a function has a specific syntax:

`(parameter-types): return-type`

> Templates?

```csharp
// returns a function that takes one param (U8) and returns a Str
makeFn(p: U8): Fn<(U8): Str>
// returns a function that takes two params (Str and U8) and returns a Bool
makeFn(p: U8): Fn<(Str, U8): Bool>
// returns a function that takes one param (U8) and has no return
makeFn(p: U8): Fn<(U8)>
```

### Void

A special type to allow to be explicit when there is no (function return) Type. Acts as the functional `Unit` in that it has only one value: itself and therefor holds no information.

```csharp
VoidFn: ()    // no return type: Void
    ...

v = VoidFn()    // legal: v => Void
// you can't do anything with v, though.

NoParamsFn: (Void): U8    // Error: Void not allowed here
    ...
```

Introducing the `Void` type removes the necessity to distinguish between functions with or without a return value. See the 'Void' topic in [Functions](functions.md) for more info.

## Literal Numerical Values

Literal values are commonly use in programs and by default the compiler will assign the smallest data type to fit the literal numerical value. There are times when you want to override that, however.

```csharp
a = 42          // a: U8
b = U16(42)     // b: U16
c: U24 = 42     // c: U24
```

We are simply calling a dedicated constructor function with the literal value.

## Custom Data Types

(Constrained Types? / Type Constraints)

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

The use of `_` is optional in most cases. It signifies that nothing follows the declaration.

You do have to use the explicit type on the variable declaration, using defaults will yield standard types (U8 and Str).

Here's an example of the use of data types.

```csharp
MetricLength: U16 _
ImperialLength: U16 _

ml: MetricLength = 200      // 200 meter
il: ImperialLength = 200    // 200 yards

loa = ml + il               // error: cannot add different data types
```

Operators of the underlying type can **NOT** be used. Data Types are always more specific and restrictive than the underlying type. New operator implementations have to be created using the dedicated function names mapped to each operator. It is a compile error if such a function is not found for the operator in use.

> I think in the majority (if not all) of cases these functions can be generated by the compiler, even/especially when rules are defined. But overriding with custom functions must always be possible.

```csharp
Age: U8 _
a: Age = 42
// use conversion to get to underlying types
u = a.U8()      // u: U8
```

> What result type promotion will there be for arithmetic operators on custom data types? Will simply the return type of the operator-function determine the result type?

Based on the rules of a Custom Data Type, the value range of the result can be determined at compile time and an appropriate (smallest) return type can be chosen.

Note that numerical literals could also be thought of restricted custom data types (in a way). A constant value of 2 only has a small impact on the number of extra bytes needed for the result after an arithmetic operation.

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

Custom Data types cannot have any fields. A struct can be composed of fields using (only) data types.

```C#
Age: U8
    #value = 0
    #value = [2..101]   // Range syntax
Mode: Str       // this would be a Str-Enum...
    #value = "A"
    #value = "B"
    #value = "C"
Length: I16
    #value > 0
```

> overload/override value setter (assignment operator?) to do custom validation? Can this code be generated at compile-time by the compiler?

### Literal Values

Make a literal value have a custom data type.

```csharp
MyType: U16 _

a = MyType(42)  // passes all rules
```

```csharp
SmallType: U8
    #value = [0..4]     // 0,1,2,3

a = SmallType(42)       // Error: does not pass rules
```

```csharp
MidType: U8 _

// does not fit into base type
a = MidType(275)        // Error: does not pass rules
```

Again, we're simply calling dedicated construct functions.

### Custom Data Constraints

The rules that can be defined after the type declaration narrow the value range based on its base-type - in a declarative manner.

By default the specified rules are ANDed together in that all the specified rules must pass before a value assignment will succeed.

> How to create ORed rules?

```csharp
CustomDataType: U8
    #value > 10 or #value = 0
```

> Support ranges as constraint values.

```csharp
CustomDataType: U8
    #value = [1..43]    // 1 - 42
```

String-rules may need extra features to match different aspects of the value. The goal is NOT to create a Regular Expression engine, but just cover the basic stuff. For complex validation a custom validation function (override) has to be defined.

```csharp
CustomDataType: Str
    #value += "Abc"     // starts with
    #value =+ "Abc"     // ends with with
    #value +=+ "Abc"    // contains
    #value -= "Abc"     // does not start with
    #value -=- "Abc"    // does not contain
    #value <> "Abc"     // not equal to
```

> TBD: do we want a custom error message text to go with the rule?

```csharp
CustomDataType: Str
    #length <= 100, "Too long"
```

### Custom Data Type Conversion

Any conversion to or from a custom data type must be hand written. The compiler cannot know how/what to convert when/where.

```csharp
// custom types
Hour: U8 _
Minute: U16 _
Second: U16 _

// conversion functions
Minutes: (self: Hour): Minute => self * 60
Seconds: (self: Minute): Second => self * 60
Seconds: (self: Hour): Second => self * 3600

h: Hour = 2
m = h.Minutes()     // m = 120
s = m.Seconds()     // s = 7200
s = h.Seconds()     // s = 7200
```

---

## Types with Operators

Some built-in (decorator) types are use so often, it makes sense to provide a shorter version in the form of an operator.

Type | Operator | Position
--|--|--
`Err<T>` | ! | Post
`Opt<T>` | ? | Post
`Ptr<T>` | * | Pre
`Imm<T>` | ^ | Pre

The optional and error types can be thought of as constrained variant types.

```csharp
Opt<T>: T or Nothing _
Err<T>: T or Error _
```

`Nothing` is an no-value indication for the compiler and is never available to the program.

`Opt` is discussed in more detail [here](optional.md).

`Err` is discussed in more detail [here](errors.md).

`Ptr` is discussed in more detail [here](pointers.md).

Several convenience types are created.

```csharp
ImmPtr<T> = Ptr<Imm<T>>
OptErr<T> = Err<Opt<T>>
```

### Operators

```csharp
o: U8?      // optional U8
e: U8!      // U8 or error
x: U8!?     // optional U8 or Error
p: *U8?     // optional pointer to an U8
i: ^*U8?    // optional immutable pointer to an U8
```

`Err<T>` is typically (only) used on function return values.

### Immutable Types

Any type can be made immutable wrapping it in a `Imm<T>` type.

```csharp
a: U8   // mutable
a = 42  // ok, a = 42

// immutable has to be initialized on declaration
b: Imm<U8> = 42     // init with 42
b = 101             // error! type is immutable
```

> TBD: `with` in some other languages. Mutations on an immutable type results in a new instance.

```csharp
s: Imm<Struct>
    ...         //   init struct

// s2 is copy of s with changed field
// what syntax?
s2 = s => { fld1 = 42 }     // object construction
s2 = s.Mut({ fld1 = 42 })   // explicit function call1
s2 = s.Clone({ fld1 = 42 }) // explicit function call2
s2 = s + { fld1 = 42 }      // special operator1
s2 = s & { fld1 = 42 }      // special operator2
s2 = s <= { fld1 = 42 }     // special operator3
```

> TBD: type validation after construction? This is a general issue...

In all these cases the period of time that the new instance is mutable (when a new instance is created and the old and the new values are copied in) is managed by the compiler and shielded from the developer.

## Type Alias

Provides a new name for an existing type. Similar to declaring a new type but without any additions.

```C#
// a real new type (struct)
MyType: OtherType<Complex<U8>, Str> _   // _ to indicate no fields

// another name for the same type (alias)
MyType = OtherType<Complex<U8>, Str>
```

During compilation all references to type aliases are replaced with their original types. Compiler-issues _are_ reported using the original type alias name.

## Type Constructors

> Any function can be a factory (function). Type constructors are checked specifically by the compiler to make sure they return new instances of a type.

A type constructor is a function with the same name as the type it creates and returns.

> Does the constructor function name has to be the exact same as the original Type definition or do we allow the identifier naming rules to apply?

The number and types of parameters a constructor function takes have no restrictions.

```csharp
MyType
    ...

MyType: (p: U8): MyType
    ...

t = MyType(42)
// t is an instance of MyType initialized with 42
```

Using templates

```csharp
MyType<T>
    ...

MyType: <T>(p: T): MyType<T>
    ...

t = MyType(42)
// t is an instance of MyType initialized with 42 (T=U8)
```

A name-clash can occur when you introduce a new Type with a name that (falsely) matches an existing function as its constructor function. Unfortunately that would mean you would have to alias the existing function to a different name at the locations where it is used and that also reference the new Type. See [Import](../modules/import.md) for more on aliasing.

When construction of the type is not trivial and Errors may occur the type constructor function has to have a return type of `Err<T>`.

```csharp
MyType
    ...
MyType: (p: U8): MyType!

t = try MyType(42)
```

### Type Constructor Overloading

A Type Constructor function can be overloaded - normal functions can only be overloaded based on the self parameter.

At Compile-Time the correct overload will be determined and a compilation error will be generated when no suitable overload was found.

```csharp
MyType
    ...

MyType: (p1: U8): MyType
    ...
MyType: (p1: U8, p2: Str): MyType
    ...
MyType: (p1: U8, p2: Str, p3: U16): MyType
    ...

// uses overload with 3 parameters
t = MyType(42, "42", 0x4242)
```

## Constrained Variant

Also known as Discriminated Unions.

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

> A Ptr should still point to the payload of the variant so perhaps store the var-type in front of the main payload.

A constrained variant instance cannot change type during its lifetime.

## Type Manipulation

Related variations can be created easily from existing types.

```C#
MyStruct
    fld1: U8
    fld2: U16

// make type optional
MyOptionalStruct: Opt<MyStruct>
MyOptionalStruct: MyStruct?     // language supported
// fld1: U8?
// fld2: U16?

// make type read-only
MyReadOnlyStruct: Imm<MyStruct>
MyReadOnlyStruct: ^MyStruct
// fld1: ^U8
// fld2: ^U16
```

Make an instance read-only:

```csharp
s: MyStruct
// using a conversion to make immutable
r = s.Imm()
r.fld1 = 101        // error! field is read-only

//-or-  cast will convert
r: MyReadOnlyStruct = s
```

Make an instance optional:

```csharp
s: MyStruct
// using a conversion to make optional
o = s.Opt()
o.fld1 = _        // field is 'nulled'

//-or-  cast will convert
o: MyOptionalStruct = s
```

---

## TBD

Ideas...

The `|`, `&` and `^` operators act on the memory of a type (sort of).

`and` and `or` operate on the logical type.

> In no case can a type ever be empty.

What about marker interfaces?

### Unions

> How are shared fields (locations) initialized when two structs have different default values? Or simply init to zero-always.

> What happens if -part of- a field is accessed through another -incompatible- type? For instance: `Str|U8` write `Str="42"` and read through `U8`. (also a problem in C).
COM-interop (.NET) disallows this.

```C#
MyUnion1: Struct1 | Struct2
MyUnion2: Struct1 | Struct2 | Struct3

MyUnion             // all fields share the same memory
    fld1: U8 |
    fld2: U16 |
    fld3: Str |     // trailing | ok
```

> Because there is no `union` keyword, anonymous or inline unions are not possible.

A union can be used with any type or struct.

```csharp
Union1
    fld1: U8 |
    fld2: U16
Union2
    prop1: Str |
    prop2: Bool

// one big union
Union3
    un1: Union1 |
    un2: Union2

// struct with 2 unions
Struct1
    un1: Union1
    un2: Union2
```

### Type Commonality

Common fields in all types.

```C#
MyStruct: Struct1 & Struct2
```

A compiler error is generated if no fields are common - the type defined is empty.

### Type difference

Think of this as an inverse union.

```C#
Difference: Struct1 ^ Struct2
```

> Can the `|`, `&` and `^` be combined in one declaration? What is the precedence of these operators?

```csharp
MyStruct: (Struct1 & Struct2) | (Struct3 ^ Struct4)
```

### Multiple Inheritance

Type addition.

```C#
MyStruct: Struct1 and Struct2
```

Laid out in memory in order of definition.

> How to move the 'self' pointer? => All info is available at compile-time.

```csharp
MyStruct: Struct1 and Struct2
structFn(self: Struct2, U8)
    ...

s: MyStruct
    ...

s.structFn(42)      // the 'reference' to the structFn has to go past Struct1
// Also goes for Ptr's to sub-parts

// explicit offset? (verbose!)
structFn(s#offset(Struct2), 42)
```

---

## Dynamic Type

> Should dynamic types be taken into account? How would the syntax look and what semantics are attached?

A dynamic type would require a whole runtime system that turns away from the compile-time focus currently aimed for.
Dynamic types may be required when doing a REPL interface..?
But that would be more of an implementation detail of the REPL itself.

```csharp
d: Dyn              // dynamic type
d.prop1 = 42        // creates a new field (fixed type)

MyFunction: (self: Dyn, p1: U8): Bool
    // does field exist
    if self?#prop1
        return self.prop1 = 42

    // does function exist
    if self?#getMagicValue
        return self.getMagicValue() = 42
    return false

if d.MyFunc(42)
    ...
```

> What functions are available to which `Dyn` instances?

Calling non-existent functions should raise an (runtime) Error.
Accessing non-existing fields returns 0? -or- always requires a check in the same scope (like optional)?

> Can fields be removed?

```csharp
d: Dyn
d.prop1 = 42    // now you see it
d.prop1 = _     // now you don't
```

> Can functions be assigned to instances?

```csharp
MyFunction: (self: Dyn, p1: U8): Bool
    ...

d: Dyn
// depend on dot-syntax here!
d.MyFunc = MyFunction

if d.MyFunc(42)
    ...

d.MyFunc = _    // function is removed
```

---

## Variant Type

> Do we need a variant type? => Don't think so, we have constrained variants.

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

---

> Other types that need close integration with the compiler?

- Buffer / RingBuffer
- Stream
