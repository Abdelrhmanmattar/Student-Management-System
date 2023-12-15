//
// Created by abdelrhman mattar on 11/23/2023.
//

#include "FIFO.h"

FIFO_Error FIFO_Init(S_FIFO* fifo,element_type* buffer,unsigned int length)
{
    if(!fifo || !buffer || !length)return FIFO_NULL;
    fifo->base=buffer;
    fifo->head=buffer;
    fifo->tail=buffer;
    fifo->capacity=length;
    fifo->count=0;
    return FIFO_NO_ERROR;
}
FIFO_Error FIFO_ENQUEUE(S_FIFO* fifo,element_type data)
{
    if(!fifo || !fifo->base )return FIFO_NULL;
    if(fifo->count==fifo->capacity)return FIFO_FULL;
    *(fifo->head)=data;
    fifo->count++;
    if( (fifo->head) == (fifo->base+fifo->capacity-1) )
         fifo->head=fifo->base;
    else fifo->head++;
    return FIFO_NO_ERROR;
}
FIFO_Error FIFO_DEQUEUE(S_FIFO* fifo,element_type* data)
{
    if(!fifo || !fifo->base || !fifo->tail )return FIFO_NULL;
    if(fifo->count==0)return FIFO_EMPTY;
    *data = *(fifo->tail);
    fifo->count--;
    if( (fifo->tail) == (fifo->base+fifo->capacity-1) )
        fifo->tail=fifo->base;
    else fifo->tail++;
    return FIFO_NO_ERROR;
}
FIFO_Error FIFO_IS_FULL(S_FIFO* fifo)
{
    if(!fifo || !fifo->base )return FIFO_NULL;
    if(fifo->count==fifo->capacity)return FIFO_FULL;
    return FIFO_NOT_FULL;
}
FIFO_Error FIFO_IS_EMPTY(S_FIFO* fifo)
{
    if(!fifo || !fifo->base )return FIFO_NULL;
    if(fifo->count==0)return FIFO_EMPTY;
    return FIFO_NOT_EMPTY;
}
unsigned int FIFO_Size(S_FIFO* fifo)
{
    if(!fifo || !fifo->base )return 0;
    return fifo->count;
}
void FIFO_Print(S_FIFO* fifo)
{
    if(!fifo || !fifo->count )
    {
        printf("FIFO is Empty\n");
        return;
    }
    element_type * temp=fifo->tail;
    printf("FIFO Elements are:\n");
    for(unsigned int i=0;i<fifo->count;i++)
    {
        printf("%d\n",*temp);
        if(temp==fifo->base+fifo->capacity-1)
            temp=fifo->base;
        else temp++;
    }
    printf("End of FIFO \n");
}