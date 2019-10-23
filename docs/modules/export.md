# export

By default all code in a file is private to that file. One could think of it as being inside an anonymous namespace.

The `export` keyword publishes the code identified by the name to be used by other code files / modules.

The following types of identifiers can be exported:

- Types
- Functions

> Variables cannot be exported! They need an accessor function.

Here is an example of exporting a function:

```C#
export MyFunction

MyFunction()
    implementation_here
```

The `export` keyword can also be applied directly to the code identifier to be made publically available:

```C#
export MyFunction()
    implementation_here
```
