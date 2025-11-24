/**
 * ======================================================================================
 *  TASK MANAGEMENT SYSTEM - CORE DSA ENGINE (MAX HEAP)
 * ======================================================================================
 * 
 *  Author: Group F15
 *  Language: C
 *  Purpose: This program implements a Priority Queue using a Max Heap data structure.
 *           It is designed to be the "Brain" of our Task Management System.
 * 
 *  HOW IT WORKS:
 *  1. This C program runs in the background.
 *  2. The Node.js server sends commands to it (like "INSERT" or "EXTRACT").
 *  3. This program processes the command using the Heap logic.
 *  4. It prints the result back to the server in JSON format.
 * 
 *  DATA STRUCTURE USED: MAX HEAP
 *  - A Max Heap is a special tree-based data structure.
 *  - The "Parent" node is always greater than or equal to its "Children".
 *  - This ensures the HIGHEST PRIORITY task is always at the top (root).
 * 
 * ======================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- CONSTANTS ---
// We define these limits to keep the memory usage predictable.
#define MAX_TASKS 100       // Maximum number of tasks we can store
#define NAME_LENGTH 100     // Maximum length of a task name

/**
 * --- TASK STRUCTURE ---
 * In C, a 'struct' is like a custom data type.
 * Here, we define what a 'Task' looks like.
 */
typedef struct {
    int id;                 // Unique ID for the task (1, 2, 3...)
    char name[NAME_LENGTH]; // The description of the task (e.g., "Study")
    int priority;           // The urgency level (Higher number = Higher Priority)
} Task;

// --- GLOBAL VARIABLES ---
// These variables are accessible from anywhere in this file.
Task heap[MAX_TASKS];       // The Array that acts as our Heap
int heapSize = 0;           // Current number of tasks in the heap
int taskIdCounter = 1;      // Counter to give each task a unique ID

// --- FUNCTION PROTOTYPES ---
// We declare these functions here so the 'main' function knows they exist.
void insert(char* name, int priority);
Task extractMax();
Task peek();
void bubbleUp(int index);
void bubbleDown(int index);
void swap(int i, int j);
void printHeap();

/**
 * --- MAIN FUNCTION ---
 * The entry point of our program.
 * It sits in an infinite loop, waiting for commands.
 */
int main() {
    char command[50];
    char name[NAME_LENGTH];
    int priority;

    // IMPORTANT: Disable output buffering.
    // This ensures that when we print something, it is sent IMMEDIATELY.
    // Without this, Node.js might wait forever for the output.
    setbuf(stdout, NULL);

    // Infinite Loop: Keep reading commands until the program is stopped.
    // scanf reads the first word (the command) from Standard Input.
    while (scanf("%s", command) != EOF) {
        
        // COMMAND: INSERT <name> <priority>
        if (strcmp(command, "INSERT") == 0) {
            // Read the task name and priority number
            scanf("%s %d", name, &priority);
            
            // Call our insert function
            insert(name, priority);
            
            // Send success response in JSON format
            printf("{\"status\": \"success\", \"message\": \"Task added\"}\n");
        } 
        
        // COMMAND: EXTRACT (Remove the highest priority task)
        else if (strcmp(command, "EXTRACT") == 0) {
            if (heapSize == 0) {
                printf("{\"status\": \"error\", \"message\": \"Heap is empty\"}\n");
            } else {
                Task t = extractMax();
                printf("{\"status\": \"success\", \"task\": {\"name\": \"%s\", \"priority\": %d}}\n", t.name, t.priority);
            }
        } 
        
        // COMMAND: PEEK (Look at the highest priority task without removing it)
        else if (strcmp(command, "PEEK") == 0) {
            if (heapSize == 0) {
                printf("{\"status\": \"error\", \"message\": \"Heap is empty\"}\n");
            } else {
                Task t = peek();
                printf("{\"status\": \"success\", \"task\": {\"name\": \"%s\", \"priority\": %d}}\n", t.name, t.priority);
            }
        } 
        
        // COMMAND: PRINT (Show all tasks - for the Visualizer)
        else if (strcmp(command, "PRINT") == 0) {
            printHeap();
        }
    }

    return 0;
}

/**
 * --- HELPER: SWAP ---
 * Swaps two tasks in the heap array.
 * Used during Bubble Up and Bubble Down operations.
 */
void swap(int i, int j) {
    Task temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

/**
 * --- OPERATION: INSERT ---
 * Adds a new task to the Priority Queue.
 * 
 * Algorithm:
 * 1. Place the new task at the very END of the array.
 * 2. "Bubble Up" the task until it finds its correct spot.
 */
void insert(char* name, int priority) {
    if (heapSize >= MAX_TASKS) {
        return; // Heap is full, cannot add more
    }

    // 1. Create the new task
    Task newTask;
    newTask.id = taskIdCounter++;
    strcpy(newTask.name, name);
    newTask.priority = priority;
    
    // 2. Place it at the end of the array
    heap[heapSize] = newTask;
    
    // 3. Move it up to its correct position (Bubble Up)
    bubbleUp(heapSize);
    
    // 4. Increase the size counter
    heapSize++;
}

/**
 * --- ALGORITHM: BUBBLE UP ---
 * Moves a node UP the tree if it has higher priority than its parent.
 * This restores the Max Heap property after insertion.
 */
void bubbleUp(int index) {
    // While the node is not the root (index 0)...
    while (index > 0) {
        // Calculate Parent's index: (i - 1) / 2
        int parentIndex = (index - 1) / 2;
        
        // If Child's priority > Parent's priority...
        if (heap[index].priority > heap[parentIndex].priority) {
            // SWAP them! The child moves up.
            swap(index, parentIndex);
            
            // Update index to continue checking from the new position
            index = parentIndex;
        } else {
            // Parent is bigger (or equal), so we are done.
            break;
        }
    }
}

/**
 * --- OPERATION: EXTRACT MAX ---
 * Removes and returns the task with the HIGHEST priority (the Root).
 * 
 * Algorithm:
 * 1. Save the Root (index 0).
 * 2. Move the LAST element of the heap to the Root position.
 * 3. "Bubble Down" this new root until it fits.
 */
Task extractMax() {
    Task max = heap[0]; // Save the top task
    
    // 1. Move the last task to the top
    heap[0] = heap[heapSize - 1];
    heapSize--; // Decrease size
    
    // 2. Move it down to its correct position (Bubble Down)
    if (heapSize > 0) {
        bubbleDown(0);
    }
    
    return max;
}

/**
 * --- ALGORITHM: BUBBLE DOWN ---
 * Moves a node DOWN the tree if it has lower priority than its children.
 * This restores the Max Heap property after extraction.
 */
void bubbleDown(int index) {
    while (1) {
        int leftChild = 2 * index + 1;  // Formula for Left Child
        int rightChild = 2 * index + 2; // Formula for Right Child
        int largest = index;            // Assume current node is largest
        
        // Check if Left Child exists AND is bigger than current largest
        if (leftChild < heapSize && heap[leftChild].priority > heap[largest].priority) {
            largest = leftChild;
        }
        
        // Check if Right Child exists AND is bigger than current largest
        if (rightChild < heapSize && heap[rightChild].priority > heap[largest].priority) {
            largest = rightChild;
        }
        
        // If one of the children is bigger...
        if (largest != index) {
            swap(index, largest); // Swap with the larger child
            index = largest;      // Continue checking from there
        } else {
            // Current node is bigger than both children. We are done.
            break;
        }
    }
}

/**
 * --- OPERATION: PEEK ---
 * Simply returns the top task without removing it.
 */
Task peek() {
    return heap[0];
}

/**
 * --- HELPER: PRINT HEAP ---
 * Prints the entire heap array as a JSON object.
 * This is used by the Frontend to visualize the memory.
 */
void printHeap() {
    printf("{\"status\": \"success\", \"heap\": [");
    for (int i = 0; i < heapSize; i++) {
        printf("{\"name\": \"%s\", \"priority\": %d}", heap[i].name, heap[i].priority);
        if (i < heapSize - 1) printf(", ");
    }
    printf("]}\n");
}

