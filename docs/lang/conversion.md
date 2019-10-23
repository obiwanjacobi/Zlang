# Type Conversion

## Built-in Types

The allowed conversions are all explicitly represented by a function. The name of the function is the target type.

```C#
b = 42        // U8
s = b.Str()   // to string "42"
```

Type conversion from larger to smaller types need some extra help:

```C#
v = 0x4242      // U16
b = v.U8()      // error: loss of data!
b = v.U8[8..15] // using a Range to extract the bits
```

Unchecked signed to unsigned or visa versa conversions boil down to the number of bits: can the target type contain all the bits of the original value - even though the meaning of those bits may change.

```C#
v = 0xFF        // U8: 255
i = v.I8()      // I8: -1
```

> _An additional set of 'checked' functions should do bounds checking to make sure that the actual value has not changed meaning._
