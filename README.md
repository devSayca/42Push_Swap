*This project has been created as part of the 42 curriculum by jferone, almanier*.

---
# DESCRIPTION

This project asks us to reorganize the stack `*a` with 11 **restricted operations** : `3 pushes ; 2 swaps ; 3 rotates ; 3 reverse-rotates`.

We need to sort these numbers really fast, with only two stacks as the following :

> stack **a** : `int 1` `int 2` `int n`

> stack **b** : `(empty)`

This program gives `user` the choice to select one of our **3 algo strategies**, or a **default adaptive strategy** wich can select the right algo based on the original's stack disorder calculation.

---

# ARCHITECTURE
### "Single Source of Truth" architecture type

```
.
│	# PROGRAM'S CONTRACT : Enumerations, Structures & Prototypes
├── push_swap.h
│
│	# ORCHESTRATION : Init, Flags, Check, Dispatch, Free
├── main.c 
│
│	# ALGORITHMS : Methods with the 3 imposed mathematical complexities
├── algo_simple.c		# O(n^2) complexity level	: Insertion logic
├── algo_medium.c		# O(n√n) complexity level	: Chunks logic
├── algo_complex.c		# O(nlogn) simulated level	: Greedy Cheapest Insertion logic
│
│	# MANAGERS : Program's brain
├── mgr_init.c			# Stack initialisation & argv parsing
├── mgr_checks.c		# Input validations
├── mgr_flags.c			# Flags management
├── mgr_metrics.c		# Disorder  & is_sorted (Mandatory & Bench)
├── mgr_strategy.c		# Dispatcher by flags or disorder calculation
├── mgr_benchmark.c		# Displaying stats in STDERR
│
│	# PUSHSWAP OPERATIONS : These operators are the only authorized to work on stacks *a & *b
├── ops_push.c			# pa, pb
├── ops_rotate.c		# ra, rb, rr
├── ops_rrotate.c		# rra, rrb, rrr
├── ops_swap.c			# sa, sb, ss
│
│	# UTILS : Cleaning & helping tools
├── utils_cleanup.c		# free_stack, free_all, error_exit
├── utils_cost.c		# cost calculator for our complex algorithm
├── utils_wrappers.c	# ft_atol & writers/wrappers
│
└── Makefile
```

## Operations

#### 1. Swaps - in-stack top-swap

- **sa** - `swap a` : swap the first two elements at the top of stack a.

- **sb** - `swap b` : same operation for stack b.

- **ss** - `"swap-swap"` : sa & sb combined in one operation. *Eco move.*



#### 2. Pushes - inter-stack transfers

- **pa** - `push to a` : push the top of *b to the top of *a.
*Does nothing if **b** is empty.*

- **pb** - `push to b` push the top of *a to the top of *b.
*Does nothing if **a** is empty.*



#### 3. Rotations - in-stack top-to-bottom

- **ra** - `rotate a` : shift up all elements of stack *a by one.
*The first element becomes the last one.*

- **rb** - `rotate b` : shift up all elements of stack *a by one.
*The first element becomes the last one.*

- **rr** - `"rotates"` : ra & rb combined in one operation. *Eco move.*



#### 4. Reverse-rotations - in-stack bottom-to-top

- **rra** - `reverse rotate a` : Shift down all elements of stack *a by one.
*The last element becomes the first one.*

- **rrb** - `reverse rotate b` : Shift down all elements of stack *b by one.
*The last element becomes the first one.*

- **rrr** - `"reverse-rotates"` : rra and rrb at the same time. *Eco move.*


---
## `PushSwap` ADDITIONNAL SECTION

A **few methods** exists, so we selected 4 specific algorithms for the 4 following modes.


### Technical choices and explanations

### 1. `--simple`
#### Insertion Sort algorithm

Forces the use of our `O(n square2) complexity` algorithm.

**Aims to** solve small stacks with iterative minimum insertion strategy.


### 2. `--medium`
#### Chunks Sort algorithm

Forces the use of our `O(n√n) complexity` algorithm.

**Aims to** solve medium stacks with range-based  partitioning algorithm dividing the stack into √n buckets to reduce rotation costs.


### 3. `--complex`
#### Greedy Cheapest Insertion algorithm

Forces the use of our `simulated O(n log n) complexity` algorithm

**Aims to** 


### 4. `--adaptive` (default mode if no flag)
#### Hybrid Heuristic Dispatcher

Forces the use of our `decision meta-algorithm` based on **disorder calculation**.

##### Disorder ratio calculation
- `Disorder < 0.2` : Insertion sort
- `0.2 =< Disorder < 0.5` : Chunk Sort
- `0.5 =< Disorder` : Greedy Cheapest Insertion sort

---
### Benchmark mode  (`--bench`)

The additionnal `--bench` flag displays :

- The computed disorder (% with two decimals).

- The name of the strategy used and its theoretical complexity class.

- The total number of operations.

- The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr)

The benchmark output is sent to stderr and only appear when the flag is present.

---

((( WORK IN PROGRESS FROM THIS MESSAGE ))) - temporary warning

## **TEAMWORK REPARTITION**

> **`common work`**
- Global debugs & troubleshots.
- Complex algo implementation.

> **`jferone`** focused on...
- Global source code architecture.
- README & headers composition.
- Medium algo implementation.
- Bench

> **`almanier`** focused on...
- Global architecture corrections, upgrades and validation.
- Operations code,  composition.
- Init, 
- Simple algo implementation.

### **USAGE EXAMPLES**

- Using
- 
- 

### **FEATURE LIST**

- PushSwap flags : `--simple` ; `--medium` ; `--complex` ; `--adaptive` ; `--benchmark`



# INSTRUCTIONS



# RESOURCES




# AI USAGE

1. **LLM used for** syntax checking, optimization research, and generating boilerplate documentation. 

2. **No LLM** for generating Readme, Makefile, Headers, Source codes.

3. **No LLM** for automatic debugs or code completion. 

4. **LLM used for** deepening research on existing mathematical algorithms, and manipulation of non-mastered mathematical theory.

5. **Advanced cross-LLM collaboration** for exploring and learning some mathematical "super-algorithms" and post-bonus possibilities.

6. **LLM used for** language and logical mistakes tracking throught project's building.
