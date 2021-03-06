/***************************************************************************//**
 \addtogroup QUEUE_USING_STACK_2
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       queue_using_stack_2.c
 \details    Queue using stack (By making enqueue operation costly)
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#define MAX_QUEUE_SIZE 16
/**
**  Data Structure to implement queue using two stack
*/
typedef struct
{
  STK_S32_ *stk1 ;
  STK_S32_ *stk2 ;

} QUEUE_S32_;

/*******************************************************************************
  PURPOSE:  Create an array queue of integer (S32) type using stack
*******************************************************************************/
QUEUE_S32_* queue_create_s32( int queue_size )
{
  QUEUE_S32_ *q = (QUEUE_S32_*)malloc(sizeof(QUEUE_S32_));
  if(q == NULL)
    return NULL ;
  q->stk1 = stk_create_s32(queue_size);
  q->stk2 = stk_create_s32(queue_size);
  return (q);
}

/*******************************************************************************
  PURPOSE:  Insert an S32 element into the queue
*******************************************************************************/
void enqueue_s32(QUEUE_S32_ *q, int element)
{
  stk_push_s32(q->stk1, element);
}

/*******************************************************************************
  PURPOSE:  Delete an S32 element from the queue
*******************************************************************************/
int dequeue_s32(QUEUE_S32_ *q)
{
  /* If both the stacks are empty then return Error */
  if(stk_is_empty_s32(q->stk1) && stk_is_empty_s32(q->stk2)) {
    printf("\nQueue Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  /* If Stack2 is empty,
     then Until stack1 becomes empty, push everything from stack1 to stack2 */
  if(stk_is_empty_s32(q->stk2)) {
    while(!stk_is_empty_s32(q->stk1)) {
      stk_push_s32(q->stk2, stk_pop_s32(q->stk1));
    }
  }
  /* POP the element from Stack2 and return it */
  if(!stk_is_empty_s32(q->stk2))
    return(stk_pop_s32(q->stk2));
  else
    exit(EXIT_FAILURE);
}

/*******************************************************************************
  PURPOSE:  Delete an S32 element from the queue
*******************************************************************************/
void queue_print_s32(STK_S32_ *stk)
{
  stk_print_s32(stk);
}

/*******************************************************************************
  PURPOSE: Delete the entire queue from the memory
*******************************************************************************/
void queue_delete_s32(QUEUE_S32_ *q)
{
  if(q) {
    stk_delete_s32(q->stk1);
    stk_delete_s32(q->stk2);
  }
  free(q);
  return ;
}
/***************************************************************************//**
  \details  The main function starts from here

  \return   Zero
*******************************************************************************/
int main(void)
{
  char ans ;
  int element, dq ;

  QUEUE_S32_ *q = queue_create_s32(MAX_QUEUE_SIZE);

  do
  {
    printf("\nEnter an element to be enqueued: ");
    scanf("%d", &element);
    enqueue_s32(q, element);
    printf("REAR===>");
    queue_print_s32(q->stk1);
    printf("<===FRONT");
    printf("\nDo you want to enqueue a new element(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }while(ans == 'y');

  printf("\nDo you want to dequeue an element(y/n)?\n");
  getchar();
  scanf("%c", &ans);
  while(ans == 'y')
  {
    dq = dequeue_s32(q);
    printf("\nDe queued element : %d\n",dq);
    printf("FRONT===>");
    queue_print_s32(q->stk2);
    printf("<===REAR");
    printf("\nDo you want to dequeue another element(y/n)?\n");
    getchar();
    scanf("%c", &ans);
  }
  queue_delete_s32(q);
  return 0;
}