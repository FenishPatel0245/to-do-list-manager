#ifndef TODOLIST_H
#define TODOLIST_H

#define MAX_TASKS 100     // Maximum number of tasks that can be stored
#define FILENAME "tasks.txt" // File to store created tasks

// Task structure
typedef struct {
	char description[100];  // Task description 
	char date[11];      // YYYY-MM-DD
	char time[6];       // HH:MM
	int priority;      // Task priority 
	int done;         // indicates if the task is done or not
} Task; 

extern Task tasks[MAX_TASKS];   // Array to store tasks
extern int taskCount;           // Number of tasks currently stored

// Function declarations
void print_header(const char* title);                        // for Print header 
int validate_date(const char* date);                         // for Validateing date format (YYYY-MM-DD)
int validate_time(const char* time);                         // for Validateing time format (HH:MM)
int get_integer_input(const char* prompt, int min, int max); // for Geting integer input from user
void load_tasks();										     // for Loading tasks from file
void save_tasks();											 // for Saving tasks to file
void add_task(); 										     // for Adding a new task
void view_tasks(); 									       	// for Viewing tasks
void view_tasks_by_priority(); 								// for Viewing tasks by priority
void view_tasks_by_date(); 							     	// for Viewing tasks by date
void mark_task_completed(); 								// for Marking a task as completed
void search_task(); 									    // for Searching for a task
void delete_task(); 									    // for Deleting a task
void print_menu(); 								        	// for Printing the main menu
void sort_tasks_by_priority(); 								// for Sorting tasks by priority
void sort_tasks_by_date(); 								    // for Sorting tasks by date

#endif

extern Task tasks[MAX_TASKS];   // Array to store tasks
extern int taskCount;           // Numbers of tasks currently stored

// Function declarations
void print_header(const char* title);                        // for Print header 
int validate_date(const char* date);                         // for Validateing date format (YYYY-MM-DD)
int validate_time(const char* time);                         // for Validateing time format (HH:MM)
int get_integer_input(const char* prompt, int min, int max); // for Geting integer input from user
void load_tasks();										     // for Loading tasks from file
void save_tasks();											 // for Saving tasks to file
void add_task(); 										     // for Adding a new task
void view_tasks(); 									       	// for Viewing tasks
void view_tasks_by_priority(); 								// for Viewing tasks by priority
void view_tasks_by_date(); 							     	// for Viewing tasks by date
void mark_task_completed(); 								// for Marking a task as completed
void search_task(); 									    // for Searching for a task
void delete_task(); 									    // for Deleting a task
void print_menu(); 								        	// for Printing the main menu
void sort_tasks_by_priority(); 								// for Sorting tasks by priority
void sort_tasks_by_date(); 								    // for Sorting tasks by date

#endif