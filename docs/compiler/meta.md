# Meta Programming

> TBD allow to write Z# code that executes at compile time in order to shift the workload as much as possible to compiler.

## Intrinsic Attributes

The compiler will allow accessing intrinsic attributes of the compiled code. These attributes are constants whose value was determined by the compiler at compile time and they do not take up any storage in the program.

A special operator is used to access them: `#`

| Attribute | Description
|----|-----
| `#type` | Full type info.
| `#typeid` | A unique numerical type identifier.
| `#name` | The identifier (name).
| `#min` | The minimum value possible.
| `#max` | The maximum value possible.
| `#bits` | The number of bits for the type.
| `#count` | The number of elements.
| `#size` | The size in bytes the type takes up in memory.
| `#default` | Default value for the type.
| `#ptr` | Pointer to a (function) type.
| `#imm` | Make immutable.

> `#typeid` is a U16 hash value over the module name and type name.

> `#type` is only available in a compile-time function that is tagged with a `#!`.

_`#imm` is still under debate. Another option would be to use a template type `Imm<T>`._

Not all types support all attributes. The compiler will give an error when the code accesses an attribute that is not supported by the type in question.

```C#
a = 42      // U8
a#size      // 1
a#bits      // 8
a#min       // 0
a#max       // 255
a#ptr       // error! use .Ptr() on instances
a#name      // 'a'

U8#size     // 1
U8#bits     // 8
U8#min      // 0
U8#max      // 255
U8#ptr      // error! not on this type
U8#name     // 'U8'

Bit<3>#size // 1
Bit<3>#bits // 3
Bit<3>#min  // 0
Bit<3>#max  // 7
Bit<3>#name // 'Bit3'

MyFunction()
    ...
MyFunction#ptr  // ok, ptr to function
```

## Pragmas

A pragma is a directive that instructs the compiler to take some action. For instance turn off a compiler warning temporarily.

A pragma is prefixed with: `#` that starts at the indent level of the current scope. It also starts a new scope.

```C#
# ignore("CE3091")    // compiler fn call - starts a scope!
    code_that_causes_CE3091
    more_code_that_causes_CE3091
well_behaved_code
```

> A `#` symbol not at the current scope indent position, does not start a new scope.

> TBD: A file level scope 'options' pragma that executes all pragmas for that file.

```C#
# options()
    enable(Checks.Bounds)
    enable(Checks.Overflow)

...     // rest of code file
```

## Compile-Time Code

_Any_ Z# code can be executed at compile-time. By placing a `#!` in front of it, the compiler knows it is not to be included in the binary. The use of this symbol does not introduce an extra scope.

```C#
m = MyStruct
    ...

// this code is run at compile time
#! compTime<T>(m: T)
    t = m#type
    t.name                      // 'MyStruct'
    loop f in t.fields
        "field: {f.name} of type {f.type.name}"

#! compTime(m)
compTime(m)     // error! `#type` attr is not available
```

Some `#` compiler attributes may require the code to be `#!` compile time code.

```C#
anyFunc<T>(m: T)    // normal function
    ...

#! anyFunc(m)       // called/run at compile time
anyFunc(m)          // called/run at run time
```
