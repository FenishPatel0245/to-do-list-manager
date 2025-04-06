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

    if (sscanf(time, "%2d:%2d", &hour, &minute) != 2)
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

