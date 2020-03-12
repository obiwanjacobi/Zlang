# Functions

A function is a block of code that can be called from another function. The function can take parameters and optionally return a value of any type.

A function has a name that identifies it uniquely. See [Identifiers](../lexical/identifiers.md).

It is also distinguished by the use of parenthesis `()` when declared or called. Even when the function takes no arguments, the caller still uses the '()' to mark it as function.

```C#
MyFunction()        // function declaration
    fn_impl_here

MyFunction()        // function call
```

A more complex example would look like this:

```C#
repeat(count: U8, char: U8): Str
    fn_impl_here

s = repeat(42, 'X')
```

Typically the names of functions (and variables) can begin with either an upper or lower case letter. There is one exception when a function is used as a type: all type names start with an upper case letter.

## Pointer to a Function

> I probably gonna do this differently. Make functions lower case and use a Function Interface (declaration) to have the type. Seems more consistent and concise. Does bring up an issue when auto initializing a ptr-to-a-function variable though: What would be the type of ptr? `ptr = myFunction`. Can we go look for suitable types that match the declaration of the specified function? Do we generate an anonymous function type?

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

> I want to ditch `#ptr` because just using the function name is easier and more intuitive.

When the code has a pointer to a function, it can be called by specifying the `()` straight after it. Any parameters the function that is pointed to requires, must be passed in at that time. The return value -if any- will be available when the function returns.

A function without implementation is called a function declaration or [Function Interfaces](interfaces.md).

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

> Having doubts about this for it allows overloading that is not explicit.

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
namedFn(p2 = 0x4242, p = 42)    // ok, out of order, but named
namedFn(42, p2 = 0x4242)        // ok, p in order, rest named
namedFn(0x4242, p = 42)         // error! cannot convert 1st to U8

```

Variable number of parameters:

Not really supported but can fake with Array: all of same type. We don't have an 'object' type that is the basis of all.

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

> Compiler will check if a ptr is returned, it is not pointing at a stack variable.

Return values are also passed by value, so in the example above, two values (U8 and U16) would be copied to the caller.

The caller has to handle the return value (just like with Error). There is a syntax to explicitly ignore the return value.

```C#
retFunc(): Bool
    ...

b = retFunc()       // ok, retval caught
retFunc()           // error! uncaught retval

_ = retFunc()       // ok, explicitly not interested in retval
```

These is a language syntax compiler option to turn this feature on or off.

## Type Bound (Self)

Using the `self` keyword on the (name of the) first parameter, a function can be bound to a type. In this example the function is bound to the MyStruct type.

```C#
jamesBond(self: Ptr<MyStruct>)
    ...

s = MyStruct
    ...

s.jamesBond()
jamesBond(s)
```

When calling a bound function, the 'self' parameter can be used as an 'object' using a dot-notation or simply passed as a first parameter. Normal function rules apply, so for a struct it is usually a good idea to declare a `Ptr<T>` in order to avoid copying and be able to change the fields of the structure. Matching type-bound functions to their types is done as follows:

|Var Type | Self Type | Self Type Note
|---|---|---
| T | T or Ptr\<T> | Either can be Imm\<T>
| T? | T? or Ptr\<T?> | Either can be Imm\<T>
| Ptr\<T> | T or Ptr\<T> | Either can be Imm\<T>
| Imm\<T> | Imm\<T> or Ptr<Imm<\<T>>>

> This means implicit conversions => something we don't want?

Any type can be used, for instance Enum types:

```C#
isMagicValue(self: MyEnum): Bool
    return self = 42

e = MyEnum.MagicValue

b = e.IsMagicValue()        // true
```

## Function Overrides

When resolving target functions the most specific function is chosen at compile time. This means that of the multiple function candidates the function is chosen that has parameter and return types that are most specific and closest to the types used at the call site.

> TODO: Example

> At compile time => means no runtime dispatch based on `self` type!?

## Local Functions

A local function is a function that is defined inside another function and is local to that scope - it cannot be used (seen) outside the function its defined in.

In other aspects they are no different from other functions.

```C#
MyFunc(): U8
    LocalFun(p: U8): U8
        return p << 1;

    return LocalFun(42)
```

> Not sure if local variables of the containing function can be captured in the local function...

## Fluent Functions

Fluent functions are possible with type-bound functions that return self or another types where another set of bound function is available for.

```C#
FnState1
    ...
FnState2
    ...

add(self: FnState1, v: U8): FnState2
    ...
build(self: FnState2): Array<U8>
    ...

s = FnState1        // instantiate root struct
    ...

arr = s.Add(42)     // chained calls can be spread over multiple lines
// split before . and use 2 indents (next indent + 1)
        .Build()
```

```C#
is(someVar).biggerThan(42)
does<SomeType>().implement<SomeInterface>()
can<SomeType>().BeCastedTo<DiffType>()
does<SomeType>().implementMethod(MethodName)
```

> Allow by default using the 'fluent' self object if no return type?

```csharp
add(self: Calc, v: U8)
sub(self: Calc, v: U8)

c = Calc
// only works with dot-syntax
c.add(4).sub(2)
// with scope?
c.add(4)
    .sub(2)
```

> Auto-Fluent syntax? `Build(p: MyStruct)::Into(target: Stream)`

## Function Overloads

Function overloading means that there are multiple functions with the same name but different parameter (or return) types.

Function overloading will work regardless if the function uses a self parameter or not.

```C#
sameName(p: U8)
    ...
sameName(p: Str)
    ...

sameName(42)
sameName("42")

sameName(x: Str)    // error! already defined
    ...
```

An overloaded type bound function with a self parameter:

```C#
overloadFn(self: U8, p: U8)
    ...
overloadFn(self: U8, p: Str)
    ...

v = 42
v.overloadFn(42)
v.overloadFn("42")
```

Overload a function by the number of parameters.

```C#
overload(p1: U8)
    ...
overload(p1: U8, p2: U8)
    ...
overload(p1: U8, p2: U8, p3: U8)
    ...

overload(42)            // #1
overload(42, 42)        // #2
overload(42, 42, 42)    // #3
```

When resolving overloads the types of the function parameters are used to determine what function to call. Conversion functions can be used to direct resolving the targeted function.

### Double Dispatch / Visitor Pattern

A demonstration on function overloading and resolving them: does the visitor pattern work?

```C#
// declare data structure to visit
MyStruct1
    ...
MyStruct2
    ...
MyStruct
    field1: MyStruct1
    field2: MyStruct2

// instantiate data structure to visit
s = MyStruct
    ...

// declare visitor struct
Visitor
    ...

// instantiate visitor struct
v = Visitor
    ...

// 2 visit functions for different data structs
// these functions could also be on an interface
visit(self: Visitor, p: MyStruct1)
    ...
visit(self: Visitor, p: MyStruct2)
    ...

// accept a visitor
accept(self: MyStruct, v: Visitor)
    v.visit(field1)
    v.visit(field2)

```

## Coroutines

Coroutines are functions that execute in parts. A different part is executed each time the function is called.

The `yield` keyword indicates that a part in the function code has finished and the function should be exited. When the function is called next, execution will begin right after the yield statement that exited it last time.

The `return` keyword works as normal and also resets the state of the coroutine. The next call to the function will start from the beginning.

There are three types of coroutines in respect to the function return value.

```C#
// multiple calls, no result
coroutine(p: U8)
    yield
    yield
    yield
    return

// multiple calls, one result
coroutine(p: U8): U16?
    yield _
    yield _
    yield _
    return p << 12

// multiple calls each with result
coroutine(p: U8): Iter<U16>
    yield p
    yield p << 4
    yield p << 8
    return p << 12
```

> Coroutine state is kept in hidden param? (has to be caller context specific)

```C#
coroutine(p: U8) // hidden coroutine state param?
coroutine(state, p: U8) // explicit coroutine state param?
coroutine(self, state, p: U8) // with self?

i = 42
s1 = 0           // (hidden) coroutine call state at root-scope
loop [0..3]
    coroutine(i, s1.Ptr())     // ref, yield/return updates state
    i = i + 2

// multiple coroutines
s1 = 0
s2 = 0
loop [0..3]
    coroutine(42, s1.Ptr())
    otherCoroutine(42, s2.Ptr())
```

---

> TDB:

support recursion? Let compiler check for exit condition.

pure functions (functional) / higher order functions?

anonymous functions/lambda/in-place syntax (no capture)

```C#
arr.ForEach(callback)             // fn ptr
arr.ForEach(i => action(i, 42))   // like match, but different
```

simulate properties? thru type-bound functions?
Get\<T>/Set\<T>/Notify\<T>/Watch\<T[]>

tag interrupt service routines (for analysis - volatile) as a simplified interface?
functions that do not return?

intrinsic functions (operator implementations) - extensions?

inlining (compiler)
