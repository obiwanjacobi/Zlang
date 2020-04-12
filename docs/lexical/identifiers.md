# Identifiers

Identifiers name program entities such as variable, functions and types. These names must follow these rules:

- Cannot be empty.
- Cannot contain spaces.
- Cannot contain operator characters (+-/*).
- Cannot start with a digit.
-
- Can start with `_` (but this has special meaning).
- Can contain alpha-numeric characters.
- Are case sensitive.

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

## Case Sensitivty

Type identifiers start with an upper case letter. Variables and Function Parameters must have a lower case first letter. Function names can use either.

> Are identifier defenition and reference matched case sensitive? (full name, or just the first letter match?)

## Discard

Using a discard `_` in an identifier is ignored during matching.

```csharp
My_Function(p: U8)
    ...

MyFunction(42)  // calls My_Function

//----

MyFunction(p: U8)
    ...

My_Function(42)  // calls MyFunction
```

> When an identifier starts with a discard `_` ...?

```csharp
_myFn(p: U8)
    ...
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