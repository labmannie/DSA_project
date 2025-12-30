# 🎓 Code Explanation: Line-by-Line Breakdown
**For Viva & Presentation Prep**

This document explains the inner workings of `main.c`. Use this to understand exactly what is happening so you can answer any question from the external examiner!

---

## 1. Header Files (Lines 1-5)
```c
#include <stdio.h>  // For printf, scanf (Input/Output)
#include <stdlib.h> // For malloc, free (Memory Management)
#include <string.h> // For strcpy, strlen (String handling)
...
```
-   **Why?** These give us the basic tools we need. We use `malloc` because Linked Lists use dynamic memory (heap memory).

## 2. ANSI Colors (Lines 8-30)
```c
#define BOLD "\033[1m"
#define RED  "\033[31m"
...
```
-   **What?** These are "Escape Codes". When printed, the terminal changes color instead of showing text.
-   **Why?** To make the project look "Best Ever" and vibrant as requested!

## 3. Data Structures (Lines 34-58)

### The Task Struct
```c
typedef struct {
    int id;
    int priority;
    char title[TITLE_LEN]; ...
} Task;
```
-   Holds the actual data: ID, Priority, Title.

### The Node Struct
```c
typedef struct Node {
    Task task;
    struct Node* next;
} Node;
```
-   **Crucial Step**: This makes it a **Linked List**.
-   `next`: Points to the next task in the chain.

### The PriorityQueue Struct
```c
typedef struct {
    Node* head;
    int size; 
    ...
} PriorityQueue;
```
-   **Why?** Instead of just a global `head` variable, we wrap it in a struct. This is "Proper Coding Practice" for ADTs (Abstract Data Types). It allows us to pass `&pq` to functions.

---

## 4. Core Logic Functions

### `initQueue`
Sets `head = NULL`. This means the list starts empty.

### `enqueue` (THE MOST IMPORTANT FUNCTION)
**Goal**: Insert a new task but keep the list **SORTED** by priority (Highest -> Lowest).

**Logic Flow**:
1.  **Create Node**: `malloc(sizeof(Node))`.
2.  **Case 1 (Head Update)**:
    -   If the list is empty OR new priority > head priority.
    -   **Action**: New node becomes the NEW Head.
3.  **Case 2 (Traversal)**:
    -   If not Case 1, we must find the right spot.
    -   **Loop**: `while (current->next != NULL && current->next->task.priority >= priority)`
    -   We keep moving `current` forward as long as the next node is *more important* than our new one.
    -   **Insert**: Once we stop, we squeeze our new node in:
        ```c
        newNode->next = current->next;
        current->next = newNode;
        ```

### `dequeue`
**Goal**: Remove the highest priority task.
-   Because we sorted on insertion, **Highest Priority is ALWAYS at the Head**.
-   **Action**:
    1.  Save data of `head`.
    2.  Move head pointer: `head = head->next`.
    3.  `free(temp)` to prevent memory leaks!

---

## 5. Visualization Helper

### `visualizeQueue`
loops through the list and prints:
`[Priority] --> [Priority] --> NULL`
-   It changes color (Red/Yellow/Green) based on how high the priority number is.
-   This proves to the examiner you know how to traverse a linked list!

---

## 6. Main Function
-   Uses a `while(1)` loop (Infinite Loop) to keep the menu running until you choose "Exit".
-   `switch(choice)` handles the user input.
-   **Safety**: Uses `scanf("%d", &choice)` but checks if it failed to prevent infinite loops on bad input.

---
**Viva Tip**: If asked "Why Linked List over Array?", say: "Linked Lists allow O(1) Dequeue operations (removing from front) without shifting all other elements like an Array would require."
