# Enums

Enums are groups of values that belong together.
An enum is basically a value type that has its possible values predefined.

As with all type names, the name of the enum type has to start with a capital letter. The enum declaration looks very much like the declaration of a structure, but the use of comma's make it an enum.

Here is an intuative declaration of an enum type.

```C#
MyEnum
    opt1, opt2, opt3
```

Because the values were not specifically listed, they are assigned by the compiler and start at 0 (zero) in order of declaration.
So `opt1` would be 0, `opt2` would be 1 and `opt3` would be 2. You can assign these values specifically.

```C#
MyEnum
    opt1 = 0,
    opt2 = 10,
    opt3 = 20,    // trailing comma is ok
```

The type of the enum in the previous example is defaulted to `U8`. But you can be explicit about it and / or choose a different type.

Here is how that would look:

```C#
MyBigEnum: U16
    flag = 0x8000
    mask = 0x00F0
```

> Flags are just enums where the value is carefully controlled.

You can even specify a string:

```C#
StrEnum: Str
    Low = "Low",
    Mid = "Mid",
    High = "High",
```

Each option has a string value. Also note that the option names may also begin with a capital letter.

When using an enum, the type name has to be specified too:

```C#
MyEnum
    opt1, opt2, opt3

e = MyEnum.opt1
```

The data type of an enum option is the enum type itself. So `e` in the example above is of type `MyEnum` with a value of `0` (zero).
