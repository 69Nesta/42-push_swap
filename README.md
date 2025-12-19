*This project was created as part of the 42 curriculum by rpetit, lgirard.*

# Push_swap

## Description
**Push_swap** is a 42 algorithm project that challenges you to sort data on a stack with a limited set of instructions, using the lowest possible number of actions. You're given two stacks (`a` and `b`) and a set of operations to manipulate them. The goal is to write a C program (`push_swap`) that calculates and outputs the shortest sequence of operations needed to sort a given list of integers.

This project introduces algorithmic complexity in a practical way, requiring the implementation of multiple sorting strategies with different time complexities. The program must adaptively choose the most efficient algorithm based on the initial disorder of the stack.

## Instructions

### Compilation
Clone the repository and run:
```bash
make
```
This will compile the `push_swap` executable.

To compile the bonus `checker` program:
```bash
make checker
# or
make bonus
```

To rebuild everything from scratch:
```bash
make fclean && make
```

### Usage

#### Basic sorting
```bash
./push_swap 3 2 1
# Outputs the sequence of operations to sort the stack
```

#### Strategy selection
The program supports four strategies, selectable via command-line flags:
- `--simple`: Forces the O(n²) algorithm | `Bubble sort`
- `--medium`: Forces the O(n√n) algorithm | `Chunk based`
- `--complex`: Forces the O(n log n) algorithm | `Radix LSD`
- `--adaptive`: Uses the adaptive algorithm based on disorder (default)

Examples:
```bash
./push_swap --simple 5 4 3 2 1
./push_swap --complex 100 99 98 97 96
./push_swap 4 67 3 87 23  # Uses adaptive strategy by default
```

#### Benchmark mode
To view performance metrics:
```bash
./push_swap --bench 2 1 3 6 5 8 2> bench.txt
# Operations are output to stdout, metrics to stderr (saved to bench.txt)
```

#### Using the checker
The `checker` program verifies that a sequence of operations correctly sorts the stack:
```bash
# Generate operations and verify them
./push_swap 3 2 1 | ./checker 3 2 1
# Should output "OK"

# With benchmark mode
./push_swap --bench 3 2 1 2> metrics.txt | ./checker 3 2 1
```

### Error handling
The program displays "Error" on stderr for invalid input:
- Non-integer arguments
- Integers outside the valid range
- Duplicate values
- Invalid flags

Example:
```bash
./push_swap 3 2 one 4
# Outputs: Error
```

## Selected Algorithms — Explanation and Justification

The project implements four distinct sorting strategies, each with different time complexities in terms of Push_swap operations generated.

### 1. Simple Algorithm (O(n²))
**File:** `src/strategies/simple/ft_strategy_simple.c`

**Description:** A bubble-sort-inspired algorithm that repeatedly scans stack `a`, swapping adjacent elements when they're out of order (`sa`) and rotating when necessary. It's a straightforward adaptation of classic quadratic sorting algorithms to the stack operation model.

**Complexity:** O(n²) worst-case operations.

**Justification:** Efficient for very small stacks (n < 20) or nearly sorted data where few operations are needed. The simplicity minimizes overhead and makes it optimal for low-disorder cases.

### 2. Medium Algorithm (O(n√n))
**File:** `src/strategies/medium/ft_strategy_medium.c`

**Description:** A chunk-based algorithm that:
1. Calculates the optimal chunk size as √n
2. Pushes elements from stack `a` to `b` based on their value ranges (chunks)
3. Sorts each chunk in when pushing to `a`

**Complexity:** O(n√n) operations.

**Justification:** Provides a balance between operation count and algorithmic complexity for medium-sized inputs (20 ≤ n ≤ 500). Chunking reduces the number of comparisons and long-distance element moves compared to naive approaches like simple algorithms (bubble sort).

### 3. Complex Algorithm (O(n log n))
**File:** `src/strategies/complex/ft_strategy_complex.c`

**Description:** A radix sort adaptation using binary representation:
1. Normalize the input values to their ranks (0 to n-1) using coordinate compression
2. For each bit position (from LSB):
   - Push elements with 0 in the current bit to stack `b` or rotate `a`
   - Push all elements back to stack `a`
3. Repeat until all bits are processed

**Complexity:** O(n log n) operations, where log is base 2.

**Justification:** The most efficient strategy for large, highly disordered inputs (n > 500). Radix sort maps naturally to stack operations (push/rotate) and guarantees consistent performance regardless of value distribution. Normalization ensures we only need to process ⌈log₂(n)⌉ bits.

### 4. Adaptive Algorithm (Learner's Design)
**File:** `src/strategies/ft_strategy_selector.c`

**Description:** Dynamically selects the optimal strategy based on the computed disorder metric:

**Disorder Calculation:**
```c
disorder = number_of_inversions / total_possible_pairs
```
Where an inversion occurs when a larger number precedes a smaller one.

**Thresholds and Strategy Selection:**
- **Low disorder (disorder < 0.2):** Uses Simple algorithm (O(n) target)
- **Medium disorder (0.2 ≤ disorder < 0.5):** Uses Medium algorithm (O(n√n) target)  
- **High disorder (disorder ≥ 0.5):** Uses Complex algorithm (O(n log n) target)

**Complexity Justification:**
- **Low disorder:** Nearly sorted stacks require minimal adjustments. A simple bubble-like approach achieves linear time by fixing few inversions.
- **Medium disorder:** Moderate randomness benefits from chunking, which reduces operation count compared to O(n²) while avoiding the overhead of radix sort for medium n.
- **High disorder:** Highly random data requires the asymptotic efficiency of O(n log n). Radix sort provides consistent performance regardless of inversion count.

**Rationale for Thresholds:**
The thresholds (0.2 and 0.5) were determined empirically through testing on various input distributions. Below 0.2 disorder, simple algorithms typically outperform chunking. Above 0.5, radix sort's log-linear scaling becomes advantageous despite its constant-factor overhead.

### Normalization (Coordinate Compression)
A key technique used in multiple strategies, particularly the radix sort. It replaces each original value with its rank in the sorted list (0 to n-1). This ensures:
- Values are in a predictable range [0, n-1]
- Only ⌈log₂(n)⌉ bits need processing in radix sort
- Independence from the original value range (works for any integers)

## Performance Benchmarks

Our implementation meets and exceeds the project's performance requirements:

| Input Size | Minimum Requirement | Good Performance | Excellent Performance | Our Average |
|------------|---------------------|------------------|----------------------|-------------|
| 100 numbers| < 2000 ops         | < 1500 ops       | < 700 ops            | ~1100 ops    |
| 500 numbers| < 12000 ops        | < 8000 ops       | < 5500 ops           | ~6784 ops   |

Benchmarks conducted on random permutations show consistent excellent performance across all input sizes.

## Repository Structure

```
push_swap/
├── Makefile                    # Build configuration
├── includes/                   # Header files
├── libft/                      # Custom C library (included)
├── src/
│   ├── main.c                  # Program entry point
│   ├── operations/             # Stack operations (push, swap, rotate, etc.)
│   ├── strategies/             # Sorting algorithm implementations
│   │   ├── simple/            # O(n²) algorithm
│   │   ├── medium/            # O(n√n) algorithm  
│   │   ├── complex/           # O(n log n) algorithm
│   │   └── ft_strategy_selector.c  # Adaptive algorithm
│   └── utils/                  # Utilities (parsing, stack management, etc.)
├── checker_bonus/              # Checker program source (bonus)
└── README.md                   # This file
```

## Resources

### Learning Materials
- [Push_swap Subject](https://cdn.intra.42.fr/pdf/pdf/190275/en.subject.pdf) - Official project requirements
- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) - Wikipedia article on radix sort
- [Coordinate Compression](https://usaco.guide/silver/sorting-custom?lang=cpp) - Guide to value normalization
- [Push Swap Visualizer](https://push.eliotlucas.ch/) - Helpful for understanding algorithm behavior

### AI Usage in This Project
AI tools were used responsibly in the development of this project:

**For Code Development:**
- **Explanation Generation:** AI helped articulate algorithm justifications and complexity analyses.
- **Code Review:** Used to identify potential edge cases and suggest test scenarios.
- **Documentation:** Assisted in structuring this README and ensuring all required sections were included.

**For Learning:**
- **Concept Clarification:** AI explained specific algorithmic concepts when researching different sorting strategies.


## Group Contributions

Both authors contributed equally to all aspects of the project:

**rpetit:**
- Input parsing and error handling
- Primary implementation of the radix sort (complex strategy)
- Adaptive strategy selector and disorder calculation
- Benchmark testing and performance optimization
- Makefile configuration

**lgirard:**
- Stack operation utilities
- Implementation of the bubble-sort algorithm (simple strategy)  
- Implementation of the chunk-based algorithm (medium strategy)  
- Performance optimization
- Checker program (bonus part)

Both authors participated in algorithm design, code review, documentation, and project defense preparation.

## License

This project is part of the 42 School curriculum. The code is provided for educational purposes. For external use, please contact the authors.

## Contact

For questions, issues, or contributions:
- **rpetit**: rpetit@student.42lyon.fr
- **lgirard**: lgirard@student.42lyon.fr

Please open an issue in the repository for bug reports or feature requests.