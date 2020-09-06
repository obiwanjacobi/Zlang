# Templates

Templates are processed at compile time.

## Template Structures

```C#
MyStruct<T>
    f: T

s = MyStruct<U8>
```

> This should also work:

```C#
MyStruct<T>: T
    ...

s = MyStruct<OtherStruct>
```

## Template Functions

```C#
typedFn: <T>(p: T)
    ...

// type inferred and checked
typedFn(42)

// type explicit
typedFn<U8>(42)
// new forms of casting?
typedFn(42: U8)
typedFn(x: U8)

// return values
typedRet: <T>(): T
    ...

x = typedRet<U8>()
x = typedRet(): U8
y: U8 = typedRet()  // type forwarding?
z = typedRet()      // Error! cannot determine type
```

## Restricting Template Type Parameters

```C#
MyStruct
    ...
OtherStruct: MyStruct       // derive from MyStruct
    ...

typedFn: <T: MyStruct>(p: T)  // accept type (derived from) MyStruct
    ...

o = OtherStruct             // instantiate
    ...

typedFn(o)                  // type inferred and checked
typedFn<MyStruct>(o)        // base type explicit
typedFn<OtherStruct>(o)     // derived type explicit
```

Restricting the allowed types by using a constrained variant.

```csharp
Choice: U8 or U16 or U24
tfn: <T: Choice>(p: T): U8
    ...

a = tfn(42)     // ok, U8
a = tfn("42")   // error, Str not in Choice
```

### Non-Type Type parameters

```C#
// non-type template params?
FixedArray<T, count: U8>
    arr: Array<T>(count)
// use type params?
FixedArray<T>(count: U8)    // hard to distinguish from function
    arr: Array<T>(count)

// restricting on metadata?
// Type rules? See Custom Data Types
TemplateType<T#bits=8>  // '=' conflicts with parameter default
    field: T
```

## Template Parameter Defaults

```C#
TemplateType<T=U8>
    field1: T

t = TemplateType
    field1 = 42         // U8
```

## Template Specialization

```C#
typedFn: <T>(p: T)
    ...
typedFn: <Bool>(p: Bool)  // how do we know this is a specialization of typedFn<T>? By name and function type.
    ...

typedFn(42)         // generic typedFn<T> called
typedFn(true)       // specialization typedFn<Bool> called
```

---

> TBD

Allow for multiple levels of type params?

```csharp
MyType<M<T>>    // requires M to have one T
    ...         // use M and T?
```
