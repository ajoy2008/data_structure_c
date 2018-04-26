/***************************************************************************//**
 \addtogroup TWO_STACK_DEMO_BASIC_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       two_stack_demo_basic_s32.c
 \details    Demonstration of two stack using single array
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
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
  STK_TWO_S32_ *stk ;
  int  pop, element ;
  char ans ;

  stk = stk_two_create_s32(MAX_STK_SIZE);

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 1 PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack 1:");
    scanf("%d", &element);
    stk_two_push_s32(stk, STK_1, element);
    printf("STK_1 Size = %d\n", stk_two_size_s32(stk, STK_1));
    printf("STK_1 TOP ===>");
    stk_two_print_s32(stk, STK_1);
    printf("\nDo you want to push a new element into the stack 1 (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 2 PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack 2:");
    scanf("%d", &element);
    stk_two_push_s32(stk, STK_2, element);
    printf("STK_2 Size = %d\n", stk_two_size_s32(stk, STK_2));
    printf("STK_2 TOP ===>");
    stk_two_print_s32(stk, STK_2);
    printf("\nDo you want to push a new element into the stack 2 (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 1 POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element from stack 1 (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_two_pop_s32(stk, STK_1);
    printf("\nSTK_1 Popped element : %d\n", pop);
    printf("STK_1 Size = %d\n", stk_two_size_s32(stk, STK_1));
    printf("TOP ===>");
    stk_two_print_s32(stk, STK_1);
    printf("\nDo you want to pop a new element from stack 1(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 2 POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element from stack 2 (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_two_pop_s32(stk, STK_2);
    printf("\nSTK_2 Popped element : %d\n", pop);
    printf("STK_2 Size = %d\n", stk_two_size_s32(stk, STK_2));
    printf("TOP ===>");
    stk_two_print_s32(stk, STK_2);
    printf("\nDo you want to pop a new element from stack 2(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_two_delete_s32(stk) ;
  return 0 ;
}
