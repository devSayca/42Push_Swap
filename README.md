*This project has been created as part of the 42 curriculum by jferone, almanier*.

---
# DESCRIPTION

This project asks us to reorganize the stack `*a` with 11 **restricted operations** : `3 pushes ; 2 swaps ; 3 rotates ; 3 reverse-rotates`.

We need to sort these numbers really fast, with only two stacks as the following :

> stack **a** : `int 1` `int 2` `int n`

> stack **b** : `(empty)`


## Operations

#### 1. **Swaps**

- **sa** - `swap a` : swap the first two elements at the top of stack a.

- **sb** - `swap b` : same operation for stack b.

- **ss** - `"swap-swap"` : sa & sb combined in one operation. *Economical.*



#### 2. **Pushes**

- **pa** - `push to a` : push the top of *b to the top of *a.
*Does nothing if **b** is empty.*

- **pb** - `push to b` push the top of *a to the top of *b.
*Does noting if **a** is empty.*



#### 3. **Rotations (top to bottom)**

- **ra** - `rotate a` : shift up all elements of stack *a by one.
*The first element becomes the last one.*

- **rb** - `rotate b` : shift up all elements of stack *a by one.
*The first element becomes the last one.*

- **rr** - `"rotate-rotate"` : ra & rb combined in one operation. *Economical.*



#### 4. **Reverse-rotations (bottom to top)**

- **rra** - `reverse rotate a` : Shift down all elements of stack *a by one.
*The last element becomes the first one.*

- **rrb** - `reverse rotate b` : Shift down all elements of stack *b by one.
*The last element becomes the first one.*

- **rrr** - `"rotato-rotato"` : rra and rrb at the same time. *Economical.*


---
## `PushSwap` ADDITIONNAL SECTION

A **few methods** exists, so we choosed 4 specific algorithms for the 4 following modes.


### Technical choices and explainations

### 1. `--simple`
#### Insertion Sort

Forces the use of our `O(n square2) complexity` algorithm.

**Aims to** solve small stacks with iterative minimum insertion strategy.


### 2. `--medium`
#### Chunks Sort algorithm

Forces the use of our `O(n√n) complexity` algorithm.

**Aims to** solve medium stacks with range-based  partitioning algorithm dividing the stack into √n buckets to reduce rotation costs.


### 3. `--complex`
#### Turk Greedy Cost algorithm

Forces the use of our `O(n log n) complexity` algorithm

**Aims to** solve heavy stacks by cost-minimizing greedy heuristic calculating the optimal path for each element.


### 4. `--adaptive` (default mode if no flag)
#### Hybrid Heuristic Dispatcher

Forces the use of our `decision meta-algorithm` based on **disorder calculation**.

##### Disorder ratio calculation
- `Disorder < 0.2` : Linear Sort (Insertion sort)
- `0.2 =< Disorder < 0.5` : Chunk Sort
- `0.5 =< Disorder` : Complex Sort (Turk algo.)

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

## **TEAMWORK REPARTITION**

- Global architecture.
- Global debugging & troubleshots.

> **`jferone`** focused on...
- Composition: README, Makefile, Headers.
- exemple

> **`almanier`** focused on...
- exemple
- exemple

### **USAGE EXEMPLES**

- 
- 
- 

### **FEATURE LIST**

- PushSwap flags : `--simple` ; `--medium` ; `--complex` ; `--adaptive` ; `--benchmark`





# INSTRUCTIONS



# RESOURCES




# LLM USAGE

0. **No AI** used to replace human intelligence & cognition.

1. **No AI** for Readme, Makefile, Headers, Source codes.

2. **No AI** for debugs or code completion. 

3. **AI used for** deepening research on existing mathematical algorithms, and manipulation of non-mastered mathematical theory.

4. **Advanced cross-AI collaboration** for exploring and learning some mathematical "super-algorithms" and post-bonus possibilities.



