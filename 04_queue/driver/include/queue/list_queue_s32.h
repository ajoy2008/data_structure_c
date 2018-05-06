/***************************************************************************//**
  \defgroup   LST_QUEUE_S32 LST QUEUE S32
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       LstQueue_S32.h

  \details    LST QUEUE S32 interface specification

  \author     Ajoy Samanta

  \copyright  All Rights Reserved.
  \copyright  Ajoy, Inc.
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560103

*******************************************************************************/
#ifndef _LST_QUEUE_S32_H_
#define _LST_QUEUE_S32_H_  1

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_LEN 8

/**
**  Data Structure for QUEUE_NODE_S32_
*/
struct QUEUE_NODE_S32_
{
  int data                      ; /**< Data portion of the QUEUE_NODE_S32_ node */
  struct QUEUE_NODE_S32_ *link  ; /**< Pointer to the next QUEUE_NODE_S32_ node */
};
typedef struct QUEUE_NODE_S32_ LST_QUEUE_NODE_S32_ ; /**< LST_QUEUE_NODE_S32_ Node */

/**
**  Data Structure for LST_QUEUE_S32_
*/
typedef struct
{
  LST_QUEUE_NODE_S32_ *front ; /**< Pointer to the front node */
  LST_QUEUE_NODE_S32_ *rear  ; /**< Pointer to the rear node  */
  
}LST_QUEUE_S32_ ;

/***************************************************************************//**
  \details  Create list queue of integer (S32) type

  \return   Pointer to LST_QUEUE_S32_ structure
*******************************************************************************/
LST_QUEUE_S32_* LstQueueCreate_S32(void);

/***************************************************************************//**
  \details  To check the list queue is empty or not

  \return   1 --> EMPTY, 0 --> NOT-EMPTY 
*******************************************************************************/
int  LstQueueIsEmpty_S32(LST_QUEUE_S32_ *q);

/***************************************************************************//**
  \details  To insert an integer element into the list queue

  \return   None
*******************************************************************************/
void LstEnQueue_S32(LST_QUEUE_S32_ *q, int data);

/***************************************************************************//**
  \details  To pop an integer element from the list queue

  \return   The recently popped integer element
*******************************************************************************/
int LstDeQueue_S32(LST_QUEUE_S32_ *q);

/***************************************************************************//**
  \details  To return the front element of the list queue

  \return   The front element of the queue
*******************************************************************************/
int  LstQueueFront_S32(LST_QUEUE_S32_ *q);

/***************************************************************************//**
  \details  To return the rear element of the list queue

  \return   The rear element of the queue
*******************************************************************************/
int  LstQueueRear_S32(LST_QUEUE_S32_ *q);

/***************************************************************************//**
  \details  To find the current size of the queue

  \return   The size of the queue
*******************************************************************************/
int  LstQueueSize_S32( LST_QUEUE_S32_ *q )   ;

/***************************************************************************//**
  \details  To display the array queue

  \return   None
*******************************************************************************/
void  LstQueueDisplay_S32( LST_QUEUE_S32_ *q )   ;

/***************************************************************************//**
  \details  To delete the list queue ( S32 type)

  \return   None
*******************************************************************************/
void LstQueueDelete_S32(LST_QUEUE_S32_ *q);

/** @} */
#endif
