# Identifiers

Identifiers name program entities such as variable, functions and types. These names must follow these rules:

- Cannot be empty.
- Cannot contain spaces.
- Cannot contain operator characters (+-/*).
- Cannot start with a digit.
-
- Can start with `_` (but this has special meaning).
- Can contain alpha-numeric characters.

Here are examples of valid identifiers:

```C#
My_Function1
someVariable
_unused
```

Here are examples of _invalid_ identifiers:

```C#
1Function
some variable
my-type
```

## Fully Qualified Names

```C#
MyModule.v2.MyFunction
```

> Do we want to distinguish between namespace separators and obj.fn() calls?

```C#
// namespace / module name (also for import, export aliases)
MyModule::v2::MyFunction

// function call
obj.MyFunction(42)
```

Only needed when function call may include namespace/module parts...