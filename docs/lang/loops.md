# Loops

A loop is an essential control mechanism in directing the execution flow of the code. There is only one keyword for making a loop: `loop`.

The simplest form is an endless loop:
```
loop
    endless_loop
```

A 'while loop' just adds a condition to the statement:

```
loop false
    never_get_here
```

A 'for' or 'for-each' loop is constructed using a `Range`.

```
loop n in [0..9]
    foreach_n_1_to_9
```
