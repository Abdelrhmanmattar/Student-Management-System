#include <stdio.h>
#include <stdlib.h>
#include "APPLICATION.h"
void clear_cmd()
{
    char enter;
    fflush(stdin);
    printf("Press Enter to clear the screen...");
    fflush(stdout);
    scanf("%c", &enter);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int main() {
    S_FIFO fifo;
    STUDENT student;
    STUDENT student_buffer[MAX_STUDENTS];
    FIFO_Init(&fifo,student_buffer,MAX_STUDENTS);
    int choice;
    while(1)
    {
        choice=menu_content();
        //choice=1;
        switch (choice)
        {
            case 1:
                TASK_ONE(&fifo);
                break;
            case 2:
                TASK_TWO(&fifo,&student);
                break;
            case 3:
                TASK_THREE(&fifo);
                break;
            case 4:
                TASK_FOUR(&fifo);
                break;
            case 5:
                TASK_FIVE(&fifo);
                break;
            case 6:
                TASK_SIX(&fifo);
                break;
            case 7:
                TASK_SEVEN(&fifo);
                break;
            case 8:
                TASK_EIGHT(&fifo);
                break;
            case 9:
                TASK_NINE(&fifo);
                break;
            case 10:
                TASK_TEN();
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        clear_cmd();
    }
}
