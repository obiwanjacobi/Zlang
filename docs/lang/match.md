# Match

The `match` expression tries to select the first pattern that matches the specified operand.

Here are some examples of patterns that can be used:

```C#
v = 42
x = 24

a = match v
    0 =>        // by literal numerical value
    "" =>       // by literal string value
    x =>        // by variable value
    n: U8 =>    // by type (with casted var)
    s: MyStruct ? s.fld1 = 20 =>  // by type with filter
    _ =>        // default (ignore) case
```

The syntax continues after the `=>` which contains the result of the expression when that specific pattern matched.

This example results in `"The Answer"` based on the string `"42"`:

```C#
s = "42"

a = match s
    "" => "Empty"
    "0" => "Zero"
    "42" => "The Answer"    // this pattern will be chosen
    _ => ""

// a = "The Answer
```

When more comprehensive logic is required to compute the result a function can be called to yield that result.

Here an example on matching a type pattern with multiple pattern for the same type - but different filters.

```C#
s = MyStruct
    field1 = 12

a = match s
    n: U8 => make42(n)
    x: MyStruct ? x.field1 = 12 => 42
    x: MyStruct => 0

// a = 42
```

The two patterns for `MyStruct` differ in filter. That is why this works.

> The compiler checks if later patterns are still reachable.

Patterns for values and patterns for types can be used at the same time. Type matching is done base on the underlying `#typeid`.

> TBD: How will the compiler be able to assess if a pattern will be reachable?

> TBD: more support for expressions? Like returning an expression from a scope (no return statement needed)? A loop that results in a value (break 42)??
