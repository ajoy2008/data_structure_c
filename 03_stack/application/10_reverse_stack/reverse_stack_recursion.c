/***************************************************************************//**
 \addtogroup REVERSE_STACK
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       reverse_stack_recursion.c
 \details    Reverse a stack recursively
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <stdio.h>

#define MAX_STK_SIZE 16

/* IDEA :
Initial Stack : 1 2 3 4 <-- Top

rev_stack(1,2,3,4)
rev_stack(1, 2, 3) insert_bottom(4) <-- Top
rev_stack(1, 2)    insert_bottom(4), insert_bottom(3) <-- Top
rev_stack(1)       insert_bottom(4), insert_bottom(3), insert_bottom(2) <-- Top
                   insert_bottom(4), insert_bottom(3), insert_bottom(2) insert_bottom(1) <-- Top

insert_bottom(1) : 1 <-- Top
insert_bottom(2) : 2, 1 <-- Top
insert_bottom(3) : 3, 2, 1 <-- Top
insert_bottom(4) : 4 3, 2, 1 <-- Top

*/
/***************************************************************************//**
  \details  Insert element at bottom
  \return
*******************************************************************************/
void insert_at_bottom(STK_S32_ *stk_s32, int item)
{
  int temp ;
  if (stk_is_empty_s32(stk_s32)) {
    stk_push_s32(stk_s32, item);
  } else {
    temp = stk_pop_s32(stk_s32);
    insert_at_bottom(stk_s32, item);
    stk_push_s32(stk_s32, temp);
  }
}

/***************************************************************************//**
  \details  Reverse stack using recursion
  \return
*******************************************************************************/
void reverse_stack_recursion(STK_S32_ *stk_s32)
{
  int temp ;
  if (!stk_is_empty_s32(stk_s32)){
    temp = stk_pop_s32(stk_s32);
    reverse_stack_recursion(stk_s32);
    insert_at_bottom(stk_s32, temp);
  }
}
/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  STK_S32_ *stk_s32 ;
  int  element ;
  char ans ;

  stk_s32 = stk_create_s32(MAX_STK_SIZE);

  /* PUSH element into stack interactively */
  do {
    printf("\nEnter a new integer element to be pushed into the stack:");
    scanf("%d", &element);
    stk_push_s32(stk_s32, element);
    stk_print_s32(stk_s32);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  printf("After stack reverse operation\n");
  reverse_stack_recursion(stk_s32) ;
  stk_print_s32(stk_s32);

  stk_delete_s32(stk_s32) ;
  return 0 ;
}
