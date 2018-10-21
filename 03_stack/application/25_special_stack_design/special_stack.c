/***************************************************************************//**
 \addtogroup QUEUE_USING_STACK_1
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       queue_using_stack_1.c
 \details    Queue using stack (By making enqueue operation costly)
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#define SPECIAL_STK_MAX_SIZE 16
/**
**  Data Structure to implement queue using two stack
*/
typedef struct
{
  STK_S32_ *orig_stk ;
  STK_S32_ *aux_stk ;
}SPECIAL_STK_S32_;

/*******************************************************************************
  PURPOSE:  Create an array queue of integer (S32) type using stack
*******************************************************************************/
SPECIAL_STK_S32_* special_stack_create_s32( size_t stk_size)
{
  SPECIAL_STK_S32_ *special_stk = (SPECIAL_STK_S32_*)malloc(sizeof(SPECIAL_STK_S32_));
  if(special_stk == NULL)
    return NULL ;
  special_stk->orig_stk = stk_create_s32(stk_size);
  special_stk->aux_stk  = stk_create_s32(stk_size);
  return (special_stk);
}

int special_stack_is_empty_s32(SPECIAL_STK_S32_ *special_stk)
{
  return( stk_is_empty_s32(special_stk->orig_stk) && stk_is_empty_s32(special_stk->aux_stk));
}

/*******************************************************************************
  PURPOSE:  Insert an S32 element into the queue
*******************************************************************************/
void special_stack_push_s32(SPECIAL_STK_S32_ *special_stk, int data)
{
  if(special_stack_is_empty_s32(special_stk)) {
    stk_push_s32(special_stk->orig_stk, data);
    stk_push_s32(special_stk->aux_stk, data);
  } else {
    stk_push_s32(special_stk->orig_stk, data);
    if(data <= stk_top_s32(special_stk->aux_stk)) {
      stk_push_s32(special_stk->aux_stk, data);
    }
  }
}

int special_stack_pop_s32(SPECIAL_STK_S32_ *special_stk)
{
   int pop ;
   if(stk_top_s32(special_stk->orig_stk) == stk_top_s32(special_stk->aux_stk)) {
       pop = stk_pop_s32(special_stk->aux_stk);
       pop = stk_pop_s32(special_stk->orig_stk);
   } else {
       pop = stk_pop_s32(special_stk->orig_stk);
   }
   return (pop);
}

int special_stack_get_min_s32(SPECIAL_STK_S32_ *special_stk)
{
    return(stk_top_s32(special_stk->aux_stk));
}

void special_stack_print_s32(SPECIAL_STK_S32_ *special_stk) {
    stk_print_s32(special_stk->orig_stk);
}

/***************************************************************************//**
  \details  The main function starts from here

  \return   Zero
*******************************************************************************/
int main(void)
{
  char ans ;
  int element, pop ;
  int min ;

  SPECIAL_STK_S32_ *special_stack = special_stack_create_s32(SPECIAL_STK_MAX_SIZE);

  do
  {
    printf("\nEnter an element to be pushed into special stack: ");
    scanf("%d", &element);
    special_stack_push_s32(special_stack, element);
    printf("TOP ===>");
    special_stack_print_s32(special_stack);
    printf("\nDo you want to push a new element into special stack(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }while(ans == 'y');

  min = special_stack_get_min_s32(special_stack);
  printf("Minimum element into special stack = %d\n",min);

  printf("\nDo you want to pop an element from special stack(y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y')
  {
    pop = special_stack_pop_s32(special_stack);
    printf("\npopped element : %d\n",pop);
    printf("TOP ===>");
    special_stack_print_s32(special_stack);
    printf("\nDo you want to pop another element from special stack(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  min = special_stack_get_min_s32(special_stack);
  printf("Minimum element into special stack = %d\n",min);
  return 0;
}
