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

Slices

> A pointer and a length
