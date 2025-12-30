# Ultimate Task Manager v4.0 🚀

![License](https://img.shields.io/badge/license-MIT-blue.svg) ![Language](https://img.shields.io/badge/language-C-orange.svg) ![Course](https://img.shields.io/badge/course-DSA-green.svg)

A high-performance, vibrant Command Line Interface (CLI) Task Management System built for the **Data Structures and Algorithms** course. This project demonstrates the implementation of a **Priority Queue** using a **Singly Linked List**.

---

## 🌟 Key Features

-   **Priority Queue ADT**: Strictly follows Enqueue/Dequeue terminology.
-   **Sorted Insertion**: Tasks are automatically kept sorted by priority (Highest First).
-   **Vibrant UI**: Uses ANSI escape codes for a stunning, colorful terminal experience.
-   **Visualizer**: Built-in option to visualize the actual node-chain structure (`[90] --> [50] --> [20]`).
-   **Zero Dependencies**: Pure C implementation (requires only Standard Library).

---

## 🛠️ Data Structures Used

We chose a **Linked List** implementation for the Priority Queue to prioritize simplicity and dynamic memory usage.

-   **Node Structure**: Contains the Task data and a pointer to the next node.
-   **Algorithm**:
    -   **Enqueue**: O(N) - Finds the correct position to maintain strictly descending order.
    -   **Dequeue**: O(1) - Always removes the head (highest priority).

---

## 🚀 Getting Started

### Prerequisites
-   GCC Compiler (MinGW for Windows, standard gcc for Mac/Linux)
-   Terminal/Command Prompt

### Compilation
Run the following command in your terminal:

```bash
gcc main.c -o dsa_project
```

### Running the App
Execute the generated binary:

```bash
./dsa_project
```

---

## 🎮 How to Use

1.  **Enqueue Task**: Select Option 1. Enter a Priority (1-100), Title, and Description.
    -   *Higher number = Higher Priority*.
2.  **Dequeue**: Select Option 2. This processes and removes the most important task immediately.
3.  **Visualizer**: Select Option 5. See exactly how your tasks are linked in memory.

---

## 👥 Group Members
*(Edit this section with your actual details)*

-   **Name 1**: [Your Roll No]
-   **Name 2**: [Roll No]
-   **Name 3**: [Roll No]
-   **Name 4**: [Roll No]

---

## 📝 License
This project is open source and available for educational purposes.
