//
// Created by abdelrhman mattar on 11/29/2023.
//

#ifndef STUDENT_MANGMENT_STRUCT_H
#define STUDENT_MANGMENT_STRUCT_H

//we make this define to make it easy to change the number of courses
// and to avoid linker errors when use STUDENT struct in other files

#define courses_count 5
typedef struct student{
    char first_name[20];
    char last_name[20];
    int id;
    float gpa;
    int courses[courses_count];
} STUDENT;

#endif //STUDENT_MANGMENT_STRUCT_H
