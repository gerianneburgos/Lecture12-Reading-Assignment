#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

// defines function prototype for reading a line of input
int read_line(char str[], int n);

int main(void)
{
    // array to store reminders
    char reminders[MAX_REMIND][MSG_LEN + 3];
    // string to store the day as a string
    char day_str[3];
    // string to store the reminder message
    char msg_str[MSG_LEN + 1];
    // variables for day, loop counters, and number of reminders
    int day, i, j, num_remind = 0;

    for (;;)
    {
        // checks if maximum number of reminders is reached
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        // prompts the user to enter the day and reminder
        printf("Enter day and reminder: ");
        // reads the day value as an integer
        scanf("%2d", &day);
        // checks if the day is 0 (terminate program if true)
        if (day == 0)
            break;
        
        // converts the day to a string format
        sprintf(day_str, "%2d", day);

        // reads the reminder message
        read_line(msg_str, MSG_LEN);

        // finds the appropriate position to insert the reminder
        for (i = 0; i < num_remind; i++)
        {
            // compares the day string with existing reminders
            // breaks the loop if the current reminder is greater than the input day
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }

        // shifts reminders down to make room for the new reminder
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        // inserts the new reminder at the appropriate position
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        // increments the number of reminders
        num_remind++;
    }

    // prints the reminders
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
    {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

// function to read a line of input
int read_line(char str[], int n)
{
    int ch, i = 0;
    
    // reads characters until newline or end of input is encountered
    while ((ch = getchar()) != '\n')
    {
        // checks if there is enough space in the array
        if (i < n)
        {
            // stores the character in the array
            str[i++] = ch;
        }
    }
    
    // appends null character to mark the end of the string
    str[i] = '\0';
    
    // returns the length of the string
    return i;
}
