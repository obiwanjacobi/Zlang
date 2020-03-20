# Conditional Compilation

How?

Direct compiler by calling funcs? (just like pragmas)

Conditional code attribute?

Steering value can be specified on compiler command line.
Can make steering values in code but have to be known at compile time.

```C#
if comptimeValue
    code compiled if comptimeValue is true
else
    code eliminated - excluded by compiler
```

When condition of an `if` statement is known at compile time, the compiler knows which branch to keep and what to throw away.
