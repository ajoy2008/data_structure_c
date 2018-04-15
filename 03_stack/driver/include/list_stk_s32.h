/***************************************************************************//**
 \defgroup   LIST_STK_S32 LIST STK S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_s32.h
 \details    LIST STK S32 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _LIST_STK_S32_H_
#define _LIST_STK_S32_H_  1

#include<stdio.h>
#include<stdlib.h>

/**
**  Data Structure for STACK_NODE_S32_
*/
struct STACK_NODE_S32_
{
  int data                    ;    ///< Data portion of the LIST_STACK_S32_ node
  struct STACK_NODE_S32_ *link ;    ///< Pointer to the next LIST_STACK_S32_ node
};
typedef struct STACK_NODE_S32_ LIST_STK_NODE_S32_  ; ///< List stack node of S32 type

/**
 ** Data Structure for LIST_STK_S32_
 */
typedef struct
{
  LIST_STK_NODE_S32_ *top ; ///< Pointer to the top node of the stack

}LIST_STK_S32_ ;

/***************************************************************************//**
  \details  Create list stack of S32 type
  \return   Pointer to LIST_STK_S32_ structure
*******************************************************************************/
LIST_STK_S32_* list_stk_create_s32(
  unsigned int stk_size            ///< [In] Stack size
  );

/***************************************************************************//**
  \details  To check the list stack is empty or not
  \return   1 --> EMPTY, 0 --> NOT-EMPTY
*******************************************************************************/
int  list_stk_is_empty_s32(
  LIST_STK_S32_ *s         ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To push an element into the list stack
  \return   None
*******************************************************************************/
void list_stk_push_s32(
  LIST_STK_S32_ *s,    ///< [In] Pointer to the stack
  int data             ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the list stack
  \return   The recently popped element
*******************************************************************************/
int  list_stk_pop_s32(
  LIST_STK_S32_ *s    ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the top element of the list stack without popping
  \return   The top element of the stack
*******************************************************************************/
int  list_stk_top_s32(
  LIST_STK_S32_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the number of elements stored in the stack
  \return   The current size of the stack
*******************************************************************************/
int  list_stk_size_s32(
  LIST_STK_S32_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To print the stack elements
  \return
*******************************************************************************/
void  list_stk_print_s32(
  LIST_STK_S32_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To delete the list stack
  \return   None
*******************************************************************************/
void list_stk_delete_s32(
  LIST_STK_S32_ *s                   ///< [In] Pointer to the stack
  );

/** @} */
#endif
