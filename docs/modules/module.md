# module

The `module` keyword attaches the code in the file to a named (logical) unit. This name is also used with [`import`](import.md).

```C#
module math
```

The name may contain a few special characters: `.` and `_` .
This is a valid module name:

```C#
module myproject.Custom_String1
```

In a sense, the module name is also the namespace of the code in the file.

> Packaging libraries is not part of the language but a function of the compiler.

---

Should the module statements `module` and `import` only be used at the top of the file, or can they appear anywhere?
