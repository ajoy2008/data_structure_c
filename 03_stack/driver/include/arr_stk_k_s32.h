/***************************************************************************//**
 \defgroup   ARR_STK_K_S32 ARR STK K S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_k_s32.h
 \details    ARR STK K S32 interface specification
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _ARR_STK_K_S32_H_
#define _ARR_STK_K_S32_H_  1

#include <stdio.h>
#include <stdlib.h>

/**
**  Data Structure for ARR_STK_TWO_S32_
*/
typedef struct
{
  int *arr  ;  ///< Stack container
  int *top  ;  ///< Array of size k to store indexes of top elements of stacks
  int *next ;  ///< Array of size n to store next entry in all stacks
  int n, k  ;
  int fr  ;    ///< To store beginning index of free list

}ARR_STK_K_S32_;

/***************************************************************************//**
  \details  Create an array stack of S32 type
  \return   Pointer to ARR_STK_S32_ structure
*******************************************************************************/
ARR_STK_K_S32_* arr_stk_k_create_s32(
  unsigned int no_of_stacks, ///< [In] Number of stacks to be created
  unsigned int size          ///< [In] Size of underlying stack container array 
  );

/***************************************************************************//**
  \details  To check the array stack is empty or not
  \return   1 : EMPTY, 0 : NOT-EMPTY
*******************************************************************************/
int arr_stk_k_is_empty_s32(
  ARR_STK_K_S32_ *s,       ///< [In] Pointer to the stack
  unsigned int stk_sel
  );

/***************************************************************************//**
  \details  To check the array stack is full or not
  \return   1 : FULL, 0 : NOT-FULL
*******************************************************************************/
int arr_stk_two_is_full_s32(
  ARR_STK_K_S32_  *s      ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  To push an element into the stack
  \return   None
*******************************************************************************/
void arr_stk_k_push_s32(
  ARR_STK_K_S32_ *s,       ///< [In] Pointer to the stack
  unsigned int    stk_sel, ///< [In] Stack number
  int data                 ///< [In] Data to be pushed into the stack
  );

/***************************************************************************//**
  \details  To pop an element from the stack
  \return   The recently popped element
*******************************************************************************/
int arr_stk_k_pop_s32(
  ARR_STK_K_S32_ *s,       ///< [In] Pointer to the stack
  unsigned int    stk_sel  ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To return the top element of the stack without popping
  \return   The top element of the stack
*******************************************************************************/
int arr_stk_k_top_s32(
  ARR_STK_K_S32_ *s,       ///< [In] Pointer to the stack
  unsigned int    stk_sel  ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To find the current size of the stack
  \return   The current size of the stack
*******************************************************************************/
int arr_stk_k_size_s32(
  ARR_STK_K_S32_ *s,       ///< [In] Pointer to the stack
  unsigned int    stk_sel  ///< [In] Stack number
  );

/***************************************************************************//**
  \details  To print the stack elements
  \return
*******************************************************************************/
void  arr_stk_k_print_s32(
  ARR_STK_K_S32_ *s,   ///< [In] Pointer to the stack
  unsigned int stk_sel
  );

/***************************************************************************//**
  \details  To delete the stack
  \return   None
*******************************************************************************/
void  arr_stk_k_delete_s32(
  ARR_STK_K_S32_ *s       ///< [In] Pointer to the stack
  );

/***************************************************************************//**
  \details  Debug help print
  \return   None
*******************************************************************************/
void arr_stk_k_debug_print_s32(
  ARR_STK_K_S32_ *s       ///< [In] Pointer to the stack
  );
/** @} */
#endif
