# Types

## Built-in data types

The built-in data type form the basic building blocks for creating structures.

> **_All type names start with a capital letter_**

There are builkt-in types for integers, floating point, string and boolean.

### Integers

The type names have been shortened to an absolute minimum. First:

- U - unsigened integer
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
