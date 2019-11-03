// module
module test1
import mymodule.v1      // TODO: `module` is an error
export funcDecl

// functions
voidFunc()
    return

funcDecl(p: U8?): Bool!
    if p
        return p = 42
    else
        return Error("Parameter not specified")

// enums
MyEnum1
    opt1,           // TODO: parse options on one line
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
