/***************************************************************************//**
  \defgroup   ARR_CIRCULAR_QUEUE_U8 ARR CIRCULAR QUEUE S32
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       ArrCirQueue_U8.h

  \details    ARR CIRCULAR QUEUE S32 interface specification.

  \author     Ajoy Samanta

  \copyright  All Rights Reserved.
  \copyright  Ajoy, Inc.
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560103

*******************************************************************************/
#ifndef _ARR_CIRQUEUE_U8_H_
#define _ARR_CIRQUEUE_U8_H_  1

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_LEN 8

/**
**  Data Structure for ARR_QUEUE_U8_
*/
typedef struct
{
  int front    ; /**< Tracks ( Pointer to) the front element of the queue  */
  int rear     ; /**< Tracks ( Pointer to) the rear element of the queue   */
  int capacity ; /**< Maximum capacity of the queue */
  int size     ; /**< Current size of the queue */
  char *arr    ; /**< Queue container */

}ARR_CIRQUEUE_U8_;

/***************************************************************************//**
  \details  Create an array queue of character (U8) type

  \return   Pointer to ARR_QUEUE_U8_ structure
*******************************************************************************/
ARR_CIRQUEUE_U8_* ArrCirQueueCreate_U8( void ) ;

/***************************************************************************//**
  \details  To check the array queue is empty or not

  \return   1 --> EMPTY, 0 --> NOT-EMPTY 
*******************************************************************************/
int  ArrCirQueueIsEmpty_U8( ARR_CIRQUEUE_U8_ *q )         ;

/***************************************************************************//**
  \details  To check the array queue is full or not

  \return   1 --> FULL, 0 --> NOT-FULL
*******************************************************************************/
int  ArrCirQueueIsFull_U8( ARR_CIRQUEUE_U8_  *q )         ;

/***************************************************************************//**
  \details  To insert an character element into queue

  \return   None
*******************************************************************************/
void ArrCirEnQueue_U8( ARR_CIRQUEUE_U8_ *q, char data )  ;

/***************************************************************************//**
  \details  To delete an element from the queue

  \return   The recently dequeued character element
*******************************************************************************/
char  ArrCirDeQueue_U8( ARR_CIRQUEUE_U8_ *q )             ;

/***************************************************************************//**
  \details  To return the front element of the array queue

  \return   The front element of the queue
*******************************************************************************/
char  ArrCirQueueFront_U8(ARR_CIRQUEUE_U8_ *q);

/***************************************************************************//**
  \details  To return the rear element of the array queue

  \return   The rear element of the queue
*******************************************************************************/
char  ArrCirQueueRear_U8(ARR_CIRQUEUE_U8_ *q);

/***************************************************************************//**
  \details  To find the current size of the queue

  \return   The size of the queue
*******************************************************************************/
int  ArrCirQueueSize_U8( ARR_CIRQUEUE_U8_ *q )   ;

/***************************************************************************//**
  \details  To display the array queue

  \return   The size of the queue
*******************************************************************************/
void  ArrCirQueueDisplay_U8( ARR_CIRQUEUE_U8_ *q )   ;

/***************************************************************************//**
  \details  To delete the character queue

  \return   None
*******************************************************************************/
void ArrCirQueueDelete_U8( ARR_CIRQUEUE_U8_ *q )          ;

/** @} */
#endif
