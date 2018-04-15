/***************************************************************************//**
 \defgroup   LIST_STK_S8 LIST STK S8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_s8.h
 \details    LIST STK S8 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _LIST_STK_S8_H_
#define _LIST_STK_S8_H_  1

#include<stdio.h>
#include<stdlib.h>

/**
**  Data Structure for STACK_NODE_S8_
*/
struct STACK_NODE_S8_
{
  char data                    ;  ///< Data portion of the LIST_STACK_S8_ node
  struct STACK_NODE_S8_ *link  ;  ///< Pointer to the next LIST_STACK_S8_ node
};
typedef struct STACK_NODE_S8_ LIST_STK_NODE_S8_  ; ///< List stack node of S8 type

/**
**  Data Structure for LIST_STK_S8_
*/
typedef struct
{
  LIST_STK_NODE_S8_ *top ; ///< Pointer to the top node of the stack

}LIST_STK_S8_ ;

/***************************************************************************//**
  \details  Create list stack of S8 type
  \return   Pointer to LIST_STK_S8_ structure
*******************************************************************************/
LIST_STK_S8_* list_stk_create_s8(
  unsigned int stk_size            ///< [In] Stack size
  );

/***************************************************************************//**
  \details  To check the list stack is empty or not
  \return   1 --> EMPTY, 0 --> NOT-EMPTY
*******************************************************************************/
int  list_stk_is_empty_s8(
  LIST_STK_S8_ *s         ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To push an element into the stack
  \return   None
*******************************************************************************/
void list_stk_push_s8(
  LIST_STK_S8_ *s,    ///< [In] Pointer to the stack
  char data           ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the stack
  \return   The recently popped element
*******************************************************************************/
char  list_stk_pop_s8(
  LIST_STK_S8_ *s    ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the top element of the stack without popping
  \return   The top element of the stack
*******************************************************************************/
char  list_stk_top_s8(
  LIST_STK_S8_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To find the size of the stack
  \return   The current size of the stack
*******************************************************************************/
int  list_stk_size_s8(
  LIST_STK_S8_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To print the stack elements
  \return
*******************************************************************************/
void  list_stk_print_s8(
  LIST_STK_S8_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To delete the list stack
  \return   None
*******************************************************************************/
void list_stk_delete_s8(
  LIST_STK_S8_ *s                   ///< [In] Pointer to the stack
  );

/** @} */
#endif
