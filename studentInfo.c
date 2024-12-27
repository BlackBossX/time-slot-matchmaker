#include <stdio.h>
#include <string.h>

char stuno[12];
char stu_name[15];
char stu_mobile[10];

int Stu_No_sizecheck(int defaultVal,int sizeEn);
int Mobile_sizecheck(int defaultVal,int sizeEn);

char get_stu_info()
{
 
    printf("Enter Your Student NO: \n");
    printf("Eg: EC2022012\n");
    scanf("%s", stuno);
    Stu_No_sizecheck(9,strlen(stuno));

    printf("\nEnter Your Name: \n");
    printf("Eg: malan (use only simple letters for name)\n");
    scanf("%s", stu_name);

    printf("\nEnter Your Mobile No: \n");
    printf("Eg: 0710000000\n");
    scanf("%s", stu_mobile);
    Mobile_sizecheck(10,strlen(stu_mobile));
}

char *print_stu_no()
{
    // this char* use to return string because we cant directly return string value. this is the returing the pointer method
    // printf("\n%s",stu_info[0]);
    return stuno;
}

char *print_stu_name()
{
    // printf("\n%s",stu_info[1]);
    return stu_name;
}

char *print_stu_mobile()
{
    // printf("\n%s",stu_info[2]);
    return stu_mobile;
}





int Stu_No_sizecheck(int defaultVal,int sizeEn){
int i=1;
while(i){
    if (defaultVal == sizeEn){
        i=0;
    }
    else{
        printf("Invalid Input Check the Example and Re Enter \n");
        scanf("%s", stuno);
        sizeEn = strlen(stuno);
    }
}
}

int Mobile_sizecheck(int defaultVal,int sizeEn){
int i=1;
while(i){
    if (defaultVal == sizeEn){
        i=0;
    }
    else{
        printf("Invalid Input Check the Example and Re Enter \n");
        scanf("%s", stu_mobile);
        sizeEn = strlen(stu_mobile);
    }
}

}




