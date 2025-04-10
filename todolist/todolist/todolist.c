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
    if (strlen(date) != 10 || !(date[4] == '-' || date[4] == '/') || !(date[7] == '-' || date[7] == '/'))
    {
        printf("Invalid date format! Please use YYYY-MM-DD or YYYY/MM/DD (e.g., 2025-04-09).\n");
        return 0;
    }

    char sep = date[4];

    if (date[7] != sep)
    {
        printf("Inconsistent separators! Use the same separator throughout (either '-' or '/').\n");
        return 0;
    }

    char year_str[5], month_str[3], day_str[3];
    strncpy(year_str, date, 4); year_str[4] = '\0';
    strncpy(month_str, date + 5, 2); month_str[2] = '\0';
    strncpy(day_str, date + 8, 2); day_str[2] = '\0';

    if (!isdigit(year_str[0]) || !isdigit(year_str[1]) || !isdigit(year_str[2]) || !isdigit(year_str[3]) ||
        !isdigit(month_str[0]) || !isdigit(month_str[1]) ||
        !isdigit(day_str[0]) || !isdigit(day_str[1]))
    {
        printf("Date must contain only numbers. Example: 2025-04-09 or 2025/04/09.\n");
        return 0;
    }

    int year = atoi(year_str);
    int month = atoi(month_str);
    int day = atoi(day_str);

    if (year < 2000 || year > 2100)
    {
        printf("Year must be between 2000 and 2100.\n");
        return 0;
    }

    if (month < 1 || month > 12)
    {
        printf("Month must be between 1 and 12.\n");
        return 0;
    }

    if (day < 1 || day > 31)
    {
        printf("Day must be between 1 and 31.\n");
        return 0;
    }

    return 1;
}

// Function to validate a time string in the format "HH:MM"

int validate_time(const char* time)
{
    // Check length and position of colon
    if (strlen(time) != 5 || time[2] != ':')
    {
        printf("Invalid time format! Please use 24-hour format HH:MM (e.g., 14:30).\n");
        return 0;
    }

    // Check that all characters (except colon) are digits
    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
            continue;

        if (!isdigit(time[i]))
        {
            printf("Time must contain only digits and a colon. Example: 09:45 or 23:00.\n");
            return 0;
        }
    }

    // Extract hour and minute values
    int hour, minute;
    if (scanf(time, "%2d:%2d", &hour, &minute) != 2)
    {
        printf("Failed to parse time. Please use format HH:MM (24-hour).\n");
        return 0;
    }

    // Validate hour and minute ranges
    if (hour < 0 || hour > 23)
    {
        printf("Hour must be between 0 and 23.\n");
        return 0;
    }

    if (minute < 0 || minute > 59)
    {
        printf("Minutes must be between 0 and 59.\n");
        return 0;
    }

    return 1;
}
// Function to search for a task by description

void view_tasks_by_priority()
{
    if (taskCount == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nSorting tasks by priority...\n");

    sort_tasks_by_priority();

    printf("Displaying tasks by priority:\n");

    view_tasks();
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
    } while (!validate_date(newTask.date));

    do
    {
        printf("Enter due time (HH:MM): ");

        scanf("%5s", newTask.time);
    } while (!validate_time(newTask.time));

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
// Function to view tasks by date
void search_task()
{
    char keyword[100];         // Create a buffer for the keyword

    getchar();

    printf("Enter keyword to search: ");

    fgets(keyword, sizeof(keyword), stdin);

    keyword[strcspn(keyword, "\n")] = 0;

    printf("\n==== Search Results ====\n");

    int found = 0;   //flag to check if any tasks are found

    for (int i = 0; i < taskCount; i++)
    {
        if (strstr(tasks[i].description, keyword))
        {
            printf("%d. %s (Due: %s %s) - Priority: %d\n",
                i + 1,
                tasks[i].description,
                tasks[i].date,
                tasks[i].time,
                tasks[i].priority);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No tasks found with that keyword.\n");
    }
}

void delete_task()
{
    view_tasks();

    if (taskCount == 0)
        return;

    int taskNumber = get_integer_input("Enter task number to delete: ", 1, taskCount);

    for (int i = taskNumber - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;

    save_tasks();

    printf("Task deleted successfully!\n");
}

// Function to view tasks sorted by priority
void view_tasks_by_priority()
{
  
    printf("Viewing tasks by priority...\n");
}

// Function to view task sorted by date
void view_tasks_by_date() {
  
    printf("Viewing tasks by date...\n");
}


// Function to print the main menu
void print_menu()
{
    print_header("TO-DO LIST MANAGER");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. View Tasks by Priority\n");
    printf("4. View Tasks by Date\n");
    printf("5. Mark Task as Completed\n");
    printf("6. Search Task\n");
    printf("7. Delete Task\n");
    printf("8. Exit\n");
}
