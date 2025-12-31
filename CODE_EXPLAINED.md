# Code Explanation: Ultimate Task Manager v1.0

This document provides a component-level breakdown of the Task Management System source code.

## 1. Architecture Overview

The system is built on two primary pillars:
1.  **The Priority Queue Backend**: Pure C logic using a Singly Linked List to store and manage tasks.
2.  **The Rendering Engine**: A custom-built UI layer that handles ANSI colors, alignment math, and layout management.

---

## 2. Rendering Engine Logic

The unique feature of this project is its "Math-Proof" alignment. Unlike standard `printf`, we calculate padding dynamically.

### `UI_WIDTH` Constant
Defined as `60`, this is the anchor for all calculations. Every single line of output inside the box is guaranteed to be exactly 60 characters wide.

### `print_centered(text)`
Calculates padding to center any string within the box:
```c
int padding_l = (UI_WIDTH - len) / 2;
int padding_r = UI_WIDTH - len - padding_l;
```
This ensures that `Padding Left + Text Length + Padding Right` always equals `UI_WIDTH`.

### `print_row(label, value)`
Used for key-value pairs like "PENDING TASKS ...... 5".
It calculates the exact number of dots needed to fill the gap between the label and the value:
```c
int dots = 56 - len_label - len_val;
```
The constant `56` comes from `UI_WIDTH (60)` minus the default padding spaces (4).

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
