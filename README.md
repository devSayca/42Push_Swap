*This project has been created as part of the 42 curriculum by jferone, almanier*.
---
# DISCLAIMER

Alongside 42’s curriculum, we deliberately approached this project as a
**system architecture and supervision exercise**, rather than a simple sorting problem.

- **Human Architects** (`jferone`, `almanier`) are fully responsible for problem decomposition,
architectural decisions, algorithmic choices, and the ability to explain and justify the complete system.
- **Crystallization AI** (LLM tools) is used strictly as an analytical aid: concept clarification,
structural review, and methodological questioning.
- **Iterative worker AI**, when used, operates only on tasks that have been entirely understood,
validated, and specified by the human architects for deadline efficiency.

This protocol is **not a shortcut** and **does not replace learning**.  
Its purpose is to reinforce **architectural rigor, systemic reasoning, and long-term autonomy in supervising complex systems**.

__Architecture first. Understanding before execution.__
---

# Description

**Push_Swap** is treated in this project as a **constrained mechanical system**, not as a traditional sorting task.

The program behaves like a **blind mechanical arm** operating on numbered objects stored in **two vertical stacks** (`a` and `b`).  
The system has no direct access to global order or absolute positions; it can only perform a **fixed and limited set of mechanical movements**.

The objective is therefore not to "place" values directly, but to **design a sequence of state transitions** that causes an ordered configuration to **emerge mechanically** from an initially disordered one.

The quality of the solution is measured by the **efficiency of this movement sequence**, expressed as the number of operations required.
Push_Swap is therefore approached as a deterministic machine whose behavior must be fully predictable, explainable, and controlled.

## Core Concepts

```markdown
- Stack-based mechanics and state transitions
- Algorithmic optimization under strict constraints
- Systemic thinking (movement over direct placement)
- Linked lists and pointer manipulation
- Memory management without leaks
```

## Bonus

The bonus introduces a **checker** program acting as a replay engine: it executes a sequence of movements and verifies whether the resulting system state satisfies the sorting invariant.

# Instructions

### Compilation

```bash
make
```

### Execution

```bash
./push_swap 3 2 1
```

With checker:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

# Resources

- 42 subject: Push_Swap (official PDF)
- Stack manipulation and constrained sorting algorithms
- Radix sort (binary) applied to indexed data
- AI usage: LLM tools were used **only** for conceptual clarification, architecture review, and documentation refinement