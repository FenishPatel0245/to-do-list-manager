#include <stdio.h>
#include "todolist.h"

int main()
{
	load_tasks(); // load tasks from file

	while (1)  // infinite loop to keep the program running
    {
        print_menu();
        int choice = get_integer_input("Choose an option (1-8): ", 1, 8);
        printf("*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\n");

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
            printf("\n*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\n");
			printf("|  Thank you for using the To-Do List Manager!  |\n");
            printf("*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\n");
            return 0;
        }
    }

    return 0;
}
