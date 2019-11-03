// comment
module test1

funcDecl(p: U8?): Bool!
    if p
        return true
    else
        return Error("Parameter not specified")

MyEnum: Str
    opt1 = "1",
    opt2 = "2"
