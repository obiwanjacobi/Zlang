# Whitespace

Unlike most languages, whitespace matters in Z#. Similar to Python and F#.

## Spaces and Tabs

Spaces are used to separate code elements in order to make them distinct.

`iftrue` does not mean anything, while `if true` represents an `if` statement with a condition (`true`). The space separates the parts and makes them meaningful.

Tabs are used to indent code and signal scope (see Indentation).

> Set your editor to use tabs and not spaces.

## Indentation

Z# uses whitespace -indents- to signal scope. Where a lot of languages use `{}` to declare a scope, Z# attempts to minimize noise and do away with those characters.

**An _`indent`_ is represented by a single tab character.**

_As the parser evolves any number of spaces is expected to be valid in the future._

The start of the line represents the root scope. An `indent` is always placed below a statement or instruction that belongs to a higher scope (one up).

A simple example of a function and its implementation:

```C#
MyFuncion()
    implementation_here
    more_code_here
```

The function is at root scope and all of its implementation is one indent removed from that origin.

These scopes can of course be nested.

Here is an example of a function with nested scopes.

```C#
MyFuncion()
    if true
        conditional_code_here
    implementation_here
```

The 'conditional code' is only executed if the `if` branch is taken. The 'implementation' is always executed.

## Scope Names

Names for the indentation levels that create scopes:

```C#
global-scope
<File>
    top-level (file-scope)

    <Function>
        function-scope

    <Type>
        type-scope
```
