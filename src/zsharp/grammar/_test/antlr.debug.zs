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

funcErr(p: U16): U8
    loop p > 14
    return Error()
    
// enums
MyEnum1
    opt1,           // TODO: enum options on one line
    opt2

MyEnum2
    opt1 = 1,
    opt2 = 2,

MyEnum3: Str
    opt1 = "1",
    opt2 = "2"

// structs
MyStruct1
    field1: U8
    field2: Str

MyStruct2: MyStruct1
    field3: U16
    field4: F32
