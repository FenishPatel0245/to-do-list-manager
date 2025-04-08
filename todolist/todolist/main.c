#include <stdio.h>
#include "todolist.h"

int main()
{
    load_tasks();

    while (1)
    {
        print_menu();
        int choice = get_integer_input("Choose an option (1-8): ", 1, 8);

        switch (choice)
        {
        case 1: add_task();
            break;
        case 2: view_tasks();
            break;
        case 3: view_tasks_by_priority();
            break;
        case 4: view_tasks_by_date(); 
            break;
        case 5: mark_task_completed(); 
            break;
        case 6: search_task(); 
            break;
        case 7: delete_task();
            break;
        case 8:
            return 0;
        }
    }

    return 0;
}
