# Errors

The error mechanism in Z# is not based on exceptions. This would be a load too heavy for the smaller and simpler CPUs. On the other hand, naked error value passing is tedious, error prone and does not guarantee handling of the error.

To create a robust error handling mechanism, it has been incorporated into the language. There are two keywords that deal with handling errors and syntax to specify errors can be returned from a function.

Errors are values returned from a function that cannot be ignored by the caller.

The story starts when an error condition is detected and a function returns an error:

```C#
errorFn(): U8!
    return Error("Failed")
```

Notice the `!` after the return type of the function. This indicates that you should pay attention, because this function can return an error!

Details on using the `Error` type can be read [here]('../types/error.md')

The calling code needs to have a way to deal with either a good return value from a function or handling the error. The primary keyword to use is `catch`, like so:

```C#
couldWork(): U8!
    return Error("Sorry, I can't do that Dave.")

var = couldWork() catch(err)
    print(err)
    return          // exit control flow
use(var)
```

The catch keyword is specified after the function that could return the error, and it introduces a scope. This scope is where the handler code goes in case there is an error. The variable name that is used to hand the code the `Error` is specified inside the parentheses.

A (predicted) common pattern is that a function will call many functions itself and as soon as one errors out, the function itself will simply stop and propagate the error to its caller. The `try` keyword is syntactic sugar for `catch(err) return err` and is specified in front of the function call. It can be used as follows:

```C#
MyFunc(): Bool!
    // propagate error from function
    try b = couldWork()  // try == catch(err) return err
    use(b)
```

It takes away some of the noise of simple error handling.

The `catch` and `try` keywords can only be used on functions that actually return errors.

```C#
myFunc(): Bool
    ...

b = myFunc() catch(err)  // error! myFunc does not return errors
```

It is not possible to return an Error from a void function - a function that has no return value.

```C#
voidFn()                    // no return value specified
    return Error("Failed")  // error! no return value
```

You can use the `return` keyword in a function to exit its execution of course.

## Error Trace

When an error is returned from a function and it bubbles up the call stack, a trace can be made of all the code sites it visits.

This diagnostic information can be useful for tracking down problems.

---

> How to access standard errors (make a list of standard errors?)?
