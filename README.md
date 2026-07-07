*This project has been created as part of the 42 curriculum by kochniak.*

# push_swap

## Description

`push_swap` is a 42 sorting project. The objective is to sort a list of integers using two stacks and a restricted set of operations, while producing as few moves as possible.

This implementation:

- parses and validates the input
- rejects duplicates and invalid integers
- assigns rank indexes before sorting
- uses dedicated logic for small inputs
- uses radix sort for larger inputs

Stacks are implemented as doubly linked lists.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable in the project root.

### Cleaning

```bash
make clean
```

```bash
make fclean
```

```bash
make re
```

### Execution

```bash
./push_swap 3 2 1
```

```bash
./push_swap "3 2 1"
```

### Checker

```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

## Resources

- 42 subject: push_swap
- GNU C Library documentation
- `man 3 malloc`
- `man 3 free`
- `man 3 write`
- binary radix sort references
- doubly linked list references

AI was used to draft and format this README, to condense the project description, and to organize the required sections. The code, build process, and runtime behaviour were verified locally in the workspace.
