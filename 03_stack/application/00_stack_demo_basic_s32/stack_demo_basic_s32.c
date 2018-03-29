/***************************************************************************//**
 \addtogroup STACK_DEMO_BASIC_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       stack_demo_basic_s32.c
 \details    Demonstration of Array or Linked List based stack operation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <stdio.h>

#define MAX_STK_SIZE 16

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
    STK_S32_ *stk_s32 ;
    int  P1, element1 ;
    char ans ;

    stk_s32 = stk_create_s32(MAX_STK_SIZE);

    /****************************************************************************/
    /*               DEMONSTRATION OF STACK PUSH OPERATION                      */
    /****************************************************************************/
    do {
        printf("\nEnter a new integer element to be pushed into the stack:");
        scanf("%d", &element1);
        stk_push_s32(stk_s32, element1);

        printf("\nDo you want to push a new element into the stack (y/n)?\n");
        getchar();
        scanf("%c", &ans);
    }while(ans == 'y');

    /****************************************************************************/
    /*               DEMONSTRATION OF STACK POP OPERATION                       */
    /****************************************************************************/
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf("%c", &ans);
    while(ans == 'y') {
        P1 = stk_pop_s32(stk_s32);
        printf("\nPopped element : %d\n", P1);
        printf("\nDo you want to pop a new element (y/n)?\n");
        getchar();
        scanf("%c", &ans);
    }
    stk_delete_s32(stk_s32) ;
    return 0 ;
}
