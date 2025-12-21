*This document defines the internal collaboration and engineering constraints applied by **jferone** and **almanier**.*

# Internal Engineering Contract — Push_Swap

This document defines the internal engineering rules agreed upon by `jferone` and `almanier`
to guarantee clarity, consistency, and maintainability of the project.

## 1. Architectural Invariants

- Strict separation between:
  - `op_*` functions: apply stack operations without any output.
  - `do_*` functions: call `op_*` and emit the corresponding instruction.
- Parsing logic is strictly isolated from stack manipulation and sorting logic.
- No global variables are allowed.

## 2. Code Constraints reminder

- Maximum 25 lines per function
- Maximum 5 functions per source file (static functions included)
- Ternary operators and operations not fully mastered by `jferone` & `almanier` are strictly forbidden
- All errors must result in `Error\n` on stderr and immediate exit

## 3. File Responsibility

- Each `.c` file has a single, clearly defined responsibility
- If a file reaches its function limit, logic must be split into a new file
- No file may contain mixed concerns (e.g. parsing and stack logic)

## 4. Collaboration Rules

- Every part of the code must be explainable by both architects
- No code is merged without mutual review
- AI tools may assist analysis and execution only after full human understanding and validation

## 5. Project Philosophy reminder

Push_Swap is treated as a constrained mechanical system.
Correctness, predictability, and explainability are valued over micro-optimizations.