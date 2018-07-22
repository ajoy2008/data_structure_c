/***************************************************************************//**
 \addtogroup ARR_STK_GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_generic.c
 \details    Array Stack Generic Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <arr_stk_generic.h>

/*******************************************************************************
  PURPOSE:  To create a generic array stack
  COMMENT:
*******************************************************************************/
ARR_STK_* arr_stk_create(size_t stk_size, size_t el_size)
{
  ARR_STK_*s = (ARR_STK_ *)malloc(sizeof(ARR_STK_));
  if(s == NULL)
      return NULL ;
  s->top = -1 ;
  s->capacity = stk_size ;
  s->el_size = el_size ;
  s->arr = (void *)malloc(stk_size * el_size);
  if(s->arr == NULL)
    return NULL ;
  else
    return (s);
}

/*******************************************************************************
 PURPOSE:  To check the generic array stack is empty or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_empty(ARR_STK_ *s)
{
  return(s->top == -1);
}

/*******************************************************************************
 PURPOSE:  To check the generic array stack is full or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_full(ARR_STK_ *s)
{
  return(s->top == s->capacity - 1);
}

/*******************************************************************************
 PURPOSE:  To push an element into generic array stack
 COMMENT:
*******************************************************************************/
void arr_stk_push(ARR_STK_ *s, void *data)
{
  if(arr_stk_is_full(s)) {
    printf("\nStack Overflow Error\n");
    exit(EXIT_FAILURE);
  }
  s->top = s->top + 1 ;
  void* target = (char*)s->arr + (s->top * s->el_size);
  memcpy(target, data, s->el_size);
}
/*******************************************************************************
 PURPOSE:  To pop an element from the generic array stack
 COMMENT:
*******************************************************************************/
void* arr_stk_pop(ARR_STK_ *s)
{
  void *target =  (void *)malloc(s->el_size);
  if(arr_stk_is_empty(s)) {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  void* source = (char*)s->arr + (s->top * s->el_size);
  memcpy(target, source, s->el_size);
  s->top--;
  return(target);
}

/*******************************************************************************
 PURPOSE:  To return the top element from the generic array stack without popping
 COMMENT:
*******************************************************************************/
void* arr_stk_top(ARR_STK_ *s)
{
  void *target = (void *)malloc(s->el_size) ;
  if(arr_stk_is_empty(s))
  {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  void* source = (char*)s->arr + (s->top * s->el_size);
  memcpy(target, source, s->el_size);
  return(target);
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the generic array stack
 COMMENT:
*******************************************************************************/
int arr_stk_size(ARR_STK_ *s)
{
  if(arr_stk_is_full(s)) {
    return(s->capacity);
  } else {
    return(1 + s->top);
  }
}

/*******************************************************************************
 PURPOSE:  To print the list stack elements
 COMMENT:
*******************************************************************************/
void arr_stk_print(ARR_STK_ *s, print_callback_t print)
{
  int i = 0;
  void *target = (void *)malloc(s->el_size) ;
  for(i=arr_stk_size(s)-1; i>=0; i--) {
    void* source = (char*)s->arr + (i * s->el_size);
	memcpy(target, source, s->el_size);
    print(target);
  }
}

/*******************************************************************************
 PURPOSE:  To delete the generic array stack
 COMMENT:
*******************************************************************************/
void arr_stk_delete(ARR_STK_ *s)
{
  if(s) {
    if(s->arr) {
      free(s->arr);
    }
    free(s);
  }
  return ;
}
/** @} */
