/***************************************************************************//**
 \addtogroup SORT_STACK_ITERATIVE
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       sort_stack_iterative.c
 \details    Sort a stack iteratively
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
Initial Stack : 4 3 2 1 <-- Top
temp_stack    :

Step 1.1 : Initial Stack : 4 3 2   <-- Top
           temp stack    : 1       <-- Top

Step 1.2 : Initial Stack : 4 3 1   <-- Top
           temp stack    : 2       <-- Top

Step 1.3 : Initial Stack : 4 3     <-- Top
           temp stack    : 2 1     <-- Top

Step 1.4 : Initial Stack : 4 1 2   <-- Top
           temp stack    : 3       <-- Top

Step 1.5 : Initial Stack : 4 1     <-- Top
           temp stack    : 3 2     <-- Top

Step 1.6 : Initial Stack : 4       <-- Top
           temp stack    : 3 2 1   <-- Top

Step 1.7 : Initial Stack : 1 2 3   <-- Top
           temp stack    : 4       <-- Top

Step 1.8 : Initial Stack : 1 2     <-- Top
           temp stack    : 4 3     <-- Top

Step 1.9 : Initial Stack : 1       <-- Top
           temp stack    : 4 3 2   <-- Top

Step 1.10: Initial Stack :         <-- Top
           temp stack    : 4 3 2 1 <-- Top

Step 2   : Initial Stack : 1 2 3 4 <-- Top
           temp stack    :

*/

/***************************************************************************//**
  \details  Reverse stack using recursion
  \return
*******************************************************************************/
void sort_stack_iterative(STK_S32_ *stk)
{
  STK_S32_ *temp_stk = stk_create_s32(MAX_STK_SIZE);
  int element ;
  while (!stk_is_empty_s32(stk)) {
    element = stk_pop_s32(stk);
    while(!stk_is_empty_s32(temp_stk) && element > stk_top_s32(temp_stk)) {
      stk_push_s32(stk, stk_pop_s32(temp_stk));
    }
    stk_push_s32(temp_stk, element);
  }
  while(!stk_is_empty_s32(temp_stk)) {
    stk_push_s32(stk, stk_pop_s32(temp_stk));
  }
  stk_delete_s32(temp_stk);
}
/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  STK_S32_ *stk ;
  int  pop, element ;
  char ans ;

  stk = stk_create_s32(MAX_STK_SIZE);

  /* PUSH element into stack interactively */
  do {
    printf("\nEnter a new integer element to be pushed into the stack:");
    scanf("%d", &element);
    stk_push_s32(stk, element);
    printf("TOP ===>");
    stk_print_s32(stk);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /* SORT stack interactively */
  printf("\nDo you want to sort the stack (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    printf("After stack sort operation\n");
    sort_stack_iterative(stk) ;
    printf("TOP ===>");
    stk_print_s32(stk);
    printf("\nDo you want to sort stack again (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }

  /* POP element from stack interactively */
  printf("\nDo you want to pop a new element (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_pop_s32(stk);
    printf("\nPopped element : %d\n", pop);
    printf("TOP ===>");
    stk_print_s32(stk);
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_delete_s32(stk) ;
  return 0 ;
}
