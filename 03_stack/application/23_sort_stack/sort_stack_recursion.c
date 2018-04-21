/***************************************************************************//**
 \addtogroup SORT_STACK_RECURSION
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       sort_stack_recursive.c
 \details    Sort a stack recursively
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
Initial Stack : 2 1 4 3 <-- Top

sort_stack(2,1,4,3)
sort_stack(1, 4, 3) sorted_insert(2) <-- Top
sort_stack(4, 3)    sorted_insert(2), sorted_insert(1) <-- Top
sort_stack(3)       sorted_insert(2), sorted_insert(1), sorted_insert(4) <-- Top
                    sorted_insert(2), sorted_insert(1), sorted_insert(4) sorted_insert(3) <-- Top

sorted_insert(3) : 3 <-- Top
sorted_insert(4) : 3, 4 <-- Top
sorted_insert(1) : 1, 3, 4 <-- Top
sorted_insert(2) : 1, 2, 3, 4 <-- Top

*/
/***************************************************************************//**
  \details  Insert element at bottom
  \return
*******************************************************************************/
void sorted_insert(STK_S32_ *stk, int item)
{
  int temp ;
  if (stk_is_empty_s32(stk) || item > stk_top_s32(stk)) {
    stk_push_s32(stk, item);
  } else {
    temp = stk_pop_s32(stk);
    sorted_insert(stk, item);
    stk_push_s32(stk, temp);
  }
}

/***************************************************************************//**
  \details  Reverse stack using recursion
  \return
*******************************************************************************/
void sort_stack_recursion(STK_S32_ *stk)
{
  int temp ;
  if (!stk_is_empty_s32(stk)){
    temp = stk_pop_s32(stk);
    sort_stack_recursion(stk);
    sorted_insert(stk, temp);
  }
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
    sort_stack_recursion(stk) ;
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
