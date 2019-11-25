# Compiler Options

> Compiler profile: a configuration of what (language) features are on/off. Separate file. All options can also be supplied on the command line.

- safety checks
- user signal values (defines) (allow to be specified in file also)

## Syntax Options

- no auto vars / always typed vars
- explicit operator precedence: use `()`.
- no bool literal comparisons: `if myBoolVar = true` will not be allowed, `if myBoolVar` or `if not myBoolVar` is ok.
- explicit return value assignment. `_ = func()` to ignore retval.