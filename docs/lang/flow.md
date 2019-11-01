# Flow Control

## Conditional branching

The basic if statement works as expected, but the condition is not enclosed in `()`. There can only be a conditional expression following the `if`, so parsing of the condition stops when a newline is encountered or a comment.

All the `if` options in one example.

```C#
if true
    conditional_code
else if false
    never_get_here
else
    other_code
```

With comments, it would look like this:

```C#
if true               // is it true?
    conditional_code
else if false         // or is it false?
    never_get_here
else                  // or is it neither?
    other_code
```
