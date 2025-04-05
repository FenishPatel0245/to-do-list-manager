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

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Name:Darshita/Date:2025-04-05 : 

I have added the following things in todolist.c (source file) 

4. input validator for integer (get_integer_nput)

- Shows a custom prompt to the user.
- Accepts only integer input.
- Keeps asking until the input is within the range [min, max].

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
