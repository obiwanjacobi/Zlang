# Functions

A function is a block of code that can be called from another function. The function can take parameters and optionally return a value of any type.

A function has a name that identifies it uniquely. See [Identifiers](../lexical/identifiers.md).

It is also distinguished by the use of parenthesis `()` when declared or called. Even when the function takes no arguments, the caller still uses the '()' to mark it as function.

```C#
MyFunction()        // function declaration
    fn_impl_here

...

MyFunction()        // function call
```

A more complex example would look like this:

```C#
repeat(count: U8, char: U8): Str
    fn_impl_here

...

s = repeat(42, 'X')
```

Typically the names of functions (and variables) can begin with either an upper or lower case letter. There is one exception when a function is used as a type: all type names start with an upper case letter.

## Pointer to a Function

This exception has to do with pointers to functions, for instance when a function is passed as a parameter to another function.

Here is an example of how to construct a pointer to a function. It is the same as getting a pointer to any 'object', but here the intrinsic `ptr` attribute is accessible on the type (function).

```C#
MyFunction(magic: U8)   // declaration
    ...

p = MyFunction#ptr      // p is of type Ptr<MyFunction>
takePtr(p, 42)          // call function with ptr to function

takePtr(ptr: Ptr<MyFunction>, p: U8)
   ptr(p)            // call the MyFunction through ptr
                     // passing in its 'magic' parameter
```

Any function that takes parameters that represent pointer to functions must specify its (function) type up front. This function type definition contains the signature of the number of parameters and their types as well as the return type - if any.

`#ptr` is different from taking a pointer from a variable with `.Ptr()` in that `#ptr` only works on a function type that is known at compile time, while `.Ptr()` takes the runtime address of a variable. See also [Pointer Types](./types.md).

When the code has a pointer to a function, it can be called by specifying the `()` straight after it. Any parameters the function that is pointed to requires, must be passed in at that time. The return value -if any- will be available when the function returns.

See also [Function Interfaces](interfaces.md).

## Parameters

There is no other way of passing parameters to functions than by value. That means, that the parameter value is copied from the caller site into the context of the function.

That also means that if a parameter is to be passed by reference, an explicit pointer to that value has to be constructed and passed to the function.

```C#
byref(ptr: Ptr<U8>)     // pointer as by-ref parameter
    ...

v = 42
byref(v.Ptr())            // call with ptr to value
```

Optional function parameters can be specified using the optional symbol `?`.

```C#
hasParam(p: U8?): Bool
    return p ? true : false
```

Default value for a function parameter:

```C#
defFunc(p: U8 = 0)
    ...

defFunc();          // ok, default value is used
defFunc(42);        // ok, default value overridden

defFunc(p: U8 = 0, p2: U16)     // error! default must be last
    ...
```

Named Parameter use:

```C#
namedFn(p: U8, p2: U16)
    ...

namedFn(p = 42, p2 = 0x4242)    // ok, both named
namedFn(p2 = 0x4242, p = 42)    // ok, out oif order, but named
namedFn(42, p2 = 0x4242)        // ok, p in order, rest named
namedFn(0x4242, p = 42)         // error! cannot convert 1st to U8

```

Variable number of parameters:

Not really supported but can fake with Array: all of same type.

```C#
varFunc<T>(p: U8, varP: Array<T>)
    ...

// requires (easy) syntax for specifying
varFunc(42, [1, 2, 3, 4, 5, 6])
```

## Return values

Returning multiple values from a function is only possible using a (custom) structure type. There are no out parameters and no tuples.

```C#
MyStruct
    field1: U8
    field2: U16

MyFunc(p: U8, p2: U16): MyStruct
    return Mystruct
        field1 = p
        field2 = p2
```

Return values are also passed by value, so in the example above, two values (U8 and U16) would be copied to the caller.

> TBD: Force caller to handle return value (just like with Error)?

```C#
retFunc(): Bool
    ...

b = retFunc()       // ok, retval caught
retFunc()           // warning? uncaught retval

_ = retFunc()       // ok, explicitly not interested in retval
```

## Type Bound (Self)

Using the `self` keyword on the first parameter, a function can be bound to a type. In this example the function is bound to the MyStruct type.

```C#
jamesBond(self s: MyStruct)
    ...

s = MyStruct
    ...

s.jamesBond()
jamesBond(s)
```

When calling a bound function, the 'self' parameter can be used as an 'object' using a dot-notation or simply passed as a first parameter.

> TBD: `self` could be the (reserved) name of the first parameter.

---

> TDB:

support recursion?

resolving overloads (only type bound?)

pure functions (functional) / higher order functions?

coroutines (yield/return) (impl. detail of the fn)

anonymous functions/lambda/in-place syntax (no capture)

simulate properties? thru type-bound functions?
Get\<T>/Set\<T>/Notify\<T>/Watch\<T[]>

intrinsic functions (operator implementations)

inlining (compiler)
