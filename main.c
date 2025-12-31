#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/**
 * ======================================================================================
 *                                   THEME & COLORS
 * ======================================================================================
 * Standard ANSI Escape Codes for formatting terminal output.
 * We define macro constants for easier use throughout the application.
 */
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define REVERSE "\033[7m"

// Neon Color Palette for "Vibrant" Aesthetic
#define C_CYAN "\033[38;5;51m"
#define C_MAGENTA "\033[38;5;213m"
#define C_GREEN "\033[38;5;46m"
#define C_YELLOW "\033[38;5;226m"
#define C_RED "\033[38;5;196m"
#define C_BLUE "\033[38;5;39m"
#define C_WHITE "\033[38;5;255m"
#define C_GREY "\033[38;5;240m"
#define C_BLACK "\033[38;5;232m"

// Background Colors for emphasis
#define BG_BLUE "\033[48;5;17m"
#define BG_MAGENTA "\033[48;5;53m"

// UI Global Constants
#define UI_WIDTH 60  // Fixed width for alignment calculations
#define TITLE_LEN 64 // Maximum character length for task titles

/**
 * ======================================================================================
 *                               DATA STRUCTURES
 * ======================================================================================
 */

// Task Object: Represents the data payload of a priority queue node.
typedef struct {
  int id;                // Unique identifier for the task
  int priority;          // 1-100, higher value means higher priority
  char title[TITLE_LEN]; // Description of the task
  time_t created_at;     // Timestamp (reserved for future use)
} Task;

// Node: A Singly Linked List Node wrapping a Task.
typedef struct Node {
  Task task;
  struct Node *next;
} Node;

// PriorityQueue: The ADT container.
typedef struct {
  Node *head;  // Points to the highest priority node
  int size;    // Tracks current number of elements
  int next_id; // Auto-increment counter for IDs
} PriorityQueue;

/**
 * ======================================================================================
 *                               RENDERING ENGINE
 * ======================================================================================
 * These functions abstract the complexity of printing perfect boxes.
 * They handle the mathematical calculations to ensure padding is always
 * correct.
 */

// Draw a horizontal line with specific start, middle, and end characters.
// Usage: print_line("╔", "═", "╗", C_BLUE) -> Draws top border
void print_line(const char *start, const char *fill, const char *end,
                const char *color) {
  printf("    %s%s", color, start);
  for (int i = 0; i < UI_WIDTH; i++)
    printf("%s", fill);
  printf("%s" RESET "\n", end);
}

// Print text centered within the UI_WIDTH.
// Calculates exact left/right padding based on text string length.
void print_centered(const char *text, const char *text_color,
                    const char *border_color) {
  int len = strlen(text);
  int padding_l = (UI_WIDTH - len) / 2;
  int padding_r = UI_WIDTH - len - padding_l;

  printf("    %s║%s", border_color, RESET);
  for (int i = 0; i < padding_l; i++)
    printf(" ");
  printf("%s%s" RESET, text_color, text);
  for (int i = 0; i < padding_r; i++)
    printf(" ");
  printf("%s║" RESET "\n", border_color);
}

// Print a key-value row with dot leaders: "Key .......... Value"
// Target Inner Width: 60
// Layout: space(1) + Label(L) + space(1) + Dots(D) + space(1) + Value(V) +
// space(1) Formula needed for dot calculation: D = 56 - L - V
void print_row(const char *label, const char *value, const char *label_col,
               const char *val_col, const char *border_col) {
  int len_label = strlen(label);
  int len_val = strlen(value);
  int dots = 56 - len_label - len_val;
  if (dots < 0)
    dots = 0;

  printf("    %s║ %s%s" RESET " ", border_col, label_col, label);
  for (int i = 0; i < dots; i++)
    printf("%s.", C_GREY);
  printf(" %s%s" RESET " %s║" RESET "\n", val_col, value, border_col);
}

// Print a menu option formatted as a button.
// Length Check: 2 (spaces) + 5 ([ X ]) + 1 (space) + 52 (padded desc) = 60.
void print_menu_item(int key, const char *desc, const char *key_color,
                     const char *desc_color, const char *border_col) {
  printf("    %s║" RESET, border_col);
  printf("  %s[ %d ]" RESET " %s%-52s" RESET, key_color, key, desc_color, desc);
  printf("%s║" RESET "\n", border_col);
}

// Helper to clear terminal
void clear_screen() { printf("\033[H\033[J"); }

// Displays the Main Banner / Header
void print_banner() {
  clear_screen();
  printf("\n");
  print_line("╔", "═", "╗", C_BLUE);
  print_centered("", C_WHITE, C_BLUE);

  // ASCII Art - Manually Aligned by User
  printf("    " C_BLUE "║" RESET C_CYAN
         "   ████████╗ █████╗ ███████╗██╗  ██╗███████╗     " C_BLUE
         "           ║" RESET "\n");
  printf("    " C_BLUE "║" RESET C_CYAN
         "   ╚══██╔══╝██╔══██╗██╔════╝██║ ██╔╝██╔════╝     " C_BLUE
         "           ║" RESET "\n");
  printf("    " C_BLUE "║" RESET C_CYAN
         "      ██║   ███████║███████╗█████╔╝ ███████╗     " C_BLUE
         "           ║" RESET "\n");
  printf("    " C_BLUE "║" RESET C_CYAN
         "      ██║   ██╔══██║╚════██║██╔═██╗ ╚════██║     " C_BLUE
         "           ║" RESET "\n");
  printf("    " C_BLUE "║" RESET C_CYAN
         "      ██║   ██║  ██║███████║██║  ██╗███████║     " C_BLUE
         "           ║" RESET "\n");
  printf("    " C_BLUE "║" RESET C_CYAN
         "      ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝     " C_BLUE
         "           ║" RESET "\n");

  print_centered("", C_WHITE, C_BLUE);
  print_centered("ULTIMATE MANAGER v1.0", C_MAGENTA BOLD, C_BLUE);
  print_centered("", C_WHITE, C_BLUE);
  print_line("╚", "═", "╝", C_BLUE);
  printf("\n");
}

/**
 * ======================================================================================
 *                               CORE LOGIC
 * ======================================================================================
 */

// Initialize the Priority Queue to empty state
void initQueue(PriorityQueue *pq) {
  pq->head = NULL;
  pq->size = 0;
  pq->next_id = 1;
}

// Insert a new task into the queue in strict priority order.
// O(N) complexity: We traverse the list to find the insertion point.
void enqueue(PriorityQueue *pq, int priority, const char *title) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
    return;

  // Setup Node Data
  newNode->task.id = pq->next_id++;
  newNode->task.priority = priority;
  strncpy(newNode->task.title, title, TITLE_LEN - 1);
  newNode->task.title[TITLE_LEN - 1] = '\0'; // Ensure string is null-terminated
  newNode->next = NULL;

  // Case 1: List is empty OR new priority is higher than head
  if (!pq->head || pq->head->task.priority < priority) {
    newNode->next = pq->head;
    pq->head = newNode;
  } else {
    // Case 2: Traverse to find correct spot
    Node *curr = pq->head;
    while (curr->next && curr->next->task.priority >= priority) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
  pq->size++;
}

// Remove and return the highest priority task (the head).
// O(1) complexity.
Task dequeue(PriorityQueue *pq) {
  Task t = {-1}; // Sentinel task for failure/empty
  if (pq->head) {
    Node *temp = pq->head;
    t = temp->task;
    pq->head = temp->next;
    free(temp);
    pq->size--;
  }
  return t;
}

/**
 * ======================================================================================
 *                                UI SCENES
 * ======================================================================================
 */

// Render the System Stats and Waiting queue summary
void show_status(PriorityQueue *pq) {
  print_line("╔", "═", "╗", C_MAGENTA);
  print_centered("SYSTEM STATUS", C_WHITE BOLD, C_MAGENTA);
  print_line("╠", "─", "╣", C_MAGENTA);

  char buf[64];
  sprintf(buf, "%d", pq->size);
  print_row("PENDING TASKS", buf, C_CYAN, C_WHITE BOLD, C_MAGENTA);

  if (pq->head) {
    sprintf(buf, "%d", pq->head->task.priority);
    print_row("HIGHEST PRIORITY", buf, C_YELLOW, C_RED BOLD, C_MAGENTA);

    // Truncate title to ensure it fits in the layout
    char title_display[30];
    strncpy(title_display, pq->head->task.title, 25);
    if (strlen(pq->head->task.title) > 25)
      strcpy(&title_display[25], "...");
    else
      title_display[strlen(pq->head->task.title)] = 0;

    print_row("NEXT UP", title_display, C_GREEN, C_WHITE, C_MAGENTA);
  } else {
    print_centered("Waiting for input...", C_GREY, C_MAGENTA);
  }
  print_line("╚", "═", "╝", C_MAGENTA);
  printf("\n");
}

// Render the Interaction Menu
void show_menu() {
  print_line("╔", "═", "╗", C_CYAN);
  print_centered("CONTROL DECK", C_WHITE BOLD, C_CYAN);
  print_line("╠", "─", "╣", C_CYAN);
  print_menu_item(1, "Create New Task", C_MAGENTA BOLD, C_WHITE, C_CYAN);
  print_menu_item(2, "Process Highest Priority", C_MAGENTA BOLD, C_WHITE,
                  C_CYAN);
  print_menu_item(3, "Visualize Queue Chain", C_MAGENTA BOLD, C_WHITE, C_CYAN);
  print_line("╠", "─", "╣", C_CYAN);
  print_menu_item(0, "Shut Down System", C_RED BOLD, C_GREY, C_CYAN);
  print_line("╚", "═", "╝", C_CYAN);
  printf("\n");
}

// Visualize the queue as a table
void show_all_tasks(PriorityQueue *pq) {
  print_line("╔", "═", "╗", C_GREEN);

  // Header Inner Width 60
  // " ID    PRI   TASK DETAILS                                   " (60 chars)
  // 1+4+3+3+3+46 = 60.
  printf("    " C_GREEN "║" RESET C_BLACK BG_MAGENTA
         " ID    PRI   TASK DETAILS                                  "
         " " RESET C_GREEN "║" RESET "\n");

  if (!pq->head) {
    print_centered("No Active Tasks", C_GREY, C_GREEN);
  } else {
    Node *curr = pq->head;
    int count = 0;
    while (curr && count < 5) {
      char title_cut[50];
      // Format: " %-4d  " (7) + "%-3d" (3) + "   " (3) = 13 used. 47 remaining.
      strncpy(title_cut, curr->task.title, 44);
      if (strlen(curr->task.title) > 44)
        strcpy(&title_cut[41], "...");
      else
        title_cut[strlen(curr->task.title)] = 0;

      // Color code the priority for visual impact
      char *prio_color = C_GREEN;
      if (curr->task.priority > 80)
        prio_color = C_RED;
      else if (curr->task.priority > 50)
        prio_color = C_YELLOW;

      printf("    " C_GREEN "║" RESET " %-4d  %s%-3d" RESET "   %-47s" C_GREEN
             "║" RESET "\n",
             curr->task.id, prio_color, curr->task.priority, title_cut);

      if (curr->next && count < 4) {
        print_line("╠", "─", "╣", C_GREEN);
      }
      curr = curr->next;
      count++;
    }
    if (curr) {
      print_centered("... more tasks ...", C_GREY, C_GREEN);
    }
  }
  print_line("╚", "═", "╝", C_GREEN);
}

// Pauses execution for user to read output
void wait_input() {
  printf("    " DIM "[ Press ENTER to continue ]" RESET);
  while (getchar() != '\n')
    ;
  getchar();
}

/**
 * ======================================================================================
 *                                     MAIN LOOP
 * ======================================================================================
 */
int main() {
  PriorityQueue pq;
  initQueue(&pq);
  int choice;

  while (1) {
    print_banner();
    show_status(&pq);
    show_menu();

    printf("    " C_MAGENTA "COMMAND > " RESET);
    // Robust input handling for menu choice
    if (scanf("%d", &choice) != 1) {
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ; // flush

    if (choice == 1) {
      // --- CREATE NEW TASK SCENE ---
      printf("\n");
      print_line("╔", "═", "╗", C_BLUE);
      print_centered("NEW TASK ENTRY", C_WHITE BOLD, C_BLUE);
      print_line("╚", "═", "╝", C_BLUE);

      int p;
      char t[TITLE_LEN];
      printf("    " C_CYAN "Priority (1-100): " RESET);
      // Input Validation Loop for Priority
      do {
        if (scanf("%d", &p) != 1) {
          while (getchar() != '\n')
            ; // Clear bad input
          p = -1;
        }
        while (getchar() != '\n')
          ; // Clear buffer

        if (p < 1 || p > 100) {
          printf("    " C_RED "Invalid! Enter 1-100: " RESET);
        }
      } while (p < 1 || p > 100);

      printf("    " C_CYAN "Task Title      : " RESET);
      fgets(t, TITLE_LEN, stdin);
      t[strcspn(t, "\n")] = 0; // Strip newline from fgets
      enqueue(&pq, p, t);
      printf("\n    " C_GREEN ">> Success." RESET "\n");
      wait_input();
    } else if (choice == 2) {
      // --- DEQUEUE SCENE ---
      printf("\n");
      Task t = dequeue(&pq);
      if (t.id != -1) {
        printf("    " C_GREEN "COMPLETED: %s" RESET "\n", t.title);
      } else {
        printf("    " C_RED "Empty Queue!" RESET "\n");
      }
      wait_input();
    } else if (choice == 3) {
      // --- VISUALIZE SCENE ---
      printf("\n");
      show_all_tasks(&pq);
      wait_input();
    } else if (choice == 0) {
      printf("\n    " C_RED "Terminating..." RESET "\n");
      break;
    }
  }
  return 0;
}
