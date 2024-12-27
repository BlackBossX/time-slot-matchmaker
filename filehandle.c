#include <stdio.h>
#include "studentInfo.h"

FILE *file;
int stu_data_csv_write()
{

    file = fopen("stu_database.csv", "a");

    fprintf(file, "%s,%s,%s\n", print_stu_no(), print_stu_name(), print_stu_mobile());

    fclose(file);
}