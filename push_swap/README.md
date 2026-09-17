*This project has been created as part of the 42 curriculum by gbekur, hcherif.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks, `a` and `b`, and a fixed set of 11 operations. The program prints the sequence of operations that sorts stack `a` in ascending order, with the smallest number on top. The goal is to use as few operations as possible.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | move the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate up: the first element becomes the last (`a` / `b` / both) |
| `rra` / `rrb` / `rrr` | rotate down: the last element becomes the first (`a` / `b` / both) |

The program has four sorting strategies, each in a different complexity class. It measures how disordered the input is before making any move, and it can report statistics about each run.

## Instructions

### Build

```bash
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes object files and the binary
make re     # full rebuild
```

It compiles with `cc -Wall -Wextra -Werror`.

### Run

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers>
```

- The first integer is the top of stack `a`.
- Flags must come before the numbers. `--adaptive` is the default.
- Numbers can be separate arguments (`3 2 1`) or one quoted argument (`"3 2 1"`).
- With no arguments, or with input that is already sorted, nothing is printed.
- Invalid input prints `Error` followed by a newline on stderr. Invalid input includes non-integers, values outside the `int` range, duplicates, empty arguments and unknown flags.

| Flag | Strategy |
|---|---|
| `--simple` | O(n²): longest increasing subsequence + cheapest insertion |
| `--medium` | O(n√n): chunk-based partitioning |
| `--complex` | O(n log n): radix sort |
| `--adaptive` | picks one of the above based on the measured disorder |
| `--bench` | after sorting, prints statistics to stderr |

### Examples

```bash
./push_swap 2 1 3 6 5 8
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
```

Benchmark output goes to stderr, so the operations on stdout can still be piped to a checker:

```bash
$ ./push_swap --bench 4 67 3 87 23 >/dev/null
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n*sqrt(n))
[bench] total_ops: 9
[bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 4 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

## Algorithms

All costs below are counted in push_swap operations, as the subject requires, not in CPU steps. `n` is the number of integers.

### Disorder metric

Disorder is the fraction of pairs `(i, j)` with `i < j` where `a[i] > a[j]`. Every pair is visited once, so the total number of pairs is `n(n-1)/2` and only the inversions need counting. It is computed before any move. It costs 0 operations and O(n²) CPU time.

### Shared building blocks

- **Ranks.** Before most strategies run, each value is replaced by its rank from `0` to `n-1` (`assign_indexes`). Algorithms then work with a compact range whatever the original numbers are, including negatives and `INT_MIN`/`INT_MAX`.
- **Small stacks (n ≤ 5).** All strategies use `sort_small` here: rotate the minimum to the top by the shorter direction, push it to `b`, and repeat until 3 values remain. Those 3 are sorted with at most 2 operations, then everything is pushed back. The worst case measured over all 120 permutations of 5 values is 10 operations.
- **Operation counting.** Global variables are forbidden, so one context structure (`t_ctx`) holds both stacks, the mode, the disorder and a counter for each operation. Every operation passes through `write_op`, which increments the counter and prints. `ss`, `rr` and `rrr` change both stacks but are printed and counted as one operation.

### Simple: O(n²), longest increasing subsequence + cheapest insertion

1. Compute a longest increasing subsequence (LIS) of the ranks with an O(n²) dynamic-programming pass. These values are already in the right order relative to each other, so they stay in `a`.
2. Walk through `a` once: rotate past values in the LIS and push every other value to `b`.
3. While `b` is not empty, look at every value in `b`. For each one, compute the rotations of `b` that bring it to the top and the rotations of `a` that bring its target to the top. The target is the smallest value in `a` greater than it, or the minimum of `a` if nothing is greater. Four combinations are possible: both up, both down, `a` up with `b` down, and `a` down with `b` up. Rotations in the same direction are merged into `rr`/`rrr`. Apply the cheapest combination, then `pa`.
4. Rotate `a` so the minimum is on top.

**Time.** Step 2 costs at most `n` operations. Let `m` be the number of values outside the LIS. Each of the `m` insertions costs at most `|a| + |b| ≤ n` rotations plus one `pa`. The final rotation costs at most `n/2`. Total: `n + m(n+1) + n/2` = **O(n·m) ⊆ O(n²)**.
**Space.** O(n): four integer arrays for the LIS, freed before any move, plus a `keep` flag in each node.

**Why this method for low disorder.** It only moves the values that break the increasing order. At low disorder most values are already in increasing order, so `m` is small and the cost stays close to linear.

### Medium: O(n√n), chunk-based partitioning

1. Let `k = ⌈√n⌉`, and keep a counter `pushed` of how many values are already in `b`.
2. While `a` is not empty: if the top rank is below `pushed + k`, push it to `b`. If it is also smaller than the value under it, `rb`, so larger values stay near the top of `b`. Otherwise `ra`.
3. While `b` is not empty: rotate the maximum of `b` to the top by the shorter direction, then `pa`.

**Time.** Every value pushed to `b` has a rank below the current window `pushed + k`. So at any moment exactly `min(k, |a|)` values in `a` qualify for pushing. A full rotation through `a` pushes all of them, so the push phase needs at most `⌈n/k⌉ ≈ √n` full rotations of at most `n` operations each: **O(n√n)**. In the pop phase, values leave `b` in decreasing order. Because values were pushed in increasing windows and the `rb` step splits each window between the top and the bottom of `b`, the next maximum lies within about `k` positions of an end of `b`. That gives **O(n√n)** for the pop phase too.
**Space.** O(n): the two stacks.

**Why this method for medium disorder.** Chunking uses the partial order in the input without paying for a full radix pass.

### Complex: O(n log n), LSD radix sort on ranks

For each bit of the ranks, from least to most significant: go through `a` once, sending ranks with a `0` bit to `b` (`pb`) and rotating past ranks with a `1` bit (`ra`). Then push everything back (`pa`). After the last bit, `a` is sorted.

**Time.** There are `⌈log₂ n⌉` passes. Each pass costs exactly `n` operations, plus at most `n` `pa`. Total at most `2n⌈log₂ n⌉` = **O(n log n)**: 1084 operations for 100 values and 6784 for 500, whatever the input order. The measured growth is shown under Performance.
**Space.** O(n): the two stacks and the rank stored in each node.

**Why this method for high disorder.** The cost does not depend on how the input is arranged, so it guarantees the O(n log n) bound when the input has no useful order to exploit.

### Adaptive

| Measured disorder | Method | Class |
|---|---|---|
| `< 0.2` | Simple (LIS + cheapest insertion) | O(n²) |
| `0.2 ≤ d < 0.5` | Medium (√n chunks) | O(n√n) |
| `≥ 0.5` | Complex (radix) | O(n log n) |

Stacks of 5 or fewer values always use `sort_small`.

**Why these thresholds.** The subject sets the thresholds and the complexity class required for each regime. Each regime uses the method that fits it best:
- **Below 0.2**, at most 20% of pairs are inverted, and usually only a small share of the values are misplaced. Keeping the LIS in place and inserting only the other values is cheap. On 500 values with 15–20% disorder it averages 2679 operations.
- **Between 0.2 and 0.5**, much less of the order can be reused. Chunking uses what partial order remains and has a better worst-case guarantee than O(n²).
- **At 0.5 and above**, the input has little usable order, which is about what random input looks like. Radix gives a fixed O(n log n) cost however the input is arranged.

The insertion method often uses fewer operations than radix at the sizes tested here, 100 to 500 values. Its worst case is still O(n²), while radix is O(n log n) in every case, and the subject asks each regime for a method within its complexity class.

## Performance

Results from [ft_ps_tester](https://github.com/italoalmeida0/ft_ps_tester), 100 runs per row. Its generated disorder ranges are: simple 15–19.9%, medium 20–49.9%, complex 50–55%, adaptive 15–55%.

| Size | Mode | Max | Min | Average | Fails |
|---|---|---|---|---|---|
| 100 | simple | 408 | 244 | 341 | 0 |
| 100 | medium | 683 | 438 | 593 | 0 |
| 100 | complex | 1084 | 1084 | 1084 | 0 |
| 100 | adaptive | 1084 | 266 | 628 | 0 |
| 500 | simple | 3319 | 2164 | 2679 | 0 |
| 500 | medium | 6916 | 4240 | 5650 | 0 |
| 500 | complex | 6784 | 6784 | 6784 | 0 |
| 500 | adaptive | 6784 | 2192 | 5439 | 0 |

On uniformly random input over the full `int` range (300 runs per size, default mode), disorder stays close to 50%. So the adaptive strategy mostly picks chunks or radix:

| Size | Max | Average | Under excellent limit | Over pass limit |
|---|---|---|---|---|
| 100 | 1084 | 864.5 | 152 / 300 (< 700) | 0 |
| 500 | 6784 | 6630.0 | 0 / 300 (< 5500) | 0 |

Subject targets: 100 values under 2000 to pass (under 700 excellent); 500 values under 12000 to pass (under 5500 excellent). The same tester also confirmed correct error handling, 0 operations on sorted input, accurate disorder percentages in `--bench`, and no memory leaks.

### Measured growth of the complex strategy

The tester's `--big-o` mode labels a strategy O(n log n) only if it uses at most `1.14 × n log₂ n` operations at n = 800. Radix uses about `1.6 × n log₂ n`, so the tester files it under the next class. That check measures the constant factor, not the growth rate. The growth rate is what shows the complexity class: when n doubles, an O(n log n) cost grows by `2(log₂ n + 1) / log₂ n`, and an O(n√n) cost grows by `2√2 ≈ 2.83`. Measured over 100 runs per size:

| n | Avg operations | Measured ratio | O(n log n) predicts | O(n√n) predicts |
|---|---|---|---|---|
| 50 | 467 | | | |
| 100 | 1084 | 2.32× | 2.35× | 2.83× |
| 200 | 2468 | 2.28× | 2.30× | 2.83× |
| 400 | 5536 | 2.24× | 2.26× | 2.83× |
| 800 | 12272 | 2.22× | 2.23× | 2.83× |

The measurements follow the O(n log n) prediction at every size.

## Contributions

- **hcherif**: stack data structure and helpers; argument parsing and integer validation, including overflow and duplicate checks; the original swap, push, rotate and reverse-rotate operations; small-stack sort; radix sort; strategy flag parsing; initial Makefile.
- **gbekur**: `t_ctx` refactor and per-operation counting; the missing `sb`, `ss`, `rr`, `rrr` operations; combined flag parsing with `--bench`; disorder metric; benchmark report; medium (chunk) strategy; simple (LIS + cheapest insertion) strategy; adaptive dispatcher; testing, norm compliance and documentation.

## Resources

- D. E. Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*: sorting methods and inversions.
- T. H. Cormen, C. E. Leiserson, R. L. Rivest, C. Stein, *Introduction to Algorithms*: asymptotic notation, insertion sort, radix sort, dynamic programming.
- Wikipedia articles: "Inversion (discrete mathematics)", "Longest increasing subsequence", "Radix sort".
- [ft_ps_tester](https://github.com/italoalmeida0/ft_ps_tester): the test suite used for correctness, benchmarks and leak checks.

### Use of AI

Claude (Anthropic) was used as an assistant for these tasks:
- comparing the existing code with this version of the subject and listing the missing requirements;
- designing the `t_ctx` structure used to count operations without global variables;
- writing the disorder metric, the `--bench` report, combined flag parsing, the medium strategy and the LIS-based simple strategy;
- finding the cause of tester failures on low-disorder inputs, which led to replacing a selection sort with the LIS-based method;
- regenerating the 42 headers and drafting this README.

Every change was checked with `norminette`, `cc -Wall -Wextra -Werror`, the ft_ps_tester suite and leak checks.
