# to-do-list-manager
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-03-23 : I added main files to work on it.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-05 :

I have added the following features in todolist.h (header file) 

It lets you add tasks with:
- Description
- Date 
- Time 
- Priority
- checking if task is done or not

Tasks are saved in a file tasks.txt.  
The program is capable of storing up to 100 tasks.  
This part of the code sets up the task structure and storage.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Pratham/Date:2025-04-05 : 

I have added the following features in todolist.h (header file) 

- tasks[MAX_TASKS] → An array to store all the tasks.
- taskCount → Keeps track of the number of tasks.

Function Declaration:

- print_header() – Print a header with a title.
- validate_date() – Check if the date is in the correct format (YYYY-MM-DD).
- validate_time() – Check if the time is in the correct format (HH:MM).
- get_integer_input() – Ask user to enter a number between given min and max.
- load_tasks() – Load tasks from a file.
- save_tasks() – Save tasks to a file.
- add_task() – Add a new task.
- view_tasks() – Show all tasks.
- view_tasks_by_priority() – Show tasks sorted by priority.
- view_tasks_by_date() – Show tasks sorted by date.
- mark_task_completed() – Mark a task as completed.
- search_task() – Find a task by keyword.
- delete_task() – Delete a task.
- print_menu() – Show the main menu.
- sort_tasks_by_priority() – Sort tasks by priority.
- sort_tasks_by_date() – Sort tasks by date.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-05 : 

I have added the following things in todolist.c (source file) 

1. Header Printer (print_header)
   - Make a title with lines above and below it.
   - Makes menus and messages easier to read.

2. Date Validator (validate_date)
   - Checks if the date is in the correct format: YYYY-MM-DD
   - Year is between 2000 and 2100
   - Month is between 1 and 12
   - Day is between 1 and 31

3. Time Validator (validate_time)
   - Checks if the time is in the correct format: HH:MM
   - Hours are between 0 and 23
   - Minutes are between 0 and 59

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-05 : 

I have added the following things in todolist.c (source file) 

4. input validator for integer (get_integer_nput)

- Shows a custom prompt to the user.
- Accepts only integer input.
- Keeps asking until the input is within the range [min, max].

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Pratham/Date:2025-04-05 : 

I have added the following things in todolist.c (source file) 

5.  for (load_tasks)
   
- Opens the file tasks.txt in read mode.
- Reads task details line by line and stores them in the tasks[] array.
- Stops reading when:
  - It reaches the end of the file, or
  - It hits the maximum allowed tasks (MAX_TASKS).

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-05 : 

I have added the following things in todolist.c (source file) 

6. adding (save_tasks)

- Opens the file tasks.txt in write mode.
- Goes through all tasks stored in the program.
- 
- Writes each task's details to the file:
  - Description
  - Date 
  - Time 
  - Priority
  - checking if task is done or not

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-06 : 

I have added the following things in todolist.c (source file) 

7. adding function: (add_task)

- Asks the user for:
  - Task description
  - Due date 
  - Due time 
  - Priority 
- Automatically sets the task as *not done*.
- Saves the new task into the array and writes it to the file.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-06 : 

I have added the following things in todolist.c (source file) 

8. adding (view_tasks)

- Displays all current tasks in the list.
- If there are no tasks, it shows a message.
  
- Each task shows:
  - Number
  - Done status ([X] if completed, [ ] if not)
  - Description
  - Due date and time
  - Priority

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Pratham/Date:2025-04-06 : 

I have added the following things in todolist.c (source file) 

9. adding (sort_tasks_by_priority)

- Compares the priority of each task.
- Swaps tasks so that higher-priority ones come first.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-07 : 

I have added the following things in todolist.c (source file) 

9. adding (mark_task_completed)

- First shows all current tasks using view_tasks()
- Asks the user to choose a task number.
- Updates the task file using save_tasks().

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-07 : 

I have added the following things in todolist.c (source file) 

10. adding (sort_tasks_by_date)

- Compares dates as strings.
- Earlier dates come before later ones.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Name:Pratham/Date:2025-04-07 : 

I have added the following things in todolist.c (source file) 

11. adding (search_task)

- Prompts the user to enter a keyword.
- Looks through all tasks to find matches in the description.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Name:Pratham/Date:2025-04-08 : 

I have added the following things in todolist.c (source file) 

12. adding (delete_task)

-Shifts tasks after deletion to maintain list integrity
-Automatically saves the updated task list
-Displays a success message upon completion.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Name:Fenish/Date:2025-04-08 : 

I have added the following things in main.c (main file) 

-Loads tasks at startup
-Continuously displays a user-friendly menu
-Calls appropriate functions based on user selection (Add, View, Search, Delete, etc.)
-Clean exit on choosing option 8

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-08 : 

I have added the following things in todolist.c (source file) 

13. Adding (print_menu)
    
-Clearly lists available task management options
-Enhances user navigation with a clean and organized layout

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-09 : 

Solving errors

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-09 : 

Implemented validate_date() to verify that date inputs follow the correct format and range

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Name:Pratham/Date:2025-04-09 : 

Added validate_time() function to validate time inputs using 24-hour format.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-09 : 

Implemented view_tasks_by_priority() function to display tasks sorted by priority.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-10 : 

Setup the todolist_UnitTest.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Pratham/Date:2025-04-10 : 

Unit test Case 1 : Added unit test ValidateDate_Valid() to verify validate_date() correctly accepts valid date formats.

- Tests both YYYY-MM-DD and YYYY/MM/DD
- Covers edge years like 2000 and 2100
- Ensures the function reliably handles proper inputs without false rejections.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-10 : 

Unit test Case 2 : Added unit test ValidateDate_InvalidFormat() to ensure validate_date() correctly rejects malformed or out-of-range dates.

- Tests invalid formats, separators, non-digit characters
- Catches out-of-range months/days and unsupported years
- Ensures empty and incorrectly structured dates are handled properly
- Strengthens input validation reliability by covering edge cases and incorrect inputs.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-10 : 

Unit test Case 3 : Added unit test ValidateTime_Valid() to confirm that validate_time() accepts properly formatted 24-hour time values.

- Tests boundary values like 00:00 and 23:59
- Confirms standard valid times like 09:45 and 23:00
- Ensures the function properly recognizes valid input within the expected range.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Pratham/Date:2025-04-10 : 

Unit test Case 4 : Added unit test ValidateTime_Invalid() to ensure validate_time() rejects incorrect time formats and values.

- Catches missing leading zeros, wrong separators, and empty strings
- Validates out-of-range hours (e.g., 24:00) and minutes (e.g., 12:60)
- Ensures time inputs strictly follow HH:MM format
- Strengthens robustness of time validation by covering diverse edge and formatting errors.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-10 : 

Unit test Case 5 : Added unit test SortTasksByPriority_CheckOrder() to confirm that sort_tasks_by_priority() orders tasks correctly by priority level.

- Uses a predefined set of tasks with different priorities
- Asserts that tasks are sorted in descending priority (high to low)
- Ensures reliability of priority-based sorting logic
  
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Fenish/Date:2025-04-10 : 

Unit test Case 6 : Added unit test SortTasksByDate_CheckOrder() to verify that sort_tasks_by_date() correctly arranges tasks in chronological order.

- Uses tasks with varying due dates
- Asserts correct order: April → May → June
- Ensures reliable sorting by date for improved task scheduling
