*This project has been created as part of the 42 curriculum by jferone, almanier.*

---
# DISCLAIMER
__@jferone — Learning & Engineering Protocol__

**Alongside 42’s curriculum**,  
I develop an experimental learning methodology focused on **cognitive architecture and system supervision**,  
applied to my work on 42 projects, which I call **Triadic Intelligence**.

1. **Human Architects** (`jferone` & `almanier`)  
   Responsible for:
   - problem understanding and decomposition,
   - architectural decisions and invariants,
   - algorithmic reasoning and trade-offs,
   - validation, explanation, and full ownership of the final code.

2. **Crystallization AI** (LLM tools)  
   Used exclusively for:
   - analysis support,
   - clarification of concepts,
   - methodological refinement.

3. **Iterative Worker AI** (optional, controlled)  
   Used only for:
   - execution of **fully understood and validated** tasks,
   - under strict human supervision.

All logic, architecture, and final implementations are **designed, understood, and justified by the human architects**,  
who remain fully capable of explaining, maintaining, and defending every line of code.

/!\ This methodology is **not a shortcut** and does **not replace learning**.  
/!\ Its objective is not dependency on AI tools.  
/!\ It aims to develop **robust cognitive discipline, architectural rigor, and long-term supervision capability**.

__Architecture first. Understanding always. Autonomy preserved.__
---

# DESCRIPTION

**Push_Swap** is an algorithmic C project focused on sorting a stack of unique integers using **only two stacks** (`a` and `b`) and a **strictly limited set of operations**.

The program must output the **shortest possible sequence of instructions** that sorts the stack in ascending order.

## Core Concepts

```markdown
- Stack-based algorithms
- Algorithmic complexity and optimization
- Constraint-driven problem solving
- Linked lists and pointer manipulation
- Memory management without leaks
```

## Bonus

The bonus part introduces a **checker** program that reads a sequence of operations from standard input and verifies whether the stack is correctly sorted at the end.

## Usage

```bash
make
./push_swap 3 2 1
```

With checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```
