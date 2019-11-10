# Checked Functions

Use functions that do extra checking like bounds and overflow checking using a compiler option. This make the code safer but also bigger and slower. Typically on during development and off for release.

User should also be able to write a checked and unchecked version of function.

## Operator Overloads

Operator overloads are checked by a built-in test framework to ensure they follow the laws for that specific operator. This ensures that an (overloaded) operator always behaves in the same predictable manner.

> TDB: determine laws for each operator.

- Identity law (operator should not change identity of operands)
- Associative law (precedence)
- Commutative law
- Distributive law
