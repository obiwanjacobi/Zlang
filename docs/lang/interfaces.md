# Interfaces

Interfaces are the means to polymorphism.

only functions.

Function interfaces - a template for a singe function. Usually used as a callback or delegate. When used compatibility of candidate function is determined by type comparison. The function name is irrelevant.

Object interfaces - a template for one or more functions. Usually used as a means to polymorphism.

Function interfaces are syntactically different from Object interfaces - so an object interface with one function cannot be mixed up/interchanged with a function interface.

---

A function interface declares only one function and does _not_ use the `self` keyword.

> Do we need the 'FunctionInterface' name? How to declare a variable of type FunctionInterface if there is no 'FunctionInterface' name?

```C#
FunctionInterface
    lowByte(p1: U16): U8    // can we detect this?
        _                   // or need no impl
    lowByte(p1: U16): U8 _  // no impl, but shorter
```

An object interface can declare one or more functions. It must have the `self` keyword as a first parameter.

```C#
ObjectInterface
    lowByte(self, p1: U16): U8 _
    hiByte(self, p1: U16): U8 _
```

> How to implement an interface

```C#
// declare
MyStruct
    ...

MyInterface
    interfunc(self, p: U8) _

// function must match exactly
interfunc(self s: MyStruct, p: U8)
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

> override / 'virtual' ?? call 'super' ??

---

> TBD: Matching interfaces onto type bound functions.