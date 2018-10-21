/***************************************************************************//**
 \addtogroup STACK_DEMO_GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       stack_demo_generic.c
 \details    Demonstration of Array or Linked List based generic stack operation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <stdio.h>

#define MAX_STK_SIZE 16
#define MAX_STR_SIZE 4

void print_s32(void *data)
{
  printf("%d ", *(int *)data);
}

void print_s8(void *data)
{
  printf("%c ", *(char *)data);
}

void print_r32(void *data)
{
  printf("%f ", *(float *)data);
}

void print_str(void *data)
{
	printf("%s ", (char *)data);
}

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  int   element_s32 ;
  char  element_s8  ;
  float element_r32 ;
  char  *element_str ;
  void *pop ;
  char ans ;

  STK_ *stk_s32 = stk_create(MAX_STK_SIZE, sizeof(int));
  STK_ *stk_s8  = stk_create(MAX_STK_SIZE, sizeof(char));
  STK_ *stk_r32 = stk_create(MAX_STK_SIZE, sizeof(float));
  STK_ *stk_str = stk_create(MAX_STK_SIZE, sizeof(char *));

  /****************************************************************************/
  /*               DEMONSTRATION OF S32 STACK PUSH OPERATION                  */
  /****************************************************************************/
  do {
    printf("\nEnter a new integer element to be pushed into the stack:");
    scanf("%d", &element_s32);
    stk_push(stk_s32, &element_s32);
    printf("TOP ===>");
    stk_print(stk_s32, print_s32);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*               DEMONSTRATION OF S32 STACK POP OPERATION                   */
  /****************************************************************************/
  printf("\nDo you want to pop a new element (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = (int *)stk_pop(stk_s32);
    printf("\nPopped element : %d\n", *(int *)pop);
    printf("TOP ===>");
    stk_print(stk_s32, print_s32);
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_delete(stk_s32) ;

  /****************************************************************************/
  /*               DEMONSTRATION OF S8 STACK PUSH OPERATION                   */
  /****************************************************************************/
  do {
    printf("\nEnter a new character element to be pushed into the stack:");
    getchar();
    scanf("%c", &element_s8);
    stk_push(stk_s8, &element_s8);
    printf("TOP ===>");
    stk_print(stk_s8, print_s8);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*               DEMONSTRATION OF S8 STACK POP OPERATION                    */
  /****************************************************************************/
  printf("\nDo you want to pop a new element (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_pop(stk_s8);
    printf("\nPopped element : %c\n", *(char *)pop);
    printf("TOP ===>");
    stk_print(stk_s8, print_s8);
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_delete(stk_s8) ;

  /****************************************************************************/
  /*               DEMONSTRATION OF r32 STACK PUSH OPERATION                   */
  /****************************************************************************/
  do {
    printf("\nEnter a new float element to be pushed into the stack:");
    scanf("%f", &element_r32);
    stk_push(stk_r32, &element_r32);
    printf("TOP ===>");
    stk_print(stk_r32, print_r32);
    printf("\nDo you want to push a new element into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*               DEMONSTRATION OF r32 STACK POP OPERATION                   */
  /****************************************************************************/
  printf("\nDo you want to pop a new element (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_pop(stk_r32);
    printf("\nPopped element : %f\n", *(float *)pop);
    printf("TOP ===>");
    stk_print(stk_r32, print_r32);
    printf("\nDo you want to pop a new element (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_delete(stk_r32) ;

  /****************************************************************************/
  /*               DEMONSTRATION OF r32 STACK PUSH OPERATION                   */
  /****************************************************************************/
  do {
    element_str = (char *)malloc(sizeof(MAX_STR_SIZE));
    printf("\nEnter a string to be pushed into the stack:");
    scanf("%s", element_str);
    stk_push(stk_str, element_str);
    printf("TOP ===>");
    stk_print(stk_str, print_str);
    printf("\nDo you want to push another string into the stack (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  } while(ans == 'y');

  /****************************************************************************/
  /*               DEMONSTRATION OF r32 STACK POP OPERATION                   */
  /****************************************************************************/
  printf("\nDo you want to pop a string (y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y') {
    pop = stk_pop(stk_str);
    printf("\nPopped string : %s\n", (char *)pop);
    printf("TOP ===>");
    stk_print(stk_str, print_str);
    printf("\nDo you want to pop another string (y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  stk_delete(stk_str) ;
  return 0 ;
}
