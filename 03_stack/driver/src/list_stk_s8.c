/***************************************************************************//**
 \addtogroup LST_STK_S8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_s8.c
 \details    List Stack S8 API Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <list_stk_s8.h>
/*******************************************************************************
 PURPOSE: To create a list stack
 COMMENT: Create an empty list
*******************************************************************************/
LIST_STK_S8_* list_stk_create_s8(unsigned int stk_size)
{
  LIST_STK_S8_ *s = (LIST_STK_S8_ *)malloc(sizeof(LIST_STK_S8_)) ;
  (void)stk_size ;
  if(s != NULL) {
    s->top = NULL ;
  }
  return(s) ;
}

/*******************************************************************************
 PURPOSE:  To check the list stack is empty or not
 COMMENT:
*******************************************************************************/
int list_stk_is_empty_s8(LIST_STK_S8_ *s)
{
  return(s->top == NULL);
}

/*******************************************************************************
 PURPOSE:  To push an element into list stack
 COMMENT:  Same as adding a node beginning of the list
*******************************************************************************/
void list_stk_push_s8(LIST_STK_S8_ *s, char data)
{
  LIST_STK_NODE_S8_ *temp = (LIST_STK_NODE_S8_ *)malloc(sizeof(LIST_STK_NODE_S8_));
  if(temp != NULL) {
    temp->data = data ;
    temp->link = s->top ;
    s->top = temp;
  }
  return ;
}

/*******************************************************************************
 PURPOSE:  To pop an element from the list stack
 COMMENT:  Same as removing a node from beginning of the list
*******************************************************************************/
char list_stk_pop_s8(LIST_STK_S8_ *s)
{
  LIST_STK_NODE_S8_ *temp ;
  int data ;
  if(list_stk_is_empty_s8(s)) {
    printf("\nStack Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  temp = s->top ;
  s->top = s->top->link ;
  data = temp->data ;
  free(temp);
  return(data);
}

/*******************************************************************************
 PURPOSE:  To return the top element from the list stack without popping
 COMMENT:
*******************************************************************************/
char list_stk_top_s8(LIST_STK_S8_ *s)
{
  if(list_stk_is_empty_s8(s)) {
    printf("\nStack underflow error\n");
    exit(EXIT_FAILURE);
  }
  return(s->top->data);
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the stack
 COMMENT:
*******************************************************************************/
int list_stk_size_s8(LIST_STK_S8_ *s)
{
  LIST_STK_NODE_S8_ *temp = s->top ;
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
void list_stk_print_s8(LIST_STK_S8_ *s)
{
  LIST_STK_NODE_S8_ *temp = s->top ;
  while(temp != NULL) {
    printf("%c  ", temp->data);
    temp = temp->link;
  }
}

/*******************************************************************************
 PURPOSE:  To delete the list stack
 COMMENT:
*******************************************************************************/
void list_stk_delete_s8(LIST_STK_S8_ *s)
{
  LIST_STK_NODE_S8_ *temp ;
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