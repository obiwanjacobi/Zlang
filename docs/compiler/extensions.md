# Extensions

> TBD: compiler extensions. plugins that supply code. Don't allow language extension, but do allow compile-time function extensions.

> A meta extension: implement a custom # tag. Register C++ code with the compiler to be called when the `#` tag is encountered. The extension either manipulates the Abstract Syntax Tree or emits Machine Code Representation.

> A 'code attribute' extension. (no code attributes yet.) Annotated code that gets in the loop for generating the code for that scope. This, for instance, allows implementation of detailed entry and exit tracing etc.

Code attributes syntax??

```C#
// function code attributes
{CodeAttr}                  // {} not used for anything else
myFunction(p: U8) Bool

// multiple code attributes
{CodeAttr1, CodeAttr2}      // comma separated
myFunction(p: U8) Bool

// code attributes inline?
{CodeAttr} myFunction(p: U8) Bool
// gets really long
{CodeAttr1, CodeAttr2, CodeAttr3, CodeAttr4} myFunction(p: U8) Bool

// function parameter code attributes
myFunction({CodeAttr} p: U8) Bool

{p: CodeAttr}
myFunction(p: U8) Bool

// function return code attributes
myFunction(p: U8) {CodeAttr} Bool

{=> CodeAttr}               // => for retval
{: CodeAttr}                // : for retval
myFunction(p: U8) Bool

// full set
{p: CodeAttr}               // order does not matter
{: CodeAttr}
{CodeAttr1, CodeAttr2}      // for function
myFunction(p: U8) Bool
// ^^^^ this I like the best.
```

## Z80

Z80 specific extension. Similar could be made for other CPUs. Code is bound to that CPU - not trying to abstract these specifics.

```C#
import Z80

Z80.Halt()                  // execute the halt instruction
Z80.InterruptMode(Interrupt.Mode2)  // set interrupt mode
Z80.SetInterruptVector(myISR, 0)    // set interrupt handler
Z80.SetNonMaskableInterruptHandler(myNMI)  // NMI handler
Z80.Restart(Rst28)
Z80.Input()
Z80.Output()
```
