/***************************************************************************//**
 \addtogroup THREE_STACK_DEMO_BASIC_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       three_stack_demo_basic_s32.c
 \details    Demonstration of three stack using single array
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <stdio.h>

#define MAX_STK_SIZE 15

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  STK_K_S32_ *stk ;
  int  pop, element ;
  char ans ;

  stk = stk_k_create_s32(3, MAX_STK_SIZE);
  stk_k_debug_print_s32(stk);
  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 0 PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack 0: ");
    scanf("%d", &element);
    stk_k_push_s32(stk, 0, element);
	stk_k_debug_print_s32(stk);
    //printf("STK_0 Size = %d\n", stk_k_size_s32(stk, 0));
    //printf("STK_0 TOP ===>");
    //stk_k_print_s32(stk, 0);
    printf("\nDo you want to push a new element into the stack 0 (y/n)? ");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 1 PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack 1: ");
    scanf("%d", &element);
    stk_k_push_s32(stk, 1, element);
	stk_k_debug_print_s32(stk);
    //printf("STK_1 Size = %d\n", stk_k_size_s32(stk, 1));
    //printf("STK_1 TOP ===>");
    //stk_k_print_s32(stk, 1);
    printf("\nDo you want to push a new element into the stack 1 (y/n)? ");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');
  
  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 2 PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack 2: ");
    scanf("%d", &element);
    stk_k_push_s32(stk, 2, element);
	stk_k_debug_print_s32(stk);
    //printf("STK_2 Size = %d\n", stk_k_size_s32(stk, 2));
    //printf("STK_2 TOP ===>");
    //stk_k_print_s32(stk, 2);
    printf("\nDo you want to push a new element into the stack 2 (y/n)? ");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');
  
  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 0 POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element from stack 0 (y/n)? ");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_k_pop_s32(stk, 0);
    printf("\nSTK_0 Popped element : %d\n", pop);
	stk_k_debug_print_s32(stk);
    //printf("STK_0 Size = %d\n", stk_k_size_s32(stk, 0));
    //printf("STK_0 TOP ===>");
    //stk_k_print_s32(stk, 0);
    printf("\nDo you want to pop a new element from stack 0(y/n)? ");
    getchar();
    scanf("%c", &ans);
  }

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 1 POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element from stack 1 (y/n)? ");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_k_pop_s32(stk, 1);
    printf("\nSTK_1 Popped element : %d\n", pop);
	stk_k_debug_print_s32(stk);
    //printf("STK_1 Size = %d\n", stk_k_size_s32(stk, 1));
    //printf("STK_1 TOP ===>");
    //stk_k_print_s32(stk, 1);
    printf("\nDo you want to pop a new element from stack 1(y/n)? ");
    getchar();
    scanf("%c", &ans);
  }

  /****************************************************************************/
  /*             DEMONSTRATION OF STACK 2 POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element from stack 2 (y/n)? ");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_k_pop_s32(stk, 2);
    printf("\nSTK_2 Popped element : %d\n", pop);
	stk_k_debug_print_s32(stk);
    //printf("STK_2 Size = %d\n", stk_k_size_s32(stk, 2));
    //printf("STK_2 TOP ===>");
    //stk_k_print_s32(stk, 2);
    printf("\nDo you want to pop a new element from stack 2(y/n)? ");
    getchar();
    scanf("%c", &ans);
  }
  stk_k_delete_s32(stk) ;
  return 0 ;
}
