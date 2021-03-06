# Interfaces

Interfaces are the means to polymorphism without using objects (in an OOP sense).

## Function Interface

Function interfaces are a prototype for a singe function. Usually used as a callback or delegate.

A function interface declares only one function and does _not_ use the `self` keyword.

```C#
FunctionInterface: (p1: U16): U8 _

callFn(ptrFn: Ptr<FunctionInterface>): U8
    return ptrFn(0x4242)

fnImpl: FunctionInterface
// may repeat declaration for readability
fnImpl: FunctionInterface (p1: U16): U8
    return p1.U8([4..12])

r = callFn(fnImpl)      // r = 0x24
```

The function interface is simply a function declaration. It ends with a `_` to indicate it is not a function definition and contains no implementation.

Function interfaces are syntactically different from Object interfaces - so an object interface with one function cannot be mixed up/interchanged with a function interface.

## Object Interface

Object interfaces are a template for one or more functions. Usually used as a means to polymorphism.

An object interface can declare one or more functions. It must have the `self` keyword as a first parameter.

```C#
ObjectInterface<S>
    lowByte: (self: S, p1: U16): U8 _
    hiByte: (self: S, p1: U16): U8 _
```

The Type of `self` is set as a template parameter, for it is not known (or fixed) at this point.

Also note that there is no implementation `_`.

An interface can have more template parameters however:

```C#
TemplateInterface<S, T>
    lowByte: (self: S, p1: U16): T _
    hiByte: (self: S, p1: U16): T _
```

Normal template parameter restrictions can be applied:

```csharp
// recommended way to restrict self
MyStruct
    ...
RestrictedInterface<S: MyStruct>
    lowByte: (self: S, p1: U16): U8 _
    hiByte: (self: S, p1: U16): U8 _
// The interface can only be implemented on MyStruct (or derived) types.

CompanionInterface<S: TemplateInterface>
    fn: (self: S, p1: U8): Str _
// The interface can only be implemented on types that also implement TemplateInterface (with any T).
```

How to implement an interface:

```C#
MyInterface<S>
    interfunc: (self: S, p: U8) _

MyStruct
    ...
// function name must match and template parameters must satisfy restrictions (none here)
interfunc: (self: MyStruct, p: U8)
    ...

// make struct instance
s = MyStruct
    ...

// will check if all interface functions are implemented for MyStruct
// it is a 'pointer' to the interface
a: MyInterface = s

// call (both the same)
a.interfunc(42)         // because 'self'
interfunc(a, 42)
```

The interface implementation functions are matched based on the function name, template parameters, function parameter types and its return type. The `self` parameter type may be derived from other types but must match exactly.

A compile time error is generated when the compiler detects that an interface is not fully implemented for a specific type of `self`.

---

> How to determine at runtime if an 'object' implements a specific interface?

The compiler has to check if the specified `self` type has implementation for all the functions of the interface.

```csharp
MyInterface<S>
    interfunc: (self: S, p: U8) _

s: Struct
    ...

// use interface type name as cast/convert? (retval: Opt<T>)
i = s.MyInterface<Struct>() // s => self AND <T> (Struct) !
i = s.MyInterface()         // s => self (infer T=Struct)

// use builtin functions?
b = s.Is<MyInterface<Struct>>()     // retval: Bool
i = s.As<MyInterface<Struct>>()     // cast/convert (Opt<T>)

// use some kind of operator as cast/convert?
i = s &= MyInterface<Struct>
b = s ?= MyInterface<Struct>    // retval: Bool

// use some kind of intrinsic/pragma?
b = s?#MyInterface<Struct>  // similar to check if field exists
```

---

> TBD: Anonymous interface implementations?

This is more a template thing than an interface problem...

```csharp
// interface
PropGetFn: <S>(self: S): Str
    return self.Name

// anonymous struct
s = { Name = "MyName" }
p = PropGetFn(s)
```

See also [Anonymous Structures](structures.md#Anonymous-Structures).
