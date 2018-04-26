/***************************************************************************//**
 \defgroup   ARR_STK_TWO_S32 ARR STK TWO S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_two_s32.h
 \details    ARR STK TWO S32 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _ARR_STK_TWO_S32_H_
#define _ARR_STK_TWO_S32_H_  1

#include <stdio.h>
#include <stdlib.h>

/**
**  Data Structure for ARR_STK_TWO_S32_
*/
typedef struct
{
  int top1     ;  ///< Tracks the top element of the first stack
  int top2     ;  ///< Tracks the top element of the second stack
  int capacity ;  ///< Maximum capacity of the stack
  int *arr     ;  ///< Stack container

}ARR_STK_TWO_S32_;

typedef enum
{
	STK_1 = (1),
	STK_2 = (2)

}STK_SEL_ ;

/***************************************************************************//**
  \details  Create an array stack of S32 type
  \return   Pointer to ARR_STK_S32_ structure
*******************************************************************************/
ARR_STK_TWO_S32_* arr_stk_two_create_s32(
  unsigned int stk_size  ///< [In] Size of the stack
  );

/***************************************************************************//**
  \details  To check the array stack is empty or not
  \return   1 : EMPTY, 0 : NOT-EMPTY
*******************************************************************************/
int  arr_stk_two_is_empty_s32(
  ARR_STK_TWO_S32_ *s,       ///< [In] Pointer to the stack
  STK_SEL_ stk_sel
  );

/***************************************************************************//**
  \details  To check the array stack is full or not
  \return   1 : FULL, 0 : NOT-FULL
*******************************************************************************/
int  arr_stk_two_is_full_s32(
  ARR_STK_TWO_S32_  *s,      ///< [In] Pointer to the stack
  STK_SEL_ stk_sel
  );

/***************************************************************************//**
  \details  To push an element into the stack
  \return   None
*******************************************************************************/
void arr_stk_two_push_s32(
  ARR_STK_TWO_S32_ *s,  ///< [In] Pointer to the stack
  STK_SEL_ stk_sel,      ///< [In] Stack number
  int data              ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the stack
  \return   The recently popped element
*******************************************************************************/
int  arr_stk_two_pop_s32(
  ARR_STK_TWO_S32_ *s,       ///< [In] Pointer to the stack
  STK_SEL_ stk_sel           ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To return the top element of the stack without popping
  \return   The top element of the stack
*******************************************************************************/
int  arr_stk_two_top_s32(
  ARR_STK_TWO_S32_ *s,       ///< [In] Pointer to the stack
  STK_SEL_ stk_sel           ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To find the current size of the stack
  \return   The current size of the stack
*******************************************************************************/
int  arr_stk_two_size_s32(
  ARR_STK_TWO_S32_ *s,       ///< [In] Pointer to the stack
  STK_SEL_ stk_sel            ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To print the stack elements
  \return
*******************************************************************************/
void  arr_stk_two_print_s32(
  ARR_STK_TWO_S32_ *s,   ///< [In] Pointer to the stack
  STK_SEL_ stk_sel
  );

/***************************************************************************//**
  \details  To delete the stack
  \return   None
*******************************************************************************/
void  arr_stk_two_delete_s32(
  ARR_STK_TWO_S32_ *s       ///< [In] Pointer to the stack
  );

/** @} */
#endif
