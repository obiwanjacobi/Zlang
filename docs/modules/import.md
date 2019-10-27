# import

When the code in the file depends on code located in a different module, the `import` keyword can be used to declare the location of that dependency.

This import example indicates that the code uses one or more functions from the standard math library.

```C#
import std.math
```

Only one name can be specified at a time. Importing multiple dependencies requires multiple statements.

```C#
import std.io
import std.math
```

---

> How to deal with ambiguity/collisions of names. Aliases?
