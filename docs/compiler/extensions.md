# Extensions

> A meta extension: implement a custom # tag. Register C++ code with the compiler to be called when the `#` tag is encountered. The extension emits either Abstract Syntax Tree or Machine Code Representation.

> A 'code attribute' extension. (no code attributes yet.) Annotated code that gets in the loop for generating the code for that scope. This, for instance, allows implementation of detailed entry and exit tracing etc.

## Z80

Z80 specific extension. Similar could be made for other CPUs. Code is bound to that CPU - not trying to abstract these specifics.

```C#
import Z80

Z80.Halt()                  // execute the halt instruction
Z80.InterruptMode(Interrupt.Mode2)  // set interrupt mode
Z80.SetInterruptVector(myISR, 0)    // set interrupt handler
Z80.SetNonMaskableInterruptHandler(myNMI)  // NMI handler
```
