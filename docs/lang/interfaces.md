# Interfaces

Interfaces are the means to polymorphism without using objects (in an OOP sense).

## Function Interface

Function interfaces are a prototype for a singe function. Usually used as a callback or delegate.

A function interface declares only one function and does _not_ use the `self` keyword.

```C#
FunctionInterface (p1: U16): U8 _

callFn(ptrFn: Ptr<FunctionInterface>): U8
    return ptrFn(0x4242)
```

The function interface is simply a function declaration. It ends with a `_` to indicate it is not a function definition and contains no implementation.

Function interfaces are syntactically different from Object interfaces - so an object interface with one function cannot be mixed up/interchanged with a function interface.

## Object Interface

Object interfaces are a template for one or more functions. Usually used as a means to polymorphism.

An object interface can declare one or more functions. It must have the `self` keyword as a first parameter.

```C#
ObjectInterface
    lowByte(self, p1: U16): U8 _
    hiByte(self, p1: U16): U8 _
```

An object interface template:

```C#
TemplateInterface<T>
    lowByte(self, p1: U16): T _
    hiByte(self, p1: U16): T _

// recommended way to restrict self
MyStruct
    ...
RestrictedInterface<T: MyStruct>
    lowByte(self: T, p1: U16): U8 _
    hiByte(self: T, p1: U16): U8 _
// The interface can only be implemented on MyStruct (or derived) types.

CompanionInterface<T: TemplateInterface>
    fn(self: T, p1: U8): Str _
// The interface can only be implemented on types that also implement TemplateInterface (with any T).
```

How to implement an interface:

```C#
// define
MyStruct
    ...

MyInterface
    interfunc(self, p: U8) _

// function must match exactly
interfunc(self: MyStruct, p: U8)
    ...

// make struct instance
s = MyStruct
    ...

// will check if MyStruct has implemented all interface functions
a: MyInterface = s

// call (both the same)
a.interfunc(42)         // because 'self'
interfunc(a, 42)
```

The interface implementation functions are matched based on the function name, parameter types and its return type. The `self` parameter may be derived other types must match exactly.
