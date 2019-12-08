# Flow Control

## Conditional branching

The basic if statement works as expected, but the condition is not enclosed in `()`. There can only be a conditional expression following the `if`, so parsing of the condition stops when a newline is encountered or a comment.

All the `if` options in one example.

```C#
if true               // is it true?
    conditional_code
else if false         // or is it false?
    never_get_here
else                  // or is it neither?
    other_code
```

> No assignment is permitted inside the `if` conditional expression.

## Loops

A loop is an essential control mechanism in directing the execution flow of the code. There is only one keyword for making a loop: `loop`.

The simplest form is an endless loop:

```C#
loop
    endless_loop
```

A 'while loop' just adds a condition to the statement:

```C#
loop false
    never_get_here
```

A 'for' or 'for-each' loop is constructed using a `Range`.

```C#
loop n in [0..10]
    foreach_n_1_to_9
```

## Break

It is possible to break out of the execution of a loop at any time with the `break` keyword.

Here's an example of an endless loop that uses a conditional branch `if` to break out of the loop:

```C#
loop
    do_stuff_here
    if true
        break     // this will exit the loop
```

The `break` keyword only works on its immediate parent loop. In the case of nested loops, it will look like this:

```C#
loop                  // loop #1
    do_stuff_here
    loop              // loop #2
        do_other_stuff_here
        if true
            break     // this will exit loop #2
```

## Continue

The opposite of `break`, the `continue` keyword will allow you to skip one iteration of the loop:

```C#
loop
    if true
        continue    // this will skip 'do_stuff_here'
    do_stuff_here
```

As with `break`, `continue` only works on the immediate parent loop.
