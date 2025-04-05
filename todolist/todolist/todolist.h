#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_TASKS 100     // Maximum number of tasks that can be stored
#define FILENAME "tasks.txt" // File to store created tasks

// Task structure
typedef struct{
	char description[100];  // Task description 
    char date[11];      // YYYY-MM-DD
    char time[6];       // HH:MM
	int priority;      // Task priority 
	int done;         // indicates if the task is done or not
} Task;


