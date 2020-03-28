# LLVM

Build against the llvm-project (github). 
LLVM build into `llvm-lib` using CMake (UI) for Windows.

https://llvm.org/docs/GettingStartedVS.html

`build` the folder used to build to (build folder in cmake).
`llvm-install` the path to where the llvm-project is installed.

Include Paths:
```
    `llvm-install`/llvm/include
```

Library Paths:
```
    `llvm-install`/lib
```

Libraries to Add to Linker Input:
```
    `llvm-install`/`build`/bin/llvm-config --libs core
```

This prints out all core llvm libraries to add to the linker.

## `Error    C4146    unary minus operator applied to unsigned type, result still unsigned`

* fix by hand / change the source.
