# Zlang Packages

Final output is a binary file that could be programmed in to an EPROM. There is no executable file format.

Extra files can accompany the binary output, that provide extra meta data about the binary.

- debug symbols
- (LLVM) byte code (for linker optimization or interpretation)
- source code (zipped)
- symbol table
- modules, exports and imports

## Packaging Features

targeting memory banks

auto packing code into fixed size banks

bank switching thunks

binary format for late linking with optional optimization.

---

package manager?
