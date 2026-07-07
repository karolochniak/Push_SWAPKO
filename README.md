*This project has been created as part of the 42 curriculum by kochniak.*

# push_swap

## Description

`push_swap` is a sorting project from the 42 curriculum. The goal is to sort a list of integers using only two stacks and a limited set of allowed operations, while keeping the number of moves as low as possible.

This implementation parses and validates the input, rejects invalid or duplicated values, converts numbers to sortable indexes, and chooses a strategy depending on the size of the stack. Small inputs are handled with dedicated logic, while larger inputs are sorted with a radix-based approach.

The stacks are represented with doubly linked lists.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable in the project root and also compiles the bundled `printf/` library.

### Cleaning

```bash
make clean
make fclean
make re
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

The output is the sequence of operations needed to sort the stack.

### Checker

You can verify the generated instructions with the provided checker:

```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

## Features

- Input parsing from separate arguments or a quoted string.
- Validation of integer format, range, and duplicates.
- Stack operations implemented with linked lists.
- Optimized handling for small input sizes.
- Radix-sort-based strategy for larger inputs.

## Technical Choices

- Doubly linked lists are used to make rotations and push operations efficient.
- Values are normalized to indexes before sorting so the algorithm can work on compact ranks instead of raw numbers.
- The implementation keeps the sorting logic separated from parsing and stack utilities to make the code easier to follow.

## Resources

- 42 subject: push_swap
- GNU C Library documentation
- man 3 malloc
- man 3 free
- man 3 write
- Radix sort references and explanations
- Doubly linked list references

## AI Usage

AI was used to rewrite this README, improve the wording, and make sure the required sections were included. The project code, compilation target, and execution examples were checked against the workspace files, and no code was generated or modified by AI as part of the implementation itself.
