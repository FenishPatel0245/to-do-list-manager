#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "todolist.h"

Task tasks[MAX_TASKS];
int taskCount = 0;

void print_header(const char* title)
{
    printf("\n==============================\n");
    printf("  %s\n", title);
    printf("==============================\n");
}

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

int validate_time(const char* time)
{
    if (strlen(time) != 5 || time[2] != ':')
    {
        printf("Invalid time format! Please use 24-hour format HH:MM (e.g., 14:30).\n");
        return 0;
    }

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

    int hour, minute;
    if (sscanf(time, "%2d:%2d", &hour, &minute) != 2)
    {
        printf("Failed to parse time. Please use format HH:MM (24-hour).\n");
        return 0;
    }

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
    int value;

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

        while (getchar() != '\n');
    }

    return value;
}

void load_tasks()
{
    FILE* file = fopen(FILENAME, "r");

    if (!file)
    {
        return;
    }

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

    fclose(file);
}

void save_tasks()
{
    FILE* file = fopen(FILENAME, "w");
    if (!file)
    {
        printf("Error saving tasks!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++)
    {
        fprintf(file, "%s\n%s %s %d %d\n",
            tasks[i].description,
            tasks[i].date,
            tasks[i].time,
            tasks[i].priority,
            tasks[i].done);
    }

    fclose(file);
}

void add_task()
{
    if (taskCount >= MAX_TASKS)
    {
        printf("Task list is full!\n");
        return;
    }

    Task newTask;

    getchar();

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

    newTask.priority = get_integer_input("Enter priority (1-5, 5 is highest): ", 1, 5);

    newTask.done = 0;

    tasks[taskCount++] = newTask;

    save_tasks();

    printf("Task added successfully!\n");
}

void view_tasks()
{
    if (taskCount == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\n==== To-Do List ====\n");

    for (int i = 0; i < taskCount; i++)
        printf("%d. [%s] %s (Due: %s %s) - Priority: %d\n",
            i + 1,
            tasks[i].done ? "X" : " ",
            tasks[i].description,
            tasks[i].date,
            tasks[i].time,
            tasks[i].priority);
}

void sort_tasks_by_priority()
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
            if (tasks[j].priority < tasks[j + 1].priority)
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

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

void sort_tasks_by_date()
{
    for (int i = 0; i < taskCount - 1; i++)
    {
        for (int j = 0; j < taskCount - i - 1; j++)
        {
            if (strcmp(tasks[j].date, tasks[j + 1].date) > 0)
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

void view_tasks_by_date()
{
    if (taskCount == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\nSorting tasks by date...\n");

    sort_tasks_by_date();

    printf("Displaying tasks by date:\n");

    view_tasks();
}

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

void search_task()
{
    char keyword[100];

    getchar();

    printf("Enter keyword to search: ");

    fgets(keyword, sizeof(keyword), stdin);

    keyword[strcspn(keyword, "\n")] = 0;

    printf("\n==== Search Results ====\n");

    int found = 0;

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

// Function to view tasks sorted by date
void view_tasks_by_date() {
  
    printf("Viewing tasks by date...\n");
}

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
