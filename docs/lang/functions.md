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

This exception has to do with pointers to functions, for instance when a function is passed as a parameter to another function.

Here is an example of how to construct a pointer to a function. It is the same as getting a pointer to any 'object', but here the intrinsic `ptr` attribute is accessible on the type (function).

```C#
MyFunction(magic: U8)        // declaration
    ...

p = MyFunction#ptr  // p is of type Ptr<MyFunction>
takePtr(p, 42)          // call function with ptr to function

takePtr(ptr: Ptr<MyFunction>, p: U8)
   ptr(p)            // call the MyFunction through ptr
                     // passing in its 'magic' parameter
```

Any function that takes parameters that represent pointer to functions must specify its (function) type up front. This function type definition contains the signature of the number of parameters and their types as well as the return type - if any.

See also [Function Interfaces](interfaces.md).

When the code has a pointer to a function, it can be call by specifying the `()` straight after it. Any parameters the function that is pointed to requires, must be passed in at that time. The return value -if any- will be available when the function returns.

---

parameters (in/out/ref) and return values (structs/tupples?)

support recursion?

type-bonded (extension) / creators and pure functions

resolving overloads (only type bonded?)

coroutines (yield/return) (impl. detail of the fn)

anonymous functions/lambda/in-place (no capture)

intrinsic functions (operator implementations)

inlining (compiler)
