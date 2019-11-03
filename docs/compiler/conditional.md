# Conditional Compilation

How?

Direct compiler by calling funcs? (just like pragmas)

Conditional code attribute?

Steering value have to be specified on compiler command line.
Cannot make steering values in code?

```C#
#if value
    code compiled if value is defined
#else
    code compiled if value is not defined
#endif
```
