//
// Created by abdelrhman mattar on 11/23/2023.
//

#ifndef UNTITLED18_FIFO_H
#define UNTITLED18_FIFO_H
#include "struct.h"
#include <stdio.h>
#define element_type STUDENT

//this enum is used to return error status
//from the functions
//it is used to check if the function is executed
typedef enum{
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_NOT_FULL,
    FIFO_EMPTY,
    FIFO_NOT_EMPTY,
    FIFO_NULL
} FIFO_Error;
//this struct is used to implement FIFO
//it contains the base pointer to the buffer
//the head pointer to the next element to be enqueued
//the tail pointer to the next element to be dequeued
//the capacity of the buffer
//the count of the elements in the buffer
typedef struct
{
    element_type* base;
    element_type* head;
    element_type * tail;
    unsigned int capacity;
    unsigned int count;
}S_FIFO;

/*this function is used to initialize the FIFO
it takes the FIFO pointer and the buffer pointer and the length of the buffer*/
FIFO_Error FIFO_Init(S_FIFO* fifo,element_type * buffer,unsigned int length);


/*this function is used to enqueue an element in the FIFO
it takes the FIFO pointer and the element to be enqueued*/
FIFO_Error FIFO_ENQUEUE(S_FIFO* fifo,element_type data);


/*this function is used to dequeue an element from the FIFO
  it takes the FIFO pointer and the pointer to the element to be dequeued*/
FIFO_Error FIFO_DEQUEUE(S_FIFO* fifo,element_type * data);


/*this function is used to check if the FIFO is full
  it takes the FIFO pointer and returns FIFO_FULL if the FIFO is full
  and FIFO_NOT_FULL if the FIFO is not full*/
FIFO_Error FIFO_IS_FULL(S_FIFO* fifo);

/*this function is used to check if the FIFO is empty
  it takes the FIFO pointer and returns FIFO_EMPTY if the FIFO is empty
  and FIFO_NOT_EMPTY if the FIFO is not empty*/
FIFO_Error FIFO_IS_EMPTY(S_FIFO* fifo);

/*this function is used to get the size of the FIFO
  it takes the FIFO pointer and returns the size of the FIFO*/
unsigned int FIFO_Size(S_FIFO* fifo);

/*this function is used to print the FIFO
  it takes the FIFO pointer and prints the FIFO*/
void FIFO_Print(S_FIFO* fifo);


#endif //UNTITLED18_FIFO_H