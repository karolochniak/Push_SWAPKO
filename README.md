# Push_SWAPKO

A highly optimized data sorting algorithm implemented in C. This project uses two stacks (`A` and `B`) and a limited set of operations to sort a given array of integers in ascending order with the minimum possible number of moves.

---

## 🚀 About the Project

The `push_swap` program takes a list of integers as arguments, initializes stack `A` with them, and outputs a sequence of operations (e.g., `sa`, `pb`, `ra`) to standard output that sorts the data. 

Depending on the input size, the program dynamically selects the most efficient sorting strategy:
- **2 elements:** Handled by `sort_two`.
- **3 elements:** Handled by an optimized `sort_three` algorithm.
- **Larger datasets:** Handled by a custom `radix_sort` utilizing pre-assigned indexes.

---

## 🧩 Data Structure

The stacks are implemented using a doubly linked list to ensure efficient node manipulation:
```c
typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
    struct s_list   *prev;
} t_list;
