# Code Explanation: Ultimate Task Manager v1.0

This document provides a component-level breakdown of the Task Management System source code.

## 1. Architecture Overview

The system is built on two primary pillars:
1.  **The Priority Queue Backend**: Pure C logic using a Singly Linked List to store and manage tasks.
2.  **The Rendering Engine**: A custom-built UI layer that handles ANSI colors, alignment math, and layout management.

---

## 2. Visual Presentation

The interface prioritizes stability and exact formatting over dynamic resizing.

### Static Layouts
To eliminate calculations and potential alignment bugs during runtime, the specific borders, spacing, and headers are **hardcoded**. This ensures that the application always looks exactly as intended, with a fixed width of 60 characters.

### Inline Logic
For dynamic rows (like task lists), we perform simple inline calculations to ensure dot leaders (`....`) fill the remaining space perfectly:
```c
int dots = 56 - strlen(label) - strlen(value);
```
This keeps the code simple and predictable.

---

## 3. Data Structure: Priority Queue

We use a **Linked List** instead of an Array or Heap for simplicity and dynamic sizing.

### `enqueue(priority, title)` - O(N)
We perform a **Sorted Insert**. When a new task arrives:
1.  We iterate through the list starting from `head`.
2.  We look for the first node that has a *lower* priority than our new task.
3.  We insert our new task *before* that node.

This ensures the list is **Always Sorted**, meaning the highest priority task is always at the `head`.

### `dequeue()` - O(1)
Because the list is always sorted, the most important task is simply `head`.
1.  Store the data from `head`.
2.  Move `head` pointer to `head->next`.
3.  `free()` the old head memory.
4.  Return the data.

---

## 4. Input Validation

In `main()`, we use a robust `do-while` loop for priority input:
```c
do {
  // check scanf result AND range logic
} while (p < 1 || p > 100);
```
This prevents the UI from breaking if a user enters "abc" or "999".

---

## 5. Visual Design (ANSI Codes)

We use extensive ANSI escape codes to create a "Neon" look.
-   `\033[38;5;51m`: Cyber Cyan
-   `\033[38;5;213m`: Hot Pink/Magenta
-   Box Drawing Characters (`╔`, `║`, `╚`): Creating the solid borders.

This combination results in a terminal interface that looks like a modern dashboard application.
