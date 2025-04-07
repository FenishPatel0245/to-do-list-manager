#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "todolist.h"

Task tasks[MAX_TASKS]; // Array to store tasks
int taskCount = 0;  // Number of tasks currently stored


// call this function to print the header

void print_header(const char* title) 
{
    printf("\n==============================\n");
    printf("  %s\n", title);
    printf("==============================\n");
}

// call this function to get date in YYYY-MM-DD format

int validate_date(const char* date)
{
	if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') // ckecking user input
    {
        return 0; 
    }

    for (int i = 0; i < 10; i++) 
    {
        if (i == 4 || i == 7)
        {
            continue;
        }

        if (!isdigit(date[i]))
        {
            return 0;
        }
    }

	int year, month, day; // declaring variables for year, month and day

    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3)
    {
        return 0;
    }

    if (year < 2000 || year > 2100)
    {
        return 0; 
    }

    if (month < 1 || month > 12)
    {
        return 0; 
    }

    if (day < 1 || day > 31)
    {
        return 0;
    }

    return 1; 
}

// Function to validate a time string in the format "HH:MM"

int validate_time(const char* time)  
{
    
	if (strlen(time) != 5 || time[2] != ':') // checking user input
    {
        return 0; 
    }

    
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
        {
            continue;
        }

        if (!isdigit(time[i]))
        {
            return 0;
        }
    }

	int hour, minute; // declaring variables for hour and minute

    if (scanf(time, "%2d:%2d", &hour, &minute) != 2)
    {
        return 0; 
    }

    if (hour < 0 || hour > 23)
    {
        return 0; 
    }

    if (minute < 0 || minute > 59)
    {
        return 0;
    }

    return 1;
}

// Function to get a valid integer input from the user within a specific range
int get_integer_input(const char* prompt, int min, int max)
{
	int value;  // declaring variable for user input

    while (1)
    {
        
        printf("%s", prompt);

        
        if (scanf("%d", &value) == 1)
        {
            
            if (value >= min && value <= max)
            {
                break; 
            }
        }

        
        printf("Invalid input! Please enter a number between %d and %d.\n", min, max);  

        
		while (getchar() != '\n'); // clear the input buffer
    }

    return value; 
}
// Function to save tasks to a file

void load_tasks()
{
    FILE* file = fopen(FILENAME, "r"); // Open the file in read mode

    if (!file)
    {
        return;
    }

    // Read data from the file line by line

    while (fscanf(file, " %99[^\n] %10s %5s %d %d",
        tasks[taskCount].description,
        tasks[taskCount].date,
        tasks[taskCount].time,
        &tasks[taskCount].priority,
        &tasks[taskCount].done) == 5)
    {

        taskCount++;

        if (taskCount >= MAX_TASKS)
        {
            break;
        }
    }

    fclose(file); // Close the file
}
// Function to save tasks to a file

void save_tasks()
{
    FILE* file = fopen(FILENAME, "w");  // Open the file in write mode
    if (!file)
    {
        printf("Error saving tasks!\n");
        return;
    }

    // Write tasks to the file
    for (int i = 0; i < taskCount; i++)
    {
        fprintf(file, "%s\n%s %s %d %d\n",
            tasks[i].description,
            tasks[i].date,
            tasks[i].time,
            tasks[i].priority,
            tasks[i].done);
    }

    fclose(file); // Close the file
}

// Function to add a new task
void add_task()
{
    if (taskCount >= MAX_TASKS)
    {
        printf("Task list is full!\n");
        return;
    }

    Task newTask;                  // Create a new task

    getchar();                           // Clear newline from previous input

    printf("Enter task description: ");

    fgets(newTask.description, sizeof(newTask.description), stdin);

    newTask.description[strcspn(newTask.description, "\n")] = 0;

    do
    {
        printf("Enter due date (YYYY-MM-DD): ");

        scanf("%10s", newTask.date);
    }
    while (!validate_date(newTask.date));

    do
    {
        printf("Enter due time (HH:MM): ");

        scanf("%5s", newTask.time);
    } 
    while (!validate_time(newTask.time));

    newTask.priority = get_integer_input("Enter priority (1-5, 5 is highest): ", 1, 5);   // Get priority input

    newTask.done = 0;

    tasks[taskCount++] = newTask; // Add the new task to the array

    save_tasks();      // Save tasks to file

    printf("Task added successfully!\n");   // Print success message
}

// Function to add a new task

void view_tasks()
{
    if (taskCount == 0) // Check if there are no tasks

    {
        printf("No tasks available.\n");
        return;
    }

    printf("\n==== To-Do List ====\n");

    for (int i = 0; i < taskCount; i++)

        printf("%d. [%s] %s (Due: %s %s) - Priority: %d\n",
            i + 1,
            tasks[i].done ? "X" : " ",   // maeking the task done
            tasks[i].description,
            tasks[i].date,
            tasks[i].time,
			tasks[i].priority); // adding priority to the task
}

// Sort tasks by priority (5 is highest)
void sort_tasks_by_priority()
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
            if (tasks[j].priority < tasks[j + 1].priority)
            {
                // Swap the tasks
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}
// Mark a task as completed

void mark_task_completed()
{
    view_tasks(); 

    if (taskCount == 0)

        return;

    int taskNumber = get_integer_input("Enter task number to mark as completed: ", 1, taskCount);

    tasks[taskNumber - 1].done = 1;

    save_tasks();

    printf("Task marked as completed!\n");
}

// Function to search for a task by description
void sort_tasks_by_date()
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
			if (strcmp(tasks[j].date, tasks[j + 1].date) > 0)  // swapping the tasks
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}