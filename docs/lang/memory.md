# Memory

## Memory Allocations

Allocating memory is always explicit. There are NO hidden memory allocations!

Specific allocator strategies.

- Heap: traditional global memory allocation.
- Pool: A pool (of a fixed number) of fixed sized chunks. Usually the size of a specific type.
- Scoped: A container for allocation made within a certain scope. When going out-of-scope, memory is freed/container is destroyed.
- Banks: Some sort of strategy concerning bank switching.
- Stack: implicit by using language constructs (params/local vars).

Passing allocators as params

- Allocator interface (alloc, realloc, free) that allows implementing specific strategy.

Global allocators

globally available default allocator(s)

## Memory Banks

Every system has its own way of extending memory. Wide range of mechanisms and different rules.
Need to provide an interface that can be implemented (inline assembly) to facility integration into the language.

### Bank Windows

A range in memory that is swapped/replaced by switching banks.

Multiple windows may exist.

Bank size == Bank Window size

### Data in Memory Banks

The active bank window is locked until operation is done with data.

Data must be self-contained.

### Code in Memory Banks

Code blocks can be switched in and out recursively if necessary.

When function call is done, previous bank needs to be restored.