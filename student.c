//
// Created by abdelrhman mattar on 11/27/2023.
//

#include "student.h"
void GET_STUDENT_DATA(STUDENT *student)
{
    printf("Enter Student First Name : ");
    gets(student->first_name);
    fflush(stdin);
    printf("Enter Student Last Name : ");
    gets(student->last_name);
    fflush(stdin);
    printf("Enter Student ID : ");
    scanf("%d",&student->id);
    fflush(stdin);
    printf("Enter Student GPA : ");
    scanf("%f",&student->gpa);
    fflush(stdin);
    printf("Enter Student Courses : ");
    for(int i=0;i<courses_count;i++)
    {
        scanf("%d",&student->courses[i]);
        fflush(stdin);
    }
}
void UPDATE_STUDENT_DATA(STUDENT *student)
{
    printf("1- Update First Name\n");
    printf("2- Update Last Name\n");
    printf("3- Update ID\n");
    printf("4- Update GPA\n");
    printf("5- Update Courses\n");
    fflush(stdin);
    int choice;
    scanf("%d",&choice);
    fflush(stdin);
    switch (choice)
    {
        case 1:
            printf("Enter Student First Name : ");
            gets(student->first_name);
            fflush(stdin);
            break;
        case 2:
            printf("Enter Student Last Name : ");
            gets(student->last_name);
            fflush(stdin);
            break;
        case 3:
            printf("Enter Student ID : ");
            scanf("%d",&student->id);
            fflush(stdin);
            break;
        case 4:
            printf("Enter Student GPA : ");
            scanf("%f",&student->gpa);
            fflush(stdin);
            break;
        case 5:
            printf("Enter Student Courses : ");
            for(int i=0;i<courses_count;i++)
            {
                scanf("%d",&student->courses[i]);
                fflush(stdin);
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
}
void print_student(STUDENT *student)
{
    printf("Student First Name : %s\n",student->first_name);
    printf("Student Last Name : %s\n",student->last_name);
    printf("Student ID : %d\n",student->id);
    printf("Student GPA : %.2f\n",student->gpa);
    printf("Student Courses : ");
    for(int i=0;i<courses_count;i++)
    {
        printf("%d ",student->courses[i]);
    }
    printf("\n====================================\n");
}


void add_from_file( S_FIFO *fifo, char *file_path)
{
    char buffer[256];
    char courses[50];
    char *courses_ptr = courses;
    FILE *file = fopen(file_path,"r");
    if(file == NULL)
    {
        printf("[ERROR] File Not Found\n");
        return;
    }
    STUDENT student;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %s %d %f %[^\n]", student.first_name, student.last_name, &student.id, &student.gpa, courses_ptr);
        while(*courses_ptr  == ' ')
        {
            courses_ptr++;
        }
        for(int i=0;i<courses_count;i++)
        {
            student.courses[i] = 0;
            if(*courses_ptr == '\0') continue;
            sscanf(courses_ptr,"%d",&student.courses[i]);
            while(*courses_ptr != ' ' && *courses_ptr != '\0')
            {
                courses_ptr++;
            }
            while(*courses_ptr  == ' ')
            {
                courses_ptr++;
            }
        }
        fflush(stdin);
        fflush(stdout);
        add_student(&student,fifo);
        print_student(&student);
    }
    fclose(file);
}
void add_student(STUDENT *student , S_FIFO *fifo)
{
    STUDENT *temp = get_student_by_id(fifo,student->id);
    if(temp != NULL)
    {
        printf("[ERROR] Student Not Added , ID Already Exist\n");
        return;
    }
    FIFO_Error error = FIFO_ENQUEUE(fifo , *student);
    if(error == FIFO_NO_ERROR)
    {
        printf("[INFO] Student Added Successfully\n");
    }
    else if(error == FIFO_FULL)
    {
        printf("[ERROR] Student Not Added , FIFO is Full\n");
    }
    else if(error == FIFO_NULL)
    {
        printf("[ERROR] Student Not Added , FIFO is NULL\n");
    }
}
STUDENT *get_student_by_id(S_FIFO *fifo,int id)
{
    element_type *temp = fifo->tail;
    for(int i=0;i< FIFO_Size(fifo);i++)
    {
        if(temp->id == id) return temp;
        if(temp == fifo->base+fifo->capacity-1)
            temp = fifo->base;
        else temp++;
    }
    return NULL;
}
void get_student_by_name(S_FIFO *fifo , char *name , STUDENT **output)
{
    element_type *temp = fifo->tail;
    for(int i=0;i< FIFO_Size(fifo);i++)
    {
        if(stricmp(temp->first_name,name) == 0)
        {
            *output = temp;
            output++;
            *output = NULL;
        }
        if(temp == fifo->base+fifo->capacity-1)
            temp = fifo->base;
        else temp++;
    }
}
void find_students_of_course(S_FIFO *fifo ,int course_id ,STUDENT **output)
{
    element_type *temp = fifo->tail;
    for(int i=0;i< FIFO_Size(fifo);i++)
    {
        for(int j=0;j<courses_count;j++)
        {
            if(temp->courses[j] == course_id)
            {
                *output = temp;
                output++;
                *output = NULL;
                break;
            }
        }
        if(temp == fifo->base+fifo->capacity-1)
            temp = fifo->base;
        else temp++;
    }
}
int get_student_count(S_FIFO *fifo) {
    return FIFO_Size(fifo);
}

int delete_student_by_id(S_FIFO *fifo,int id)
{
    element_type *temp = fifo->tail;
    element_type *prev = NULL;
    int i,j;
    for(i=0;i< FIFO_Size(fifo);i++) {
        if (temp->id == id) {
            prev = temp;
            temp++;
            break;
        }
        if (temp == fifo->base + fifo->capacity - 1)
            temp = fifo->base;
        else temp++;
    }
    if(i == FIFO_Size(fifo)) return 0;

    for(j=i;j< FIFO_Size(fifo);j++)
    {
        if (temp > fifo->base + fifo->capacity - 1)
            temp = fifo->base;
        if (prev > fifo->base + fifo->capacity - 1)
            prev = fifo->base;
        *prev = *temp;
        prev++;
        temp++;
    }
    fifo->count--;
    return 1;
}
void print_students(S_FIFO * fifo)
{
    element_type *temp = fifo->tail;
    for(int i=0;i< FIFO_Size(fifo);i++)
    {
        printf("Student %d : \n",i+1);
        print_student(temp);
        if(temp == fifo->base+fifo->capacity-1)
            temp = fifo->base;
        else temp++;
    }
}