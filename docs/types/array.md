# Array

The array is a continuous sequence of elements. The structure of these elements are expressed in types. An array is always one-dimensional. It it possible to make arrays of arrays, thus simulating multi-dimensional arrays.

An array has a fixed size, determined at compile time that cannot be changed: the array cannot be made larger or smaller.

An immutable array is initialized once and its contents cannot be changed after that:

```C#
// immutable
arr = [1, 2, 3, 4, 5]               // 5 x U8
arr: Array<U16> = [1, 2, 3, 4, 5]   // 5 x U16

arr[0] = 42                     // error!
```

A mutable array has its size specified up front, but the contents of its elements can be changed dynamically in code.

```C#
// mutable
arr = Array<U8>([1, 2, 3, 4])   // 4 x U8
arr = Array<U8>(10)             // 10 x U8 (all 0)

arr[0] = 42                     // first element now has value 42
```

There are two ways to select array elements:

- By Index
- By Range

Using an index (zero-based, positive integer) pinpoints a single element. The type of this operation is the element type of the array. It can be used to read or write a single value (T).

Multiple array elements are selected when using [`Range`s](range.md). These too can be used to read a value from the array as well as write a value to to the array - if it is mutable.

The resulting type of a Range operation is a `Slice`. A slice is a view into the original array bounded by the range that created it. It is continuous and sequential, just like an array. Think of it as a subset.

A slice does not take up storage and therefor is not a real concrete type. It is a virtual and dynamic type that is implemented by the compiler. A slice takes on the type of the array it originated from.

Here's an example writing values to a mutable array:

```C#
arr = Array<U8>(10)         // 10 x U8
arr[3] = 42                 // set 4th element
arr[0..2] = 42              // slice: 1st, 2nd and 3rd
arr[..] = 0                 // slice: all set to zero
```

Reading values from an array is similar:

```C#
arr = [1, 2, 3, 4, 5]       // 5 x U8
x = arr[3]                  // x = 4
l = arr[-1]                 // l = 5
s = arr[0..2]               // s = 1st, 2nd and 3rd
arr2 = arr[..]              // arr2 = all elements (not a copy!)
```
