/***************************************************************************//**
 \defgroup   LIST_STK_U8 LIST STK U8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_u8.h
 \details    LIST STK U8 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _LIST_STK_U8_H_
#define _LIST_STK_U8_H_  1

#include<stdio.h>
#include<stdlib.h>

/**
**  Data Structure for STACK_NODE_U8_
*/
struct STACK_NODE_U8_
{
  char data                    ;  ///< Data portion of the LIST_STACK_U8_ node
  struct STACK_NODE_U8_ *link  ;  ///< Pointer to the next LIST_STACK_U8_ node
};
typedef struct STACK_NODE_U8_ LIST_STK_NODE_U8_  ; ///< List stack node of U8 type

/**
**  Data Structure for LIST_STK_U8_
*/
typedef struct
{
  LIST_STK_NODE_U8_ *top ; ///< Pointer to the top node of the stack

}LIST_STK_U8_ ;

/***************************************************************************//**
  \details  Create list stack of U8 type
  \return   Pointer to LIST_STK_U8_ structure
*******************************************************************************/
LIST_STK_U8_* list_stk_create_u8(
  unsigned int stk_size            ///< [In] Stack size
  );

/***************************************************************************//**
  \details  To check the list stack is empty or not
  \return   1 --> EMPTY, 0 --> NOT-EMPTY 
*******************************************************************************/
int  list_stk_is_empty_u8(
  LIST_STK_U8_ *s         ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To push an element into the list stack
  \return   None
*******************************************************************************/
void list_stk_push_u8(
  LIST_STK_U8_ *s,    ///< [In] Pointer to the stack
  char data             ///< [In] Data to be pushed into the stack 
  );

/***************************************************************************//**
  \details  To pop an element from the list stack
  \return   The recently popped element
*******************************************************************************/
char  list_stk_pop_u8(
  LIST_STK_U8_ *s    ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the top element of the list stack without popping
  \return   The top element of the stack
*******************************************************************************/
char  list_stk_top_u8(
  LIST_STK_U8_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To delete the list stack
  \return   None
*******************************************************************************/
void list_stk_delete_u8(
  LIST_STK_U8_ *s                   ///< [In] Pointer to the stack
  );

/** @} */
#endif
