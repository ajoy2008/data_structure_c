/***************************************************************************//**
 \addtogroup ARR_STK_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_s32.c
 \details    Array Stack S32 API Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <arr_stk_two_s32.h>

/*******************************************************************************
  PURPOSE:  To create an array stack
  COMMENT:
*******************************************************************************/
ARR_STK_TWO_S32_* arr_stk_two_create_s32(unsigned int stk_size)
{
  ARR_STK_TWO_S32_ *s = (ARR_STK_TWO_S32_ *)malloc(sizeof(ARR_STK_TWO_S32_));
  if(s == NULL)
    return NULL ;

  s->capacity = stk_size ;
  s->top1 = -1 ;
  s->top2 = s->capacity ;
  s->arr = (int *)malloc(s->capacity * sizeof(int));
  if(s->arr == NULL)
    return NULL ;
  else
    return (s);
}

/*******************************************************************************
 PURPOSE:  To check the array stack is empty or not
 COMMENT:
*******************************************************************************/
int arr_stk_two_is_empty_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel)
{
  if(stk_sel == STK_1) {
      return(s->top1 == -1);
  } else if(stk_sel == STK_2) {
      return(s->top2 == s->capacity);
  }
  return(0); // For invalid input return false, indicating that stack is not empty
}

/*******************************************************************************
 PURPOSE:  To check the stack is full or not
 COMMENT:
*******************************************************************************/
int arr_stk_two_is_full_s32(ARR_STK_TWO_S32_ *s)
{
  return((s->top2 - s->top1) == 1);
}

/*******************************************************************************
 PURPOSE:  To push an element into stack
 COMMENT:
*******************************************************************************/
void arr_stk_two_push_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel, int data)
{
  if(arr_stk_two_is_full_s32(s)) {
    printf("\nStack %d Overflow Error\n", stk_sel);
    exit(EXIT_FAILURE);
  }
  if(stk_sel == STK_1) {
    s->arr[++s->top1] = data ;
  } else if(stk_sel == STK_2) {
    s->arr[--s->top2] = data ;
  }
}
/*******************************************************************************
 PURPOSE:  To pop an element from the stack
 COMMENT:
*******************************************************************************/
int arr_stk_two_pop_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel)
{
  if(arr_stk_two_is_empty_s32(s, stk_sel)) {
    printf("\nStack %d Underflow Error\n", stk_sel);
    exit(EXIT_FAILURE);
  }
  if(stk_sel == STK_1) {
    return(s->arr[s->top1--]);
  } else if(stk_sel == STK_2) {
    return(s->arr[s->top2++]);
  }
  exit(EXIT_FAILURE); // In case of wrong input return failure
}

/*******************************************************************************
 PURPOSE:  To return the top element from the stack without popping
 COMMENT:
*******************************************************************************/
int arr_stk_two_top_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel)
{
  if(arr_stk_two_is_empty_s32(s, stk_sel)) {
    printf("\nStack %d underflow error\n", stk_sel);
    exit(EXIT_FAILURE);
  }
  if(stk_sel == STK_1) {
    return(s->arr[s->top1]);
  } else if(stk_sel == STK_2) {
    return(s->arr[s->top2]);
  }
  exit(EXIT_FAILURE); // In case of wrong input return failure
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the stack
 COMMENT:
*******************************************************************************/
int arr_stk_two_size_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel)
{
  if(stk_sel == STK_1) {
    return(s->top1 + 1);
  } else if(stk_sel == STK_2) {
    return(s->capacity - s->top2);
  }
  exit(EXIT_FAILURE); // In case of wrong input return failure
}

/*******************************************************************************
 PURPOSE:  To print the list stack elements
 COMMENT:
*******************************************************************************/
void arr_stk_two_print_s32(ARR_STK_TWO_S32_ *s, STK_SEL_ stk_sel)
{
  int i = 0;
  if(stk_sel == STK_1) {
    for(i=arr_stk_two_size_s32(s, STK_1)-1; i>=0; i--) {
      printf("%d ", s->arr[i]);
    }
  } else if(stk_sel == STK_2) {
    for(i = s->top2; i < s->capacity; i++) {
      printf("%d ", s->arr[i]);
    }
  }
}

/*******************************************************************************
 PURPOSE:  To delete the array stack
 COMMENT:
*******************************************************************************/
void arr_stk_two_delete_s32(ARR_STK_TWO_S32_ *s)
{
  if(s) {
    if(s->arr){
      free(s->arr);
    }
    free(s);
  }
  return ;
}
/** @} */