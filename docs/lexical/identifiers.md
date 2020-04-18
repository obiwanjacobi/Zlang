# Identifiers

Identifiers name program entities such as variable, functions and types. These names must follow these rules:

- Cannot be empty.
- Cannot contain spaces.
- Cannot contain operator characters (+-/*).
- Cannot start with a digit.
-
- Can contain `_`.
- Can contain alpha-numeric characters.
- Valid characters lie in the ASCII range (no unicode).

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

## Case Sensitivity

Type identifiers start with an upper case letter. Variables and Function Parameters must have a lower case first letter. Function names can use either.

Identifiers are the same when:

- The first letter matches exactly (case sensitive)
- All other letters match (case insensitive)
- `_` are ignored (removed) when comparing.

### Discard

Using a discard `_` in an identifier is ignored during matching.

```csharp
My_Function(p: U8)
    ...

Myfunction(42)  // calls My_Function

//----

Myfunction(p: U8)
    ...

My_Function(42)  // calls Myfunction
```

When an identifier starts with a discard `_` it indicates the symbol is not used.

```csharp
myFn(_p: U8): U8    // param p not used
    ...
_a = myFn(42)       // return value named but not used

```

Or when it ends with an `_`? => Invalid?

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