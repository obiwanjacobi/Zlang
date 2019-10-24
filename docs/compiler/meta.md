# Meta Programming

> TBD allow to write code and logic that executes at compile time in order to shift the workload as much as possible to compiler.

## Intrinsic Attributes

The compiler will allow accessing intrinsic attributes of the compiled code. These attributes are constants whose value was determined by the compiler at compile time and they do not take up any storage in the program.

A special operator is used to access them: `!`

| Attribute | Description
|----|-----
| min | The minimum value possible.
| max | The maximum value possible.
| bits | The number of bits for the type.
| count | The number of elements.
| size | The size in bytes the type takes up in memory.
| ptr | A ptr to the instance of the type.
| dup | A deep copy (duplicate) of the instance.

```C#
a = 42      // U8
a!size      // 1
a!bits      // 8
a!min       // 0
a!max       // 255
p = a!ptr   // p points to a
q = p!dup   // q points to a
```

## Pragmas

A pragma is a directive that instructs the compiler to take some action.
For instance turn off a compiler warning temporarily.

A pragma is prefixed with: `#!`.

```C#
#! ignore: CE3091    // describe the error
code_that_causes_CE3091
```
