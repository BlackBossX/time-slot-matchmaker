#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filehandle.h"
#include "studentInfo.h"


FILE *fl;
typedef struct
{
    char stu_no[10]; // put extra character here because when we read we read without the last index
    char name[20];
    char mobile[11];
} student;

FILE *time_file;

typedef struct
{
    char name[20];
    char time1[3];
    char time2[3];
    char time3[3];
    char time4[3];
    char time5[3];
    char time_empty[2];
} timeslot;

int data_validation()
{
    FILE *fl;
    fl = fopen("stu_database.csv", "r");

    if (fl == NULL)
        printf("NO file detected\n");

    student Student[80]; // object of the struct Student [80] means how many students can have in this struct

    int read = 0; // this is for read the how many parts in the row
    int row = 0;  // this is for count the number of rows in the csv

    do
    {
        read = fscanf(fl, "%9[^,],%19[^,],%10[^,]\n",
                      Student[row].stu_no,
                      Student[row].name,
                      Student[row].mobile);

            /*this %[^,] use to declear the data type
            thats mean this is also a pointer(array) so dont need to
            put %s or %d when we use that kind of data type we need to put those

            also keep it mind use less character than intialized variable
            ^ simple for stop before ,

            %9[^,]: Reads up to 9 characters
            (excluding the comma) into Student[row].stu_no.
            */

        if (read == 3)
            row++;

    } while (!feof(fl));

    fclose(fl);

    time_file = fopen("time_slots.csv", "r");

    timeslot time_slot[80];

    int read_time_parts = 0;
    int time_rows = 0;

    do
    {
        read_time_parts = fscanf(time_file, "%19[^,],%2[^,],%2[^,],%2[^,],%2[^,],%2[^,],%1[^,]\n",
                                 time_slot[time_rows].name,
                                 time_slot[time_rows].time1,
                                 time_slot[time_rows].time2,
                                 time_slot[time_rows].time3,
                                 time_slot[time_rows].time4,
                                 time_slot[time_rows].time5,
                                 time_slot[time_rows].time_empty);

        if (read_time_parts == 7)
            time_rows++;

    } while (!feof(time_file));
    fclose(time_file);
    time_rows++;

    char *input_time = (char *)malloc(3 * sizeof(char));

    printf("\nEnter your time slot to check availability:");
    printf("\nEg: 10 for check 10 AM and to check 6 PM type 18\n");
    scanf("%2s", input_time);

    printf("\nThese students are available for your chosen time...\n\n");

    for (int u = 0; u < time_rows; u++)
    {
        if (strcmp(time_slot[u].time1, input_time) == 0 ||
            strcmp(time_slot[u].time2, input_time) == 0 ||
            strcmp(time_slot[u].time3, input_time) == 0 ||
            strcmp(time_slot[u].time4, input_time) == 0 ||
            strcmp(time_slot[u].time5, input_time) == 0)
        {
            //   printf("He is FOUND\n");
            for (int j = 0; j < row; j++)
            {
                if (strcmp(Student[j].name, time_slot[u].name) == 0)
                {
                    printf("%s\n", Student[j].stu_no);
                    printf("%s\n", Student[j].name);
                    printf("%s\n\n", Student[j].mobile);
                }
            }
            printf("\n");
        }
    }
    return 0;
}




FILE *time_file;
int enter_time_slot()
{
    time_file = fopen("time_slots.csv", "a");

    char times_list[30];
    printf("\nStart with your name, then add up to 5 slots (1-hour intervals, separated by commas)");
    printf("\nEg: malan,9,11,13,16,18 \n");
    printf("As the example 9 means 9-10  &  (use only simple letters for name) \n\n");

    /*

    fgets(times_list,sizeof(times_list),stdin);

    int len=strlen(times_list); //where buff is your char array fgets is using
    if(times_list[len-1]=='\n') // this 3 lines doing skip gettting enter as \n
    times_list[len-1]='\0';

    */

    scanf("%s", times_list);

    char *token;
    const char del[2] = ",";

    token = strtok(times_list, del);
    fprintf(time_file, "\n");

    while (token != NULL)
    {
        fprintf(time_file, "%s,", token);

        token = strtok(NULL, del);
    }
    fclose(time_file);
}

