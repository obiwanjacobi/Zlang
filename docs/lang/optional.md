# Optional Values

There is no null in Z#. There is a syntax to structure the case where a value may not be available. The `?` is used on the type to indicate this.

```C#
// optional
valueMaybe(): U8?       // ? for optional, ! for error
    return _            // to return nothing
    return 42           // to return a value

// fallback when there is no value
var = valueMaybe() || 42

// optional can be used in a logical expression
if var
    use(var)
else
    // no var value
```

It is a compiler error if you use (dereference) an optional without checking. You can pass an optional value to an optional function parameter without problems.

Optional function parameters:

```C#
hasParam(p: U8?): Bool
    return p ? true : false
```

There is no implicit conversions in Z#. So p cannot be implicitly converted to a Bool value and therefor `return p` is invalid.

Optional fields in structs:

```C#
MyStruct
    f1: U8
    f2: Str?

s = MyStruct
    f1 = 42,    // not optional, must have a value
    f2 = _      // no value
```

```C#
MyStruct
    f1: MyStruct?   // data recursion only allowed when optional
    f2: U8          // actual payload

s = MyStruct
    f1 = ...

o = s.f1?.f1?.f2  // first non-value optional will stop navigation of path, result in _
```
