/***************************************************************************//**
 \addtogroup ARR_STK_K_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_k_s32.c
 \details    K number of stack implementation using single array
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <arr_stk_k_s32.h>

/*******************************************************************************
  PURPOSE:  To create K number of array stack using single array
  COMMENT:
*******************************************************************************/
ARR_STK_K_S32_* arr_stk_k_create_s32(unsigned int no_of_stacks, unsigned int size)
{
  int i ;
  ARR_STK_K_S32_ *s = (ARR_STK_K_S32_ *)malloc(sizeof(ARR_STK_K_S32_));
  if(s == NULL)
    return NULL ;

  s->n  = size ;
  s->k  = no_of_stacks ;
  s->fr = 0 ; // Initialize all spaces as free

  s->arr = (int *)malloc(s->n * sizeof(int));
  if(s->arr == NULL)  return NULL ;
  s->top = (int *)malloc(s->k * sizeof(int));
  if(s->top == NULL)  return NULL ;
  s->next = (int *)malloc(s->n * sizeof(int));
  if(s->next == NULL) return NULL ;

  for (i=0; i < s->n; i++)
    s->arr[i] = 0;

  // Initialize all stacks as empty
  for (i = 0; i < s->k; i++) {
    s->top[i] = -1;
  }

  for (i=0; i < s->n - 1; i++)
    s->next[i] = i+1;
  s->next[s->n - 1] = -1;  // -1 is used to indicate end of free list
  return (s);
}

/*******************************************************************************
 PURPOSE:  To check the Kth stack is empty or not
 COMMENT:
*******************************************************************************/
int arr_stk_k_is_empty_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel)
{
  return(s->top[stk_sel] == -1);
}

/*******************************************************************************
 PURPOSE:  To check the stack is full or not
 COMMENT:
*******************************************************************************/
int arr_stk_k_is_full_s32(ARR_STK_K_S32_ *s)
{
  return(s->fr == -1);
}

/*******************************************************************************
 PURPOSE:  To push an element into Kth stack
 COMMENT:
*******************************************************************************/
void arr_stk_k_push_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel, int data)
{
  int i ;
  if(arr_stk_k_is_full_s32(s)) {
    printf("\nStack %d Overflow Error\n", stk_sel);
    exit(EXIT_FAILURE);
  }
  // Store index of first free slot
  i = s->fr;
  // Update index of free slot to index of next slot in free list
  s->fr = s->next[i];
  // Update next of top and then top for stack number 'sn'
  s->next[i] = s->top[stk_sel];
  s->top[stk_sel] = i;
  // Put the item in array
  s->arr[i] = data;
}
/*******************************************************************************
 PURPOSE:  To pop an element from the stack
 COMMENT:
*******************************************************************************/
int arr_stk_k_pop_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel)
{
  int i ;
  if(arr_stk_k_is_empty_s32(s, stk_sel)) {
    printf("\nStack %d Underflow Error\n", stk_sel);
    exit(EXIT_FAILURE);
  }

  // Find index of top item in selected stack
  i = s->top[stk_sel];

  // Change top to store next of previous top
  s->top[stk_sel] = s->next[i];

  // Attach the previous top to the beginning of free list
  s->next[i] = s->fr;
  s->fr = i;

  // Return the previous top item
  return s->arr[i];
}

/*******************************************************************************
 PURPOSE:  To return the top element from the stack without popping
 COMMENT:
*******************************************************************************/
int arr_stk_k_top_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel)
{
  int i ;
  if(arr_stk_k_is_empty_s32(s, stk_sel)) {
    printf("\nStack %d Underflow Error\n", stk_sel);
    exit(EXIT_FAILURE);
  }

  // Find index of top item in selected stack
  i = s->top[stk_sel];

  // Return the previous top item
  return s->arr[i];
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the stack
 COMMENT:
*******************************************************************************/
int arr_stk_k_size_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel)
{
  return 0 ;
}

/*******************************************************************************
 PURPOSE:  To print the list stack elements
 COMMENT:
*******************************************************************************/
void arr_stk_k_print_s32(ARR_STK_K_S32_ *s, unsigned int stk_sel)
{
  return ;
}

/*******************************************************************************
 PURPOSE:  To delete the array stack
 COMMENT:
*******************************************************************************/
void arr_stk_k_delete_s32(ARR_STK_K_S32_ *s)
{
  if(s) {
    if(s->arr)  free(s->arr);
    if(s->top)  free(s->top);
    if(s->next) free(s->next);
    free(s);
  }
  return ;
}

/*******************************************************************************
 PURPOSE:  To print the list stack elements
 COMMENT:
*******************************************************************************/
void arr_stk_k_debug_print_s32(ARR_STK_K_S32_ *s)
{
  int i ;
  printf("n    = %d\n", s->n);
  printf("k    = %d\n", s->k);
  printf("free = %d\n", s->fr);
  printf("\narr[] : ");
  for(i=0; i<s->n; i++) {
    printf("%d  ", s->arr[i]);
  }
  printf("\ntop[] : ");
  for(i=0; i<s->k; i++) {
	printf("%d  ", s->top[i]);
  }
  printf("\nnxt[] : ");
  for(i=0; i<s->n; i++) {
	printf("%d  ", s->next[i]);
  }
  printf("\n");
  return ;
}
/** @} */