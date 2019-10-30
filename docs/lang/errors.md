# Errors

Errors are values

Errors are returned, not thrown

Errors cannot be ignored

Make Error return trace, following an error thru functions that return it.

---

How to access standard errors (make a list of standard errors?)?

How to make errors custom or add extra data? Have a custom struct type derive from Error...?

How to return an error from a void function?

```
voidError(): Error?
voidError(): Void!
// you can't?
```

---

```C#
// error
couldWork(): U8!
    return Error("Sorry, I can't do that Dave.")

var = couldWork() catch(err)
    print(err)
    return          // exit control flow
use(var)

MyFunc(): Bool!
    // return error from function if there is one
    try var = couldWork()  // try == catch(err) return err
    use(var)
```
