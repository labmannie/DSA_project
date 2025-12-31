# Ultimate Task Manager v1.0 🚀

![License](https://img.shields.io/badge/license-MIT-blue.svg) ![Language](https://img.shields.io/badge/language-C-orange.svg) ![Course](https://img.shields.io/badge/course-DSA-green.svg)

A high-performance, vibrant **Command Line Interface (CLI)** Task Management System built for the **Data Structures and Algorithms** course. This project demonstrates the robust implementation of a **Priority Queue** using a **Singly Linked List**.

---

## 🌟 Key Features

-   **Priority Queue ADT**: Implements core queue operations with priority-based ordering.
-   **Math-Proof Aligned UI**: A custom rendering engine ensures perfect alignment of borders and text, regardless of content length.
-   **Vibrant Dashboard**: Uses a neon-cyberpunk aesthetic with calculated layouts for a "Control Deck" feel.
-   **Input Validation**: Strict enforcement of priority range (1-100) to prevent errors.
-   **Zero Dependencies**: Pure C implementation requiring only standard libraries.

---

## 🛠️ Data Structures Used

We chose a **Linked List** implementation for the Priority Queue to prioritize simplicity and dynamic memory safety.

-   **Node Structure**: Contains the Task ID, Priority, Title, and a pointer to the next node.
-   **Algorithm**:
    -   **Enqueue**: O(N) - Insertions are automatically sorted; the list is traversed to find the correct insertion point to maintain descending priority order.
    -   **Dequeue**: O(1) - The head node always represents the highest-priority task, allowing constant-time removal.

---

## 🚀 Getting Started

### Prerequisites
-   GCC Compiler (MinGW for Windows, standard gcc for Mac/Linux)
-   Terminal/Command Prompt

### Compilation
Run the following command in your terminal:

```bash
gcc main.c -o task_manager
```

### Running the App
Execute the generated binary:

```bash
./task_manager
```

---

## 🎮 How to Use

1.  **Create New Task**: Select Option 1. Enter a Priority (1-100) and a Title.
    -   *Higher number = Higher Priority*.
    -   The system auto-sorts it into position.
2.  **Process Highest Priority**: Select Option 2. This executes and removes the most critical task.
3.  **Visualize Queue Chain**: Select Option 3. View the entire list of pending items in a structured table.

---

## 👥 Group Members (Team F15)

-   **Sourabh**: 4NI24CI108
-   **Shreyas J**: 4NI24CI104
-   **Dimpu K J**: 4NI23CI040
-   **Harsh vardhan**: 4NI24CI123

---

## 📝 License
This project is open source and available for educational purposes.
