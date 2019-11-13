# Structures

> TODO: Structuring/destructuring(spread operator)

Structures are data records of fields.

A name and a set of fields is required in order to define a structure. Structures cannot be empty - have no fields.

```
MyStruct
    field1: U8
    field2: Str
```

Note that the name of the structure has to start with a capital letter, because it is a new type.

Also note the absence of any specific keywords like 'struct'.

Here is how to create an instance of a structure and assign its fields with values.

```C#
MyStruct
    field1: U8

s = MyStruct            // instantiate an instance
    field1 = 42         // assigning values
```

A structure can have default values. If no value is explicitly specified each type is initialized with its `#default` value:

```C#
MyStruct
    field1: U8 = 42
    field2: U8 = 42

s = MyStruct
    field2 = 101        // overwrites any value

// s.field1 = 42
// s.field2 = 101
```


## Composition

New structure types can be made from other structure types by the following methods:

- Inheritance
- Containment

...or a combination of these.

Here is an example of inheritance:

```C#
MyStruct
    field1: U8

MyDerived: MyStruct
    field2: Str
```

`MyDerived` has two fields: `field1` and `field2`. An instance of  the `MyDerived` structure can be treated as an instance of the `MyStruct` structure.

> Multiple inheritance is not supported at this moment.

Here is an example of containment:

```C#
MyStruct
    field1: U8

MyContainer
    cnt: MyStruct
    field2: Str
```

The `MyContainer` structure still has the `field1` from `MyStruct` but it has to be reached by the `cnt` field. Here is how the structure would be initialized:

```C#
s = MyContainer
    cnt.field1 = 42
    field2 = "OK"
```

> Unions in structures are not supported at this moment.

## Memory Layout

The fields of a structure are layed out in the order of their definition starting at the base structure type. No alignment or filler bytes are added.
