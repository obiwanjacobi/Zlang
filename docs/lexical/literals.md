# Literals

## Numbers

Literal numeric values can be specified in the code using prefixes as follows.

- 0b - binary
- 0c - Octal
- 0d - Decimal (default, optional)
- 0x - Hexadecimal

Examples of this would be:

```C#
b = 0b01110011      // binary
o = 0c154           // octal
d = 42              // decimal is default
d = 0d42            // decimal (explicit)
h = 0x8F            // hexadecimal
```

The `_` character may be used to separate parts for readability. They have no meaning for the value. It can be used for any of the prefixes, so if used on a decimal, the prefix `0d` has to be present.

```C#
b = 0x1010_01010    // still a 8-bit binary number
d = 0d7_654_321     // 7,654,321
h = 0xFF_FF
```

## Strings

A string literal is enclosed with double quotes. Here are some examples:

```C#
s = ""                          // empty string
s = "Hello World!"
s = "I say 'Hello'"             // use of single quotes is ok
s = "C:\Windows\Path\File.Ext"  // no need to escape '\'
```

To use special characters in a literal string, you have to use the escape sequence: `\\`.

```C#
s = "Some text \\n with newlines \\n and \\"quotes\\"."
```

For longer string you may want to spread them out over multiple lines. Using indents the compiler can see that the string is spread out.

> Use one indent extra for spreading out strings.

There are two indents for the extra lines of the spread out string:

```C#
s = "Some text
        spread over
        multiple lines"
```

Basic formatting of dynamic values into a string is done in thr following way:

```C#
v = 42
s = "Answer to everthing is '{v}'"
// Anser to everything is '42'
```

Using the `{}` characters as is in a string literal, requires the escape sequence `\\`.
