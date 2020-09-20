# Templates

Templates are processed at compile time. A template has one or more template parameters inside `< >`.

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

## Template Parameters

Template parameters are applied at compile time. A parameter name _MUST_ be capitalized when it is used as a Type.

### Restricting Template Parameters

You might want to use a template with type restriction instead of a normal functions or struct with just the type, in order to keep the specific type without having to cast. For instance in case of a function return type or a structure field.

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

Restricting the allowed types for a template parameter by using a constrained variant.

```csharp
Choice: U8 or U16 or U24
tfn: <T: Choice>(p: T): U8
    ...

a = tfn(42)     // ok, U8
a = tfn("42")   // error, Str not in Choice
```

Restrict the template parameter based on metadata.

```csharp
// restricting on metadata?
// Type rules? See Custom Data Types
TemplateType<T#bits=8>  // '=' conflicts with parameter default
    field: T
```

### Non-Type Template Parameters

Although template parameters are usually types, it can be anything.

```C#
// non-type template params
FixedArray<T, count: U8>
    arr: Array<T>(count)
```

### Template Parameter Defaults

As with function parameters, template parameters can be set to a default value that can be overridden at the 'call site'.

```C#
TemplateType<T=U8>
    field1: T

t = TemplateType
    field1 = 42         // U8
```

### Variable Number of Type Parameters

> Not supported.

We really want to keep this as simple as possible.

## Template Specialization

When use of specific template parameter values require specific code.

```C#
typedFn: <T>(p: T)
    ...
// Identified to be a specialization by name and type.
typedFn: <Bool>(p: Bool)
    ...

typedFn(42)         // generic typedFn<T> called
typedFn(true)       // specialization typedFn<Bool> called
```

---

> TBD

Allow for multiple/nested levels of type params?

```csharp
MyType<M<T>>    // requires M to have one T
    ...         // use M and T?
```

With restrictions:

```csharp
MyType<M: Struct<T: OtherStruct>>
```
