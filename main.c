#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// --- ANSI COLORS & STYLES ---
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Neon / Vibrant Approximations intended for standard terminals
#define COLOR_TITLE BOLD CYAN
#define COLOR_HEADER BOLD MAGENTA
#define COLOR_ACCENT BOLD YELLOW
#define COLOR_SUCCESS BOLD GREEN
#define COLOR_ERROR BOLD RED
#define COLOR_BORDER BLUE
#define COLOR_MAGENTA BOLD MAGENTA

// --- DATA STRUCTURES ---
#define TITLE_LEN 50
#define DESC_LEN 200

// 1. Task Definition
typedef struct {
  int id;
  int priority;
  char title[TITLE_LEN];
  char description[DESC_LEN];
  time_t created_at;
} Task;

// 2. Node Definition (Linked List Node)
typedef struct Node {
  Task task;
  struct Node *next;
} Node;

// 3. Priority Queue Definition (ADT Wrapper)
typedef struct {
  Node *head;
  int size;
  int next_id;
} PriorityQueue;

// --- PROTOTYPES ---
void initQueue(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, int priority, const char *title,
             const char *description);
Task dequeue(PriorityQueue *pq);
void deleteById(PriorityQueue *pq, int id);
void printList(PriorityQueue *pq);
void printTask(Task t);
void visualizeQueue(PriorityQueue *pq);

void clearScreen();
void printBanner();
void waitForEnter();

// --- HELPER FUNCTIONS ---
void clearScreen() { printf("\033[H\033[J"); }

void waitForEnter() {
  printf("\n" DIM "Press [ENTER] to continue..." RESET);
  while (getchar() != '\n')
    ;
  getchar();
}

void printBanner() {
  clearScreen();
  printf(COLOR_BORDER "========================================================"
                      "========================" RESET "\n");
  printf(COLOR_TITLE);
  printf("   ____       _            _ _               \n");
  printf("  |  _ \\ _ __(_) ___  _ __(_) |_ _   _      \n");
  printf("  | |_) | '__| |/ _ \\| '__| | __| | | |     \n");
  printf("  |  __/| |  | | (_) | |  | | |_| |_| |     \n");
  printf("  |_|   |_|  |_|\\___/|_|  |_|\\__|\\__, |     \n");
  printf("   ___                        ___|___/      \n");
  printf("  / _ \\ _   _  ___ _   _  ___               \n");
  printf(" | | | | | | |/ _ \\ | | |/ _ \\              \n");
  printf(" | |_| | |_| |  __/ |_| |  __/              \n");
  printf("  \\__\\_\\\\__,_|\\___|\\__,_|\\___|              \n");
  printf("                                            \n");
  printf("          " COLOR_ACCENT "ULTIMATE TASK MANAGER v1.0" RESET "\n");
  printf(COLOR_BORDER "========================================================"
                      "========================" RESET "\n\n");
}

// --- PRIORITY QUEUE LOGIC ---

void initQueue(PriorityQueue *pq) {
  pq->head = NULL;
  pq->size = 0;
  pq->next_id = 1;
}

// Enqueue: Insert based on Priority (Highest First)
void enqueue(PriorityQueue *pq, int priority, const char *title,
             const char *description) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf(COLOR_ERROR "Memory Allocation Failed!" RESET "\n");
    return;
  }

  // Create Task
  newNode->task.id = pq->next_id++;
  newNode->task.priority = priority;
  strncpy(newNode->task.title, title, TITLE_LEN);
  strncpy(newNode->task.description, description, DESC_LEN);
  newNode->task.created_at = time(NULL);
  newNode->next = NULL;

  // Case 1: Queue is empty or new node has higher priority than head
  if (pq->head == NULL || pq->head->task.priority < priority) {
    newNode->next = pq->head;
    pq->head = newNode;
  } else {
    // Case 2: Traverse to find correct position (Sorted Insert)
    Node *current = pq->head;
    while (current->next != NULL && current->next->task.priority >= priority) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }

  pq->size++;
  printf(COLOR_SUCCESS "✔ Task Enqueued Successfully!" RESET "\n");
}

// Dequeue: Remove and return the Highest Priority Task (Head)
Task dequeue(PriorityQueue *pq) {
  Task empty;
  empty.id = -1;
  if (pq->head == NULL)
    return empty;

  Node *temp = pq->head;
  Task maxTask = pq->head->task;

  pq->head = pq->head->next;
  free(temp);
  pq->size--;

  return maxTask;
}

void deleteById(PriorityQueue *pq, int id) {
  if (pq->head == NULL) {
    printf(COLOR_ERROR "Queue is empty, nothing to delete." RESET "\n");
    return;
  }

  // Case 1: Head is the target
  if (pq->head->task.id == id) {
    Node *temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
    pq->size--;
    printf(COLOR_SUCCESS "✔ Task %d deleted." RESET "\n", id);
    return;
  }

  // Case 2: Search in the list
  Node *current = pq->head;
  while (current->next != NULL && current->next->task.id != id) {
    current = current->next;
  }

  if (current->next == NULL) {
    printf(COLOR_ERROR "Task with ID %d not found." RESET "\n", id);
  } else {
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    pq->size--;
    printf(COLOR_SUCCESS "✔ Task %d deleted." RESET "\n", id);
  }
}

// --- VISUALIZATION ---

void printTask(Task t) {
  printf(COLOR_BORDER "----------------------------------------" RESET "\n");
  printf(BOLD "ID: %d" RESET " | " COLOR_ACCENT "Priority: %d" RESET "\n", t.id,
         t.priority);
  printf(BOLD "Title: " RESET "%s\n", t.title);
  printf(DIM "%s" RESET "\n", t.description);
}

void visualizeQueue(PriorityQueue *pq) {
  if (pq->head == NULL) {
    printf(DIM "  (Empty Queue)" RESET "\n");
    return;
  }

  Node *temp = pq->head;
  int count = 0;
  while (temp != NULL) {
    // Colorize node based on priority
    char *nodeColor = WHITE;
    if (temp->task.priority > 80)
      nodeColor = RED;
    else if (temp->task.priority > 50)
      nodeColor = YELLOW;
    else
      nodeColor = GREEN;

    printf("  " BOLD "%s[%d | %s]" RESET, nodeColor, temp->task.priority,
           temp->task.title);

    if (temp->next != NULL) {
      printf(DIM " --> " RESET);
      // Wrap line if too long to keep it pretty
      if (++count % 3 == 0)
        printf("\n  " DIM "      |" RESET "\n  " DIM "      v" RESET "\n");
    } else {
      printf(DIM " --> NULL" RESET "\n");
    }

    temp = temp->next;
  }
}

// --- MAIN LOOP ---

int main() {
  PriorityQueue pq;
  initQueue(&pq);

  int choice;
  while (1) {
    printBanner();

    printf(BOLD "Highest Priority Task (Front of Queue):" RESET "\n");
    if (pq.head != NULL) {
      printf("  %s[%d] %s" RESET "\n", RED, pq.head->task.priority,
             pq.head->task.title);
    } else {
      printf("  %s(None)" RESET "\n", DIM);
    }
    printf("\n");

    printf(COLOR_HEADER "PRIORITY QUEUE MANGER:" RESET "\n");
    printf("  " COLOR_ACCENT "1." RESET " " BOLD "Enqueue Task" RESET "\n");
    printf("  " COLOR_ACCENT "2." RESET " " BOLD
           "Dequeue (Process Highest)" RESET "\n");
    printf("  " COLOR_ACCENT "3." RESET " " BOLD "Delete Specific Task" RESET
           "\n");
    printf("  " COLOR_ACCENT "4." RESET " " BOLD "View Queue Content" RESET
           "\n");
    printf("  " COLOR_ACCENT "5." RESET " " BOLD "Visualize Queue Chain" RESET
           "\n");
    printf("  " COLOR_ACCENT "0." RESET " " BOLD "Exit" RESET "\n");
    printf("\n");
    printf(BOLD "Select an option > " RESET);

    if (scanf("%d", &choice) != 1) {
      while (getchar() != '\n')
        ; // Clear bad input
      continue;
    }
    while (getchar() != '\n')
      ; // Clear trailing newline

    switch (choice) {
    case 1: {
      int p;
      char t[TITLE_LEN], d[DESC_LEN];
      printf("\n" COLOR_HEADER "ENQUEUE OPERATION" RESET "\n");
      printf("Priority (1-100): ");
      scanf("%d", &p);
      while (getchar() != '\n')
        ;

      printf("Title: ");
      fgets(t, TITLE_LEN, stdin);
      t[strcspn(t, "\n")] = 0;

      printf("Description: ");
      fgets(d, DESC_LEN, stdin);
      d[strcspn(d, "\n")] = 0;

      enqueue(&pq, p, t, d);
      waitForEnter();
      break;
    }
    case 2: {
      printf("\n" COLOR_HEADER "DEQUEUE OPERATION" RESET "\n");
      Task t = dequeue(&pq);
      if (t.id != -1) {
        printTask(t);
        printf("\n" COLOR_SUCCESS "Task Processed (Dequeued)!" RESET "\n");
      } else {
        printf(DIM "Queue is empty." RESET "\n");
      }
      waitForEnter();
      break;
    }
    case 3: {
      // List first to help user choose
      printf("\n" COLOR_HEADER "DELETE TASK FROM QUEUE" RESET "\n");
      if (pq.head == NULL) {
        printf(DIM "Queue is empty." RESET "\n");
      } else {
        Node *temp = pq.head;
        while (temp != NULL) {
          printf("#%d | P:%d | %s\n", temp->task.id, temp->task.priority,
                 temp->task.title);
          temp = temp->next;
        }
        printf("Enter Task ID to delete: ");
        int id;
        scanf("%d", &id);
        deleteById(&pq, id);
      }
      waitForEnter();
      break;
    }
    case 4: {
      printf("\n" COLOR_HEADER "QUEUE CONTENT" RESET "\n");
      if (pq.head == NULL)
        printf(DIM "Queue is empty." RESET "\n");
      Node *temp = pq.head;
      while (temp != NULL) {
        printTask(temp->task);
        temp = temp->next;
      }
      waitForEnter();
      break;
    }
    case 5: {
      printf("\n" COLOR_HEADER "PRIORITY QUEUE VISUALIZATION" RESET "\n");
      visualizeQueue(&pq);
      waitForEnter();
      break;
    }
    case 0:
      printf("\n" COLOR_MAGENTA "Exiting Priority Queue Manager." RESET "\n");
      return 0;
    default:
      printf(COLOR_ERROR "Invalid option." RESET "\n");
      waitForEnter();
    }
  }
  return 0;
}
