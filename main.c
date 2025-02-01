#include <stdio.h>
#include <string.h>
#include "studentInfo.h"
#include "filehandle.h"
#include "timeslot.h"

int main() {
    printf("\n... Welcome to Study Buddy ...\n");
    printf("Would you like to register? (y/n):\n");
    char reg_answer;
    scanf(" %c", &reg_answer);

    while (reg_answer != 'y' && reg_answer != 'n') {
        printf("Invalid Input Enter Again\n");
        scanf(" %c", &reg_answer);

        /*
        Why space before %c ?

        this has space before %c because when we type and enter
        its get 2 values(char and \n) so its run one more loop

        To solve this issue you need to consume this \n before next read.
        Placing a space before %c specifier in scanf can consume any number
        of new-line characters
        */
    }

    if (reg_answer == 'y') {
        printf("\nPlease enter your details: \n\n");
        get_stu_info();
        stu_data_csv_write();
        printf("\nThank you for the Information\n");
    }

    printf("\nView existing slots (t) or add your slots (m): \n");
    char slot_answer;
    scanf(" %c", &slot_answer);

    while (slot_answer != 't' && slot_answer != 'm') {
        printf("Invalid Input Enter Again\n");
        scanf(" %c", &slot_answer);
    }

    if (slot_answer == 'm')
        enter_time_slot();

    printf("\nChecking available time slots...\n");

    char ans;
    do {
        data_validation();
        printf("Do you want to continue checking slots ? (y/n): \n");
        scanf(" %c", &ans);
    } while (ans == 'y');

    printf("\nHave a nice Day...\n\n");
}
