/***************************************************************************//**
  \defgroup   ARR_QUEUE_S32 ARR QUEUE S32
  @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_queue_s32.h
 \details    ARR QUEUE S32 interface specification.
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _ARR_QUEUE_S32_H_
#define _ARR_QUEUE_S32_H_  1

#include<stdio.h>
#include<stdlib.h>

/**
**  Data Structure for ARR_QUEUE_S32_
*/
typedef struct {
  int front    ; /**< Tracks ( Pointer to) the front element of the queue  */
  int rear     ; /**< Tracks ( Pointer to) the rear element of the queue   */
  int capacity ; /**< Maximum capacity of the queue */
  int size     ; /**< Current size of the queue */
  int *arr     ; /**< Queue container */

} ARR_QUEUE_S32_;

/***************************************************************************//**
  \details  Create an array queue of integer (S32) type
  \return   Pointer to ARR_QUEUE_S32_ structure
*******************************************************************************/
ARR_QUEUE_S32_* arr_queue_create_s32( 
  unsigned int  queue_size
  );

/***************************************************************************//**
  \details  To check the array queue is empty or not
  \return   1 : EMPTY, 0 : NOT-EMPTY 
*******************************************************************************/
int  arr_queue_is_empty_s32( 
  ARR_QUEUE_S32_ *q 
  );

/***************************************************************************//**
  \details  To check the array queue is full or not
  \return   1 : FULL, 0 : NOT-FULL
*******************************************************************************/
int arr_queue_is_full_s32( 
  ARR_QUEUE_S32_  *q 
  );

/***************************************************************************//**
  \details  To insert an integer element into queue
  \return   None
*******************************************************************************/
void arr_queue_push_s32( 
  ARR_QUEUE_S32_ *q, 
  int data 
  );

/***************************************************************************//**
  \details  To delete an element from the queue
  \return   The recently deleted element
*******************************************************************************/
int arr_queue_pop_s32( 
  ARR_QUEUE_S32_ *q 
  );

/***************************************************************************//**
  \details  To return the front element of the queue
  \return   The front element of the queue
*******************************************************************************/
int arr_queue_front_s32(
  ARR_QUEUE_S32_ *q
  );

/***************************************************************************//**
  \details  To return the rear element of the queue
  \return   The rear element of the queue
*******************************************************************************/
int arr_queue_rear_s32(
  ARR_QUEUE_S32_ *q
  );

/***************************************************************************//**
  \details  To find the current size of the queue
  \return   The current size of the queue
*******************************************************************************/
int arr_queue_size_s32( 
  ARR_QUEUE_S32_ *q 
  );

/***************************************************************************//**
  \details  To display the array queue
  \return   none
*******************************************************************************/
void arr_queue_print_s32(
  ARR_QUEUE_S32_ *q 
  );

/***************************************************************************//**
  \details  To delete the integer queue
  \return   None
*******************************************************************************/
void arr_queue_delete_s32(
  ARR_QUEUE_S32_ *q 
  );

/** @} */
#endif
