/***************************************************************************//**
 \addtogroup LIST_STK_GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_generic.c
 \details    List Stack Generic API Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <list_stk_generic.h>
/*******************************************************************************
 PURPOSE: To create a list stack
 COMMENT: Create an empty list
*******************************************************************************/
LIST_STK_* list_stk_create(size_t stk_size, size_t el_size)
{
  LIST_STK_ *s = (LIST_STK_ *)malloc(sizeof(LIST_STK_)) ;
  (void)stk_size ;
  s->el_size = el_size ;
  if(s != NULL) {
    s->top = NULL ;
  }
  return(s) ;
}

/*******************************************************************************
 PURPOSE:  To check the list stack is empty or not
 COMMENT:
*******************************************************************************/
int list_stk_is_empty(LIST_STK_ *s)
{
  return(s->top == NULL);
}

/*******************************************************************************
 PURPOSE:  To push an element into list stack
 COMMENT:  Same as adding a node beginning of the list
*******************************************************************************/
void list_stk_push(LIST_STK_ *s, void *data)
{
  LIST_STK_NODE_ *temp = (LIST_STK_NODE_ *)malloc(sizeof(LIST_STK_NODE_));
  temp->data = (void *)malloc(s->el_size);
  if(temp != NULL) {
    memcpy(temp->data, data, s->el_size);
    temp->link = s->top ;
    s->top = temp;
  }
  return ;
}

/*******************************************************************************
 PURPOSE:  To pop an element from the list stack
 COMMENT:  Same as removing a node from beginning of the list
*******************************************************************************/
void* list_stk_pop(LIST_STK_ *s)
{
  LIST_STK_NODE_ *temp ;
  void *data = (void *)malloc(s->el_size) ;
  if(list_stk_is_empty(s)) {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  temp = s->top ;
  s->top = s->top->link ;
  memcpy(data, temp->data, s->el_size);
  free(temp);
  return(data);
}

/*******************************************************************************
 PURPOSE:  To return the top element from the list stack without popping
 COMMENT:
*******************************************************************************/
void* list_stk_top(LIST_STK_ *s)
{
  void *data = (void *)malloc(s->el_size) ;
  if(list_stk_is_empty(s)) {
    printf("\nStack underflow error\n");
    exit(EXIT_FAILURE);
  }
  memcpy(data, s->top->data, s->el_size);
  return(data);
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the stack
 COMMENT:
*******************************************************************************/
int list_stk_size(LIST_STK_ *s)
{
  LIST_STK_NODE_ *temp = s->top ;
  int size = 0;
  while(temp != NULL) {
    size++;
    temp = temp->link;
  }
  return(size);
}

/*******************************************************************************
 PURPOSE:  To print the list stack elements
 COMMENT:
*******************************************************************************/
void list_stk_print(LIST_STK_ *s, print_callback_t print)
{
  LIST_STK_NODE_ *temp = s->top ;
  while(temp != NULL) {
    print(temp->data);
    temp = temp->link;
  }
}

/*******************************************************************************
 PURPOSE:  To delete the list stack
 COMMENT:
*******************************************************************************/
void list_stk_delete(LIST_STK_ *s)
{
  LIST_STK_NODE_ *temp ;
  if(s != NULL){
    while(s->top != NULL) {
      temp = s->top ;
      s->top = s->top->link ;
      free(temp);
    }
    s->top = NULL ;
    free(s);
  }
  return ;
}
/** @} */
