/***************************************************************************//**
 \defgroup   LIST_STK_GENERIC LIST STK GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       list_stk_generic.h
 \details    LIST STK GENERIC interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _LIST_STK_GENERIC_H_
#define _LIST_STK_GENERIC_H_  1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
**  Data Structure for STACK_NODE_S32_
*/
struct STACK_NODE_
{
  void *data               ;    ///< Data portion of the LIST_STACK_S32_ node
  struct STACK_NODE_ *link ;    ///< Pointer to the next LIST_STACK_S32_ node
};
typedef struct STACK_NODE_ LIST_STK_NODE_  ; ///< List stack node of S32 type

/**
 ** Data Structure for LIST_STK_S32_
 */
typedef struct
{
  LIST_STK_NODE_ *top ; ///< Pointer to the top node of the stack
  size_t el_size ;

}LIST_STK_ ;

typedef void (*print_callback_t)(void *);

/***************************************************************************//**
  \details  Create list stack of S32 type
  \return   Pointer to LIST_STK_S32_ structure
*******************************************************************************/
LIST_STK_* list_stk_create(
  size_t stk_size,            ///< [In] Stack size
  size_t el_size
  );

/***************************************************************************//**
  \details  To check the list stack is empty or not
  \return   1 --> EMPTY, 0 --> NOT-EMPTY
*******************************************************************************/
int  list_stk_is_empty(
  LIST_STK_ *s         ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To push an element into the list stack
  \return   None
*******************************************************************************/
void list_stk_push(
  LIST_STK_ *s,    ///< [In] Pointer to the stack
  void *data             ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the list stack
  \return   The recently popped element
*******************************************************************************/
void *  list_stk_pop(
  LIST_STK_ *s    ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the top element of the list stack without popping
  \return   The top element of the stack
*******************************************************************************/
void *  list_stk_top(
  LIST_STK_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To return the number of elements stored in the stack
  \return   The current size of the stack
*******************************************************************************/
int  list_stk_size(
  LIST_STK_ *s   ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To print the stack elements
  \return
*******************************************************************************/
void  list_stk_print(
  LIST_STK_ *s,   ///< [In] Pointer to the stack
  print_callback_t print
  );

/***************************************************************************//**
  \details  To delete the list stack
  \return   None
*******************************************************************************/
void list_stk_delete(
  LIST_STK_ *s                   ///< [In] Pointer to the stack
  );

/** @} */
#endif
