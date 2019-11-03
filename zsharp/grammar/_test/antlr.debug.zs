// comment
module test1

funcDecl(p: U8?): Bool!
    if p
        return p = 42
    else
        return Error("Parameter not specified")

// enums
MyEnum
    opt1 = 1,
    opt2 = 2,

MyEnum: Str
    opt1 = "1",
    opt2 = "2"
