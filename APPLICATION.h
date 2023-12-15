//
// Created by abdelrhman mattar on 11/29/2023.
//

#ifndef STUDENT_MANGMENT_APPLICATION_H
#define STUDENT_MANGMENT_APPLICATION_H

#include "student.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 50
int menu_content();


void TASK_ONE(S_FIFO *fifo);
void TASK_TWO( S_FIFO *fifo , STUDENT *student);
void TASK_THREE(S_FIFO *fifo);
void TASK_FOUR(S_FIFO *fifo);
void TASK_FIVE(S_FIFO *fifo);
void TASK_SIX( S_FIFO *fifo);
void TASK_SEVEN(S_FIFO *fifo);
void TASK_EIGHT(S_FIFO *fifo);
void TASK_NINE(S_FIFO *fifo);
void TASK_TEN();



#endif //STUDENT_MANGMENT_APPLICATION_H
