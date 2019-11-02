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

```js
1Function
some variable
my-type
```

## Fully Qualified Names

```
MyModule.v2.MyFunction
```
