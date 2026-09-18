*This project has been created as part of the 42 curriculum by gbekur and hcherif.*

# push_swap

## Description

`push_swap` is a sorting project that works with two stacks, `a` and `b`, and a limited set of operations.

The program takes a list of integers, puts them in stack `a`, and prints a sequence of Push_swap operations that sorts the stack in ascending order (smallest value on top).

We implemented three main strategies:

- `--simple` — O(n²)
- `--medium` — O(n√n)
- `--complex` — O(n log n)

There is also an `--adaptive` mode that picks a strategy based on how disordered the input is. If you don't specify a strategy, `--adaptive` is used by default.

The `--bench` flag prints extra information about the sorting process to `stderr`.

---

## Operations

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of `b` to `a` |
| `pb` | Push the top element of `a` to `b` |
| `ra` | Rotate stack `a` upwards |
| `rb` | Rotate stack `b` upwards |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` at the same time |

Operations are printed to `stdout`, one per line. We only print and count an operation if it actually changes at least one of the stacks.

---

## Instructions

### Compilation

```bash
make
```

The project is compiled with:

```text
cc -Wall -Wextra -Werror
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

The Makefile avoids relinking when nothing has changed.

---

## Usage

```bash
./push_swap [strategy] [--bench] <integers>
```

Available strategies:

```bash
--simple
--medium
--complex
--adaptive
```

`--adaptive` is the default.

Examples:

```bash
./push_swap 3 2 1
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
```

You can also pass numbers inside quoted arguments:

```bash
./push_swap "5 4 3 2 1"
```

or mix quoted and separate arguments:

```bash
./push_swap "5 4" 3 "2 1"
```

The first number is considered the top of stack `a`.

- If the input is already sorted, no operations are printed.
- If no arguments are provided, the program prints nothing.

---

## Error handling

Invalid input prints:

```text
Error
```

followed by a newline to `stderr`.

Invalid cases include:

- duplicate numbers;
- non-numeric arguments;
- numbers larger than `INT_MAX`;
- numbers smaller than `INT_MIN`;
- empty arguments;
- whitespace-only arguments;
- unknown flags;
- a strategy or benchmark flag without any integers.

Examples:

```bash
./push_swap 1 1
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 hello 3
./push_swap ""
./push_swap "    "
./push_swap --unknown 3 2 1
./push_swap --simple
```

---

# Algorithms

Complexity is measured by the number of Push_swap operations we generate. CPU work used only to decide which operations to perform is not counted.

## Disorder metric

Before sorting, we calculate how disordered the input is.

For every pair of values `(i, j)` where `i < j`, an inversion exists when:

```text
a[i] > a[j]
```

Disorder is:

```text
number of inversions / total number of pairs
```

The result is between `0` and `1`:

- `0.0` → completely sorted
- `1.0` → completely reverse sorted

We compute this before any sorting operation is performed.

---

## Indexes

Before the main sorting strategies run, every value gets an index representing its rank.

For example:

```text
40  -5  12  100
```

becomes conceptually:

```text
2   0   1   3
```

This lets the algorithms work with indexes from `0` to `n - 1` instead of depending on the original integer values.

---

## Simple strategy — O(n²)

The Simple strategy uses a Longest Increasing Subsequence (LIS) together with cheapest insertion.

### Step 1 — Find the LIS

We use an O(n²) dynamic-programming algorithm to find a longest increasing subsequence. Values in that subsequence are marked with the `keep` field in each stack node.

### Step 2 — Push other values to stack B

Values in the LIS stay in stack `a`. Everything else is pushed to stack `b`.

### Step 3 — Cheapest insertion

For each value in `b`, we check:

- how much `a` must rotate;
- how much `b` must rotate;
- whether both stacks can rotate together with `rr`;
- whether both can reverse rotate together with `rrr`.

We pick the cheapest move and push the value back to `a`.

### Step 4 — Final rotation

Once all elements are back in `a`, we rotate so the minimum element ends up on top.

### Complexity

Each inserted element may require up to O(n) operations, and there are up to O(n) such elements:

```text
O(n) × O(n) = O(n²)
```

---

## Medium strategy — O(n√n)

The Medium strategy is chunk-based.

We set:

```text
chunk size ≈ √n
```

and divide values into ranges using their indexes.

### Push phase

Values whose indexes belong to the current allowed range are pushed from `a` to `b`. Other values are rotated in `a` until an eligible value reaches the top. The allowed range grows as values are pushed. Some values in `b` are rotated to keep larger values in useful positions.

### Return phase

We locate the largest value in `b`, rotate `b` in the shorter direction until it reaches the top, then push it back to `a`. This continues until `b` is empty.

### Complexity

With a chunk size around √n, we can process the input in about √n ranges. Each range may require O(n) stack operations, so the operation complexity is bounded by:

```text
O(n√n)
```

---

## Complex strategy — O(n log n)

The Complex strategy uses binary LSD radix sort.

After converting every value to its index, we process each bit of those indexes, starting from the least significant:

- if the bit is `1`, use `ra`;
- if the bit is `0`, use `pb`.

After one full pass through `a`, all values in `b` are pushed back with `pa`. We repeat this for each bit needed to represent the largest index.

The number of required bits is roughly:

```text
log₂(n)
```

Each bit needs at most O(n) pushes and rotations, so:

```text
O(n) × O(log n) = O(n log n)
```

in the Push_swap operation model.

---

# Adaptive strategy

Adaptive mode chooses one of the three strategies based on the disorder computed before sorting.

| Disorder | Strategy | Complexity |
|---|---|---|
| `< 0.2` | Simple | O(n²) |
| `0.2 ≤ disorder < 0.5` | Medium | O(n√n) |
| `≥ 0.5` | Complex | O(n log n) |

The choice depends only on the disorder value. Input size does not override an explicitly selected strategy.

For example:

```bash
./push_swap --complex 3 2 1
```

still runs the Complex strategy, and:

```bash
./push_swap --medium 3 2 1
```

runs Medium, regardless of how many elements you pass.

---

# Benchmark mode

Benchmark mode is enabled with:

```bash
--bench
```

Example:

```bash
./push_swap --bench --adaptive 3 2 1
```

Operations still go to `stdout`. Benchmark info goes only to `stderr`.

To hide operations and show only benchmark info:

```bash
./push_swap --bench --adaptive 3 2 1 > /dev/null
```

Example output:

```text
[bench] disorder: 100.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 10
[bench] sa: 0 sb: 0 ss: 0 pa: 4 pb: 4
[bench] ra: 2 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

Benchmark mode reports:

- disorder percentage with two decimal places;
- selected strategy;
- theoretical complexity;
- total number of operations;
- how many times each operation was used.

---

# Performance

The subject requires:

| Input size | Passing limit |
|---|---:|
| 100 random integers | less than 2000 operations |
| 500 random integers | less than 12000 operations |

Recent tests after the final fixes produced:

| Input | Checker | Operations |
|---|---|---:|
| 100 random integers | `OK` | 1084 |
| 500 random integers | `OK` | 6519 |

Example test:

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

For 500 values:

```bash
ARG=$(shuf -i 0-99999 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

We also ran:

```bash
norminette
```

and:

```bash
valgrind --leak-check=full --show-leak-kinds=all
```

The tested paths finished with:

```text
in use at exit: 0 bytes in 0 blocks
ERROR SUMMARY: 0 errors
```

---

# Contributions

## hcherif

- stack data structure and stack helper functions;
- argument parsing and integer validation;
- overflow and duplicate checks;
- swap, push, rotate and reverse-rotate operations;
- small-stack helper functions;
- radix sorting strategy;
- strategy flag parsing;
- initial Makefile implementation.

## gbekur

- `t_ctx` structure and operation counters;
- `sb`, `ss`, `rr` and `rrr`;
- benchmark mode and per-operation statistics;
- disorder calculation;
- combined flag handling;
- Medium chunk-based strategy;
- Simple LIS and cheapest-insertion strategy;
- Adaptive strategy selection;
- testing and debugging;
- Norminette and Valgrind checks;
- documentation.

Both of us reviewed the final implementation and can explain the whole project during evaluation.

---

# Resources

We used:

- the 42 Push_swap subject;
- 42 documentation and evaluation requirements;
- *Introduction to Algorithms* by Cormen, Leiserson, Rivest and Stein;
- Wikipedia articles on sorting algorithms, inversions, LIS, radix sort, and asymptotic complexity;
- `ft_ps_tester` for extra testing;
- Google Search for documentation and explanations.

---

How AI was used: Google Search AI Overview (used sometimes to understand a function before I started reproducing it, or to understand the difference between concepts while searching).