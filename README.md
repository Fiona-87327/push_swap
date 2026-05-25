# 🔄 Push Swap

A high-performance sorting algorithm implementation that sorts integers using only two stacks and a limited set of operations.

## 🎯 Overview

**Push Swap** is a 42 School project that challenges you to write an efficient sorting algorithm in C. The constraint: you can only use two stacks (`a` and `b`) and must sort a list of unique integers with the minimum number of operations.

This implementation uses **k-distribution sort**, a sophisticated distribution-based sorting strategy that significantly reduces operation count compared to naive approaches.

## 🎨 Push Swap Visualizer 
https://github.com/o-reo/push_swap_visualizer


<img width="800" height="450" alt="Aufzeichnung2026-05-25085404-Trim-ezgif com-crop" src="https://github.com/user-attachments/assets/9a9f42bc-1983-4900-b31f-faa6d057bb91" />


## 🤔 Problem Statement

Given:
- A list of unique integers
- Two stacks: `a` (initial input) and `b` (auxiliary)
- A limited set of operations (see [Operations](#operations))

Goal:
- Sort stack `a` in ascending order
- Minimize the number of operations

## 🚀 Algorithm

### K-Distribution Sort

This project implements **k-distribution sort**, optimized for medium-sized datasets (50-500 elements):

1. **Distribution Phase**: Partition elements from stack `a` into stack `b` based on value ranges
   - Uses a delta factor (`size / 20 + 7`) to determine partition boundaries
   - Elements below threshold are pushed to `b`
   - Elements above threshold rotate back to the end of stack `a`

2. **Index Assignment**: Assigns relative indices to all elements
   - Lower index = smaller value
   - Used for efficient value comparisons

3. **Reintegration Phase**: Merge stack `b` back into `a` in sorted order
   - Finds the maximum element in `b`
   - Rotates `b` optimally to bring it to the top
   - Pushes to `a`
   - Repeats until `b` is empty

### Small Sort Optimization

For lists ≤ 5 elements:
- **1-2 elements**: Already sorted or single swap needed
- **3 elements**: Special 3-sort function
- **4-5 elements**: Optimized 4-5 sort function

## 📁 Project Structure

```
push_swap/
├── src/                          # Source files
│   ├── k_sort.c                  # K-distribution sort implementation
│   ├── small_sort.c              # Sorting for ≤5 elements
│   ├── oper_pop.c                # Stack pop operations (pa, pb)
│   ├── oper_rotate.c             # Rotate operations (ra, rb, rr)
│   ├── oper_rev_rotate.c         # Reverse rotate operations (rra, rrb, rrr)
│   ├── oper_sab.c                # Swap operations (sa, sb, ss)
│   ├── stack_init.c              # Stack initialization
│   ├── sort_util.c               # Sorting utilities
│   ├── input_check.c             # Input validation
│   ├── check_util.c              # Validation utilities
│   └── input_check_util.c        # Input utility functions
├── include/                      # Header files
│   └── push_swap.h               # Main header
├── libft/                        # Custom library
├── Makefile                      # Build configuration
├── checker_linux                 # Validation tool
└── README.md                     # This file
```

## 🔧 Installation

### Prerequisites
- GCC compiler
- Make
- Linux/Unix environment

### Build

```bash
# Compile the project
make

# Clean object files
make clean

# Remove all compiled files
make fclean

# Rebuild from scratch
make re
```

The compiled binary will be `push_swap`.

## 💻 Usage

```bash
# Basic usage
./push_swap 3 2 5 1 4

# With many numbers
./push_swap $(seq 1 100 | shuf)

# Pipe to checker for validation
./push_swap 3 2 5 1 4 | ./checker_linux 3 2 5 1 4
```

### Input Format
- Space-separated integers
- Must be unique
- Can be positive or negative
- In any order

### Output
The program prints a sequence of operations that sort stack `a`.

## 🎮 Operations

| Operation | Description |
|-----------|-------------|
| `pa` | Push top of `b` onto `a` |
| `pb` | Push top of `a` onto `b` |
| `sa` | Swap top 2 elements of `a` |
| `sb` | Swap top 2 elements of `b` |
| `ss` | `sa` + `sb` (simultaneous) |
| `ra` | Rotate `a` up (top → bottom) |
| `rb` | Rotate `b` up (top → bottom) |
| `rr` | `ra` + `rb` (simultaneous) |
| `rra` | Reverse rotate `a` (bottom → top) |
| `rrb` | Reverse rotate `b` (bottom → top) |
| `rrr` | `rra` + `rrb` (simultaneous) |

## 📊 Performance

### Algorithm Complexity
- **Time**: O(n log n) average case
- **Space**: O(n) for stack storage
- **Operation Count**: Typically 1.5x - 2x optimal for medium datasets

### Benchmark Results (Expected)
| Input Size | Operations | Status |
|------------|-----------|--------|
| 3 elements | ≤ 3 | ✓ Optimal |
| 5 elements | ≤ 12 | ✓ Optimal |
| 100 elements | ≤ 700 | ✓ Good |
| 500 elements | ≤ 5500 | ✓ Good |

## 🧪 Testing

### Using the Checker
```bash
# Test with specific input
./push_swap 3 2 5 1 4 | ./checker_linux 3 2 5 1 4

# Test with random data
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG

# Stress test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

### Memory Check
```bash
make v  # Runs valgrind with leak detection
```

### Validation Criteria
- ✓ Stack `a` is sorted in ascending order
- ✓ Stack `b` is empty
- ✓ All operations are valid
- ✓ Minimal operation count

## 🔍 Implementation Details

### Index Assignment
Assigns relative rankings to elements for efficient comparisons without storing original values multiple times.

### Distribution Phase Logic
```c
delta = stack_size / 20 + 7;  // Partition size
```
This dynamic delta ensures:
- Smaller lists get fewer partitions
- Larger lists benefit from more fine-grained distribution
- Balanced time complexity across input sizes

### Optimal Rotation Choice
When bringing elements back from `b`, the algorithm chooses between:
- **Forward rotation** if element is in top half
- **Reverse rotation** if element is in bottom half

This minimizes unnecessary operations.

## 📚 Resources

- [K-Distribution Sort Applied to the Push Swap Problem](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376) - Detailed Medium article explaining the k-distribution algorithm and its application

## 📝 Notes

- All input integers must be **unique**
- Duplicate numbers will trigger an error
- Non-integer inputs will trigger an error
- The program validates all inputs before sorting
  

## 👤 Author

- **jiyawang** - 42 School student

## 📄 License

This project is part of the 42 School curriculum.

---

**Happy Sorting! 🎉**
