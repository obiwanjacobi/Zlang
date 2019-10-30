# Optional Values

There is no null in Z#. There is a syntax to structure the case where a value may not be available. The `?` is used on the type to indicate this.

```C#
// optional
valueMaybe(): U8?       // ? for optional, ! for error
    return              // to return nothing
    return 42           // to return a value

// fallback when there is no value
var = valueMaybe() || 42
```

Optional fields in structs:

```C#
MyStruct
    field1: U8
    field2: Str?


```
