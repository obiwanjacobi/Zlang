# LLVM

Build against the llvm-project (github). LLVM build into `llvm-project/build_vs` using CMake for Windows.

Include Paths:
```
    llvm-project/llvm/include
    llvm-project/build_vs/include
```

Library Paths:
```
    llvm-project/build_vs/Debug/libs
```

Libraries to Add to Linker Input:
```
    llvm-project/build_vs/bin/llvm-config --libs core
```

This prints out all core llvm libraries.
