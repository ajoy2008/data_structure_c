/***************************************************************************//**
 \defgroup   ARR_STK_GENERIC ARR STK GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_generic.h
 \details    ARR STK GENERIC interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _ARR_STK_GENERIC_H_
#define _ARR_STK_GENERIC_H_  1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
**  Data Structure for ARR_STK_
*/
typedef struct
{
  int top          ;       ///< Tracks the top element of the stack
  size_t capacity  ;       ///< Maximum capacity of the stack
  size_t el_size   ;       ///< Size of each element of the stack
  void *arr        ;       ///< Stack container

} ARR_STK_;

typedef void (*print_callback_t)(void *);

/***************************************************************************//**
  \details  Create an array stack gneric type
  \return   Pointer to generic ARR_STK_ structure
*******************************************************************************/
ARR_STK_* arr_stk_create(
  size_t stk_size, ///< [In] Generic array stack size
  size_t el_size   ///< [In] Size of each element of the stack
  ) ;

/***************************************************************************//**
  \details  To check the generic array stack is empty or not
  \return   1 : EMPTY, 0 : NOT-EMPTY 
*******************************************************************************/
int  arr_stk_is_empty( 
  ARR_STK_ *s          ///< [In] Pointer to the generic array stack structure
  );

/***************************************************************************//**
  \details  To check the array stack is full or not
  \return   1 : FULL, 0 : NOT-FULL
*******************************************************************************/
int  arr_stk_is_full( 
  ARR_STK_  *s         ///< [In] Pointer to the generic array stack structure
  );

/***************************************************************************//**
  \details  To push an element into the stack
  \return   None
*******************************************************************************/
void arr_stk_push( 
  ARR_STK_ *s,          ///< [In] Pointer to the generic array stack structure
  void *data            ///< [In] Pointer to the input data
  );

/***************************************************************************//**
  \details  To pop an element from the stack
  \return   The recently popped element
*******************************************************************************/
void*  arr_stk_pop( 
  ARR_STK_ *s          ///< [In] Pointer to the generic array stack structure
  );

/***************************************************************************//**
  \details  To return the top element of the stack without popping
  \return   The top element of the stack
*******************************************************************************/
void*  arr_stk_top( 
  ARR_STK_ *s          ///< [In] Pointer to the generic array stack structure
  );

/***************************************************************************//**
  \details  To find the size of the stack
  \return   The size of the stack
*******************************************************************************/
int  arr_stk_size( 
  ARR_STK_ *s          ///< [In] Pointer to the generic array stack structure
  );

/***************************************************************************//**
  \details  To find the size of the stack
  \return   The size of the stack
*******************************************************************************/
void arr_stk_print(
  ARR_STK_ *s,
  print_callback_t print
  );

/***************************************************************************//**
  \details  To delete the generic array stack
  \return   None
*******************************************************************************/
void arr_stk_delete( 
  ARR_STK_ *s       ///< [In] Pointer to the generic array stack structure
  );

/** @} */
#endif
