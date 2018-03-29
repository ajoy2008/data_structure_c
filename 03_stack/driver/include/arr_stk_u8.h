/***************************************************************************//**
 \defgroup   ARR_STK_U8 ARR STK U8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_u8.h
 \details    ARR STK U8 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _ARR_STK_U8_H_
#define _ARR_STK_U8_H_  1

#include<stdio.h>
#include<stdlib.h>

/**
**  Data Structure for ARR_STK_U8_
*/
typedef struct
{
  int top      ;  ///< Tracks the top element of the stack
  int capacity ;  ///< Maximum capacity of the stack
  char *arr    ;  ///< Stack container

}ARR_STK_U8_;

/***************************************************************************//**
  \details  Create an array stack of U8 type
  \return   Pointer to ARR_STK_U8_ structure
*******************************************************************************/
ARR_STK_U8_* arr_stk_create_u8(
  unsigned int stk_size  ///< [In] Size of the stack
  );

/***************************************************************************//**
  \details  To check the array stack is empty or not
  \return   1 : EMPTY, 0 : NOT-EMPTY
*******************************************************************************/
int  arr_stk_is_empty_u8(
  ARR_STK_U8_ *s       ///< [In] Pointer to the S32 stack
  );

/***************************************************************************//**
  \details  To check the array stack is full or not
  \return   1 : FULL, 0 : NOT-FULL
*******************************************************************************/
int  arr_stk_is_full_u8(
  ARR_STK_U8_  *s      ///< [In] Pointer to the S32 stack
  );

/***************************************************************************//**
  \details  To push an element into the stack
  \return   None
*******************************************************************************/
void arr_stk_push_u8(
  ARR_STK_U8_ *s,      ///< [In] Pointer to the S32 stack
  char data              ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the stack
  \return   The recently popped element
*******************************************************************************/
char  arr_stk_pop_u8(
  ARR_STK_U8_ *s       ///< [In] Pointer to the input stack
  );

/***************************************************************************//**
  \details  To return the top element of the stack without popping
  \return   The top element of the stack
*******************************************************************************/
char  arr_stk_top_u8(
  ARR_STK_U8_ *s       ///< [In] Pointer to the input stack
  );

/***************************************************************************//**
  \details  To find the size of the stack
  \return   The size of the stack
*******************************************************************************/
int  arr_stk_size_u8(
  ARR_STK_U8_ *s       ///< [In] Pointer to the input stack
  );

/***************************************************************************//**
  \details  To delete the stack
  \return   None
*******************************************************************************/
void  arr_stk_delete_u8(
  ARR_STK_U8_ *s       ///< [In] Pointer to the input stack
  );

/** @} */
#endif
