//
// Created by abdelrhman mattar on 11/27/2023.
//

#ifndef STUDENT_MANGMENT_STUDENT_H
#define STUDENT_MANGMENT_STUDENT_H
#include "struct.h"
#include <stdio.h>
#include <string.h>
#include "FIFO.h"

/*this function is used to get the student data from the user
  it takes the student pointer and the student id*/
void GET_STUDENT_DATA(STUDENT *student);
/*this function is used to update the student data
  it takes the student pointer*/
void UPDATE_STUDENT_DATA(STUDENT *student);
/*this function is used to print the student data
  it takes the student pointer*/
void print_student(STUDENT *student);


/* THIS FUNCTIONS ARE USED TO TAKE STUDENT DATA FROM FILE AND ADD IT TO THE FIFO
 * IT TAKES THE FIFO POINTER AND THE FILE PATH
 * THE FORMAT OF THE FILE IS :
 * FIRST_NAME LAST_NAME ID GPA COURSE_IDs
 * */
void add_from_file( S_FIFO *fifo, char *file_path);

/* THIS FUNCTIONS ARE USED TO ADD STUDENT MANUALLY TO THE FIFO*/
void add_student(STUDENT *student, S_FIFO *fifo);

/* THIS FUNCTIONS ARE USED TO GET STUDENT DATA FROM THE FIFO BY ID*/
STUDENT *get_student_by_id(S_FIFO *fifo,int id);

/* THIS FUNCTIONS ARE USED TO GET STUDENT DATA FROM THE FIFO BY NAME
 *  IT TAKES THE FIFO POINTER AND THE NAME OF THE STUDENT
 *  AND STORE THE STUDENT DATA IN THE STUDENT POINTER
 * */
void get_student_by_name(S_FIFO *fifo , char *name , STUDENT **output);

/* THIS FUNCTIONS ARE USED TO GET STUDENT DATA FROM THE FIFO BY COURSE ID
 *  IT TAKES THE FIFO POINTER AND THE COURSE ID
 *  AND STORE THE STUDENT DATA IN THE STUDENT POINTER
 * */
void find_students_of_course(S_FIFO *fifo ,int course_id ,STUDENT **output);

// THIS FUNCTION IS USED TO GET THE STUDENT COUNT IN THE FIFO
int get_student_count(S_FIFO *fifo);

/* THIS FUNCTIONS ARE USED TO DELETE STUDENT DATA FROM THE FIFO BY ID*/
int delete_student_by_id(S_FIFO *fifo,int id);
void print_students(S_FIFO *fifo);

#endif //STUDENT_MANGMENT_STUDENT_H
