# Assignment Expressions

| Operator | Function
|-------|------
| = | Assign value

> The left operand of an assignment expression can not be a literal value.

Here 42 is assigned to the variable `a`.

```C#
a = 42
```

The receiving (left) operand can also be a path to a field.

```C#
MyStruct
    field1: U8

s: MyStruct
s.field1 = 42
```

```C#
z: MyStruct
    field1 = 42     // inline assignment
```

> Because both the `Equals` and the `Assignment` operators use the '`=`' symbol, it is not possible to assign values inside a comparison expression.

```C#
if a = myFunc()      // error!
    ...
```

---

## Conditional

```csharp
a: U8?
a ??= 42
// a= 42

a: U8?
a = 42
a ??= 101
// a= 42
```

---

## Atomic Assignment

protect from (non-maskable) interrupts.

> TBD: A way to ensure an assignment operation is uninterrupted.

- unconditional
- conditional (exchange-if)

Atomic as an operator

```csharp
a = 42
// special operator?
b := a              // atomic assignment
b :=: a             // atomic exchange
b :=: a ? a = 42    // conditional1
b :=: a ?? a = 42   // conditional2
```

Atomic as a type

```csharp
// assignment is easy because Atom
a: Atom<U8> = 42
a = 101

b: U8   // does not need to be Atom
// supply function on Atom
a.Exchange(b.Ptr())
a.ExchangeIf(b.Ptr(), a = 42)
```

Atomic locking requires guaranteed unlocking... (defer keyword)

```csharp
a: Atom<U8> = 42

a.Lock()
defer a.Unlock()    // defer keyword

a = 101

// end of scope unlocks
```

Volatile is used when the contents of a variable (memory location) can be changed from outside the program (memory mapped IO/hardware registers) or outside the compiler's field of view (interrupt service routines).

If we are able to tag ISR's in the language, we can automatically tag all used variables as volatile.
Memory mapped IO is harder to auto detect.

> A 3-letter abbreviation that means volatile?

```csharp
// we may want to save IO for language supported Input/Output instructions.
a: IO<U8> = 42
a: Volatile<U8> = 42    // too long?
a: Weak<U8> = 42        // save for ptrs?
a: Alt<U8> = 42         // alternate
a: Soft<U8> = 42

// like optional - but different
// will get weird with optional/error
a: &U8 = 42
```

> Memory Fences are not supported. No need because the simple 8-bit CPUs execute in order.

---

> TBD

## Deconstructing

> Use `[]`, `{}` or `()`?

- `[]` says arrays
- `{}` says objects/structs
- `()` used for functions but otherwise ok

> This is not the same as a tuple!

> Deconstruction is _copying_ the value into a variable. But referencing could be an optimization - but that would also make it more complex.

```csharp
(a, b) = ...
// a and b can be used as separate vars
sum = add(a, b)
```

deconstructing an array

```C#
[a, b, ...rest] = [1, 2, 3, 4, 5]
(a, b, ...rest) = [1, 2, 3, 4, 5]
{a, b, ...rest} = [1, 2, 3, 4, 5]

// a: U8 = 1
// b: U8 = 2
// rest: Array<U8> = [3, 4, 5]
```

Deconstructing function parameters

```C#
arr = [1, 2, 3, 4, 5]

func: (p: U8)
    ...
func(...arr)    // called 5 times?

func5: (p1: U8, p2: U8, p3: U8, p4: U8, p5: U8)
    ...
func5(...arr)    // or with 5 params?

// what if the param count does not match array item count?
```

Deconstructing a structure:

```C#
MyStruct
    field1: U8
    field2: U8
    field3: U8

s = MyStruct
    ...

[field1, field3] = s
(field1, field3) = s
// field1: U8 = <value of s.field1>
// field3: U8 = <value of s.field3>
// <value of s.field2> is not used

[a, b] = s      // error! field names must match (case insensitive)
(a, b) = s
```

Swap scalar variables (unlike structs)

```C#
x = 42
y = 101

[x, y] = [y, x]
(x, y) = (y, x)

// x = 101
// y = 42
```

---

> TBD

Make type decl and assignment distinct.

```csharp
a: U8       // declare typed var (default init)
a: U8 = 1   // declare typed and init
a:= 1       // declare inferred-type and init
a = 1       // assign - 'a' must already be declared

// possible clashes
MyVar: U8   // clash with variable with capital?
MyAlias = U8
```

Could this help improving variable assignments?
