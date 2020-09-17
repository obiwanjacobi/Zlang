# module

The `module` keyword attaches the code in the file to a named (logical) unit. This name is also used with [`import`](import.md).

Multiple code files can be part of the same module.

```C#
module math
```

The name may contain a few special characters: `.` and `_` .
This is a valid module name:

```C#
module myproject.Custom_String1
```

In a sense, the module name is also the namespace of the code in the file.

> Packaging libraries is not part of the language but a function of the compiler. It uses modules to group code together. The module identifies all the code -not just the exported public identifiers.

---

> Should the module statements `module` and `import` only be used at the top of the file, or can they appear anywhere?

> Should the module statements (module, import and export) be prefixed with a `#` like a pragma, because they represent a meta/compile-time operation that is not really output in the binary...?

> TBD: Circular references?

---

> A way to import modules into a local scope?

```csharp
fn: ()
    use mod1
    s = Struct1     // from mod1
        ...
```

---

> Should there be a way to mark a module as open/closed for extension?

Because a module can be made up of multiple files, can any new file declare itself part of any module and therefor gain access to it's 'internals'?

```csharp
// explicitly declare the module as open
module this_is_my_module, open
extension this_is_my_module

// separate user file
module this_is_my_module    // ok, module is open
// add to 'this_is_my_module' module
```

> What about file-scope state?

```csharp
// file-scope
module this_is_my_module
globalVar: U8 = 42  // accessible by all files in module?
```
