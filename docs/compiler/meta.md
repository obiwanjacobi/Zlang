# Meta Programming

> TBD allow to write code and logic that executes at compile time in order to shift the workload as much as possible to compiler.

## Intrinsic Attributes

The compiler will allow accessing intrinsic attributes of the compiled code. These attributes are constants whose value was determined by the compiler at compile time and they do not take up any storage in the program.

A special operator is used to access them: `#`

| Attribute | Description
|----|-----
| min | The minimum value possible.
| max | The maximum value possible.
| bits | The number of bits for the type.
| count | The number of elements.
| size | The size in bytes the type takes up in memory.
| def | Default value for the type.
| ptr | A ptr to the instance of the type.
| imm | An immutable reference to the instance.
| `dup` | A deep copy (duplicate) of the instance. (??)

Not all types support all attributes. The compiler will give an error when the code accesses an attribute that is not supported by the type in question.

```C#
a = 42      // U8
a#size      // 1
a#bits      // 8
a#min       // 0
a#max       // 255
p = a#ptr   // p points to a
q = p#dup   // q points to a

U8#size     // 1
U8#bits     // 8
U8#min      // 0
U8#max      // 255
U8#ptr      // error! not on type
U8#dup      // error! not on type

Bit<3>#size // 1
Bit<3>#bits // 3
Bit<3>#min  // 0
Bit<3>#max  // 7
```

## Pragmas

A pragma is a directive that instructs the compiler to take some action.
For instance turn off a compiler warning temporarily.

A pragma is prefixed with: `#!`.

```C#
#! ignore("CE3091")    // compiler fn call
code_that_causes_CE3091
```

## Compile-time Reflection

All type information is available at compile time.

```C#
m = MyStruct
    ...

// this code is run at compile time
#! compTime(m: MyStruct)
    t = m#type
    t.name                      // 'MyStruct'
    loop f in t.fields
        "field: {f.name} of type {f.type.name}"

#! compTime(m)
compTime(m)     // error! `type` attr is not available
```
