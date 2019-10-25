# Array

The array is a continuous sequence of elements. The structure of these elements are expressed in types.

immutable - mutable
static size - dynamic size
stack - heap

A static array has a fixed size, determined at compile time and can not change size. The array cannot be made larger or smaller.

A constant static array is initialized once and immutable after that:

```C#
arr = [1, 2, 3, 4, 5, 6, 7]     // array of U8 elements
```

```C#
arr: Array<U8>          // empty array of U8 elements
arr: Array<U8>(10)      // array of 10 elements of type U8
```
