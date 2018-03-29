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
ARR_STK_* arr_stk_create(unsigned int stk_size, size_t el_size)
{
  ARR_STK_*s = (ARR_STK_ *)malloc(sizeof(ARR_STK_));
  if(s == NULL)
  return NULL ;
   
  s->capacity = stk_size * el_size ;
  s->top = -el_size ;
  s->arr = (void *)malloc(s->capacity * el_size);
  if(s->arr == NULL)
    return NULL ;
  else
    return (s);
}

/*******************************************************************************
 PURPOSE:  To check the generic array stack is empty or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_empty(ARR_STK_ *s, size_t el_size)
{
  return(s->top == -el_size);
}

/*******************************************************************************
 PURPOSE:  To check the generic array stack is full or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_full(ARR_STK_ *s, size_t el_size)
{
  return(s->top == s->capacity * el_size - 1);
}

/*******************************************************************************
 PURPOSE:  To push an element into generic array stack
 COMMENT:
*******************************************************************************/
void arr_stk_push(ARR_STK_ *s, void *data, size_t el_size)
{
  unsigned int i ;
  if(arr_stk_is_full(s, el_size))
  {
    printf("\nStack Overflow Error\n");
    exit(EXIT_FAILURE);
  }
  s->top = s->top + el_size ;
  for(i=0; i<el_size; i++)
  *(char *)(s->arr + s->top + i) = *((char *)(data + i)) ;
}
/*******************************************************************************
 PURPOSE:  To pop an element from the generic array stack
 COMMENT:
*******************************************************************************/
void* arr_stk_pop(ARR_STK_ *s, size_t el_size)
{
  char *p ;
  if(arr_stk_is_empty(s, el_size))
  {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  p = (char *)(s->arr + s->top);
  s->top = s->top - el_size ;
  return((void *)p);
}

/*******************************************************************************
 PURPOSE:  To return the top element from the generic array stack without popping
 COMMENT:
*******************************************************************************/
void* arr_stk_top(ARR_STK_ *s, size_t el_size)
{
  char *p ;
  if(arr_stk_is_empty(s, el_size))
  {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  p = (char *)(s->arr + s->top);
  return((void *)p);
}

/*******************************************************************************
 PURPOSE:  To return the top index of the stack
 COMMENT:
*******************************************************************************/
int arr_stk_top_index(ARR_STK_ *s, size_t el_size)
{
  return(s->top / (int)el_size);
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the generic array stack
 COMMENT:
*******************************************************************************/
int arr_stk_size(ARR_STK_ *s, size_t el_size)
{
  if(arr_stk_is_full(s, el_size))
  {
    return(s->capacity / (int)el_size);
  }
  else
  {
    return(1 + s->top/(int)el_size);
  }
}

/*******************************************************************************
 PURPOSE:  To delete the generic array stack
 COMMENT:
*******************************************************************************/
void arr_stk_delete(ARR_STK_ *s)
{
  if(s)
  {
    if(s->arr)
    {
      free(s->arr);
    }
    free(s);
  }
  return ;
}
/** @} */