# Range

> Note: Range's stop or end term is exclusive!

```C#
[1..4]      // closed range
[..4]       // from start
[4..]       // till end
[..]        // all
[0]         // first
[-1]        // last
```

```C#
rng = Rng(1, 6)     // ??
```

## Static

```C#
[1..10]
```

## Dynamic

```C#
i = 42
[0..i]
```

Iterators

- Array
- List
- Range
- Slice

Usually not a type you would create directly.

```csharp
Iter<T>
    Next(self): Bool _
    Current(self): T _
```

Usually not function you would call directly.

```csharp
GetIter<T>(self: Array<T>): Iter<T>
GetIter<T>(self: List<T>): Iter<T>
GetIter<T>(self: Range<T>): Iter<T>
GetIter<T>(self: Slice<T>): Iter<T>
```

```csharp
ArrIter<T>
    arr: Array<T>
    i: U8

Next<T>(self: ArrIter<T>)
    if self.arr#Count > self.i
        i = i + 1
        return true
    return false

Current<T>(self: ArrIter<T>)
    return self.arr[self.i]
```

Slices

> A pointer and a length
