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

In a sense, the module name is also the name-space of the code in the file.
