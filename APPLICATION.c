//
// Created by abdelrhman mattar on 11/29/2023.
//

#include "APPLICATION.h"
int menu_content()
{
    printf("1- ADD STUDENTS FROM FILE\n");
    printf("2- ADD STUDENT MANUALLY\n");
    printf("3- GET STUDENT DATA BY ID\n");
    printf("4- GET STUDENT DATA BY FIRST NAME\n");
    printf("5- GET STUDENT DATA BY COURSE ID\n");
    printf("6- GET STUDENT TOTAL NUMBER\n");
    printf("7- DELETE STUDENT BY ID\n");
    printf("8- UPDATE STUDENT BY ID\n");
    printf("9- PRINT STUDENTS\n");
    printf("10- EXIT\n");
    int choice;
    scanf("%d",&choice);
    fflush(stdin);
    return choice;
}

void TASK_ONE(S_FIFO *fifo)
{
    char file_path[100];
    printf("Enter File Path : ");
    gets(file_path);
    fflush(stdin);
    add_from_file(fifo,file_path);
}
void TASK_TWO( S_FIFO *fifo , STUDENT *student)
{
    GET_STUDENT_DATA(student);
    add_student(student,fifo);
}
void TASK_THREE(S_FIFO *fifo)
{
    int id;
    printf("Enter Student ID : ");
    scanf("%d",&id);
    fflush(stdin);
    STUDENT *student = get_student_by_id(fifo,id);
    if(student != NULL)
    {
        print_student(student);
    }
    else
    {
        printf("[ERROR] Student Not Found\n");
    }
}
void TASK_FOUR(S_FIFO *fifo)
{
    char name[20]; int i;
    printf("Enter Student First Name : ");
    gets(name);
    fflush(stdin);

    STUDENT *student_arrray[MAX_STUDENTS] = {0};
    get_student_by_name(fifo,name,student_arrray);
    for(i=0;i<MAX_STUDENTS && student_arrray[i] != NULL;i++)
    {
        print_student(student_arrray[i]);
    }
    if(i == 0)
    {
        printf("[ERROR] Student Not Found\n");
    }
}
void TASK_FIVE(S_FIFO *fifo)
{
    int course_id , i;
    printf("Enter Course ID : ");
    scanf("%d",&course_id);
    fflush(stdin);
    STUDENT *student_arrray[MAX_STUDENTS] = {0};
    find_students_of_course(fifo,course_id,student_arrray);
    for(i=0;i<MAX_STUDENTS && student_arrray[i] != NULL;i++)
    {
        print_student(student_arrray[i]);
    }
    if(i == 0)
    {
        printf("[ERROR] Student Not Found\n");
    }
}
void TASK_SIX( S_FIFO *fifo)
{
    int Number_Of_Students = get_student_count( fifo);
    int empty_slots = MAX_STUDENTS - Number_Of_Students;

    printf("Total Number Of Students : %d\n", Number_Of_Students);
    printf("Empty Slots : %d\n", empty_slots);
}
void TASK_SEVEN(S_FIFO *fifo)
{
    int id;
    printf("Enter Student ID : ");
    scanf("%d",&id);
    fflush(stdin);
    if(delete_student_by_id(fifo,id) == 1)
    {
        printf("[SUCCESS] Student Deleted\n");
    }
    else
    {
        printf("[ERROR] Student Not Found\n");
    }
}

void TASK_EIGHT(S_FIFO *fifo)
{
    int id;
    printf("Enter Student ID : ");
    scanf("%d",&id);
    fflush(stdin);
    STUDENT *student = get_student_by_id(fifo,id);
    if(student != NULL)
    {
        UPDATE_STUDENT_DATA(student);
    }
    else
    {
        printf("[ERROR] Student Not Found\n");
    }
}
void TASK_NINE(S_FIFO *fifo)
{
    print_students(fifo);
}
void TASK_TEN()
{
    exit(0);
}
