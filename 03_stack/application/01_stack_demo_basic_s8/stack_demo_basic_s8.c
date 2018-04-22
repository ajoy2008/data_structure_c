/***************************************************************************//**
 \addtogroup STACK_DEMO_BASIC_S8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       stack_demo_basic_s8.c
 \details    Demonstration of Array or Linked List based stack operation
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
  STK_S8_ *stk_s8 ;
  char  pop, element ;
  char ans ;

  stk_s8 = stk_create_s8(MAX_STK_SIZE);

  /****************************************************************************/
  /*               DEMONSTRATION OF STACK PUSH OPERATION                      */
  /****************************************************************************/
  do {
    printf("\nEnter a new character element to be pushed into the stack:");
    scanf(" %c", &element);
    stk_push_s8(stk_s8, element);
    printf("TOP ===>");
    stk_print_s8(stk_s8);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf(" %c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*               DEMONSTRATION OF STACK POP OPERATION                       */
  /****************************************************************************/
  printf("\nDo you want to pop a new element (y/n)?\n");
  getchar();
  scanf(" %c", &ans);
  while(ans == 'y') {
    pop = stk_pop_s8(stk_s8);
    printf("\nPopped element : %c\n", pop);
    printf("TOP ===>");
    stk_print_s8(stk_s8);
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf(" %c", &ans);
  }
  stk_delete_s8(stk_s8) ;
  return 0 ;
}