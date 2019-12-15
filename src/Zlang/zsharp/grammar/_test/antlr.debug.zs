// module
module test1
import mymodule.v1      // TODO: `module` is an error
export funcDecl

// global vars
g: U8 = 42

// expressions
e1 = 2 + 7 / 8 % 3
e2 = (2 + 7) / 8
l1 = (2 > 4) and (5 < 3)
b1 = ((2 + 7) / 8) > 4
b2 = not ((2 + 7) / 8) > 4

// functions
voidFunc()
    l = 42 / 3
    return

funcDecl(p: U8?): Bool!
    if p
        return p = 42
    else if p = 0
        return false
    else
        return Error("Parameter not specified")

funcX(p: U16): U8
    x = p + 3
    loop p > 42
        p = p - 1
    return x
