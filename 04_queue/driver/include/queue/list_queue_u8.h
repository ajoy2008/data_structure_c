/***************************************************************************//**
  \defgroup   LST_QUEUE_U8 LST QUEUE U8
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       LstQueue_U8.h

  \details    LST QUEUE U8 interface specification

  \author     Ajoy Samanta

  \copyright  All Rights Reserved.
  \copyright  Ajoy, Inc.
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560103

*******************************************************************************/
#ifndef _LST_QUEUE_U8_H_
#define _LST_QUEUE_U8_H_  1

#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_LEN 8

/**
**  Data Structure for QUEUE_NODE_U8_
*/
struct QUEUE_NODE_U8_
{
  char data                    ; /**< Data portion of the QUEUE_NODE_U8_ node */
  struct QUEUE_NODE_U8_ *link  ; /**< Pointer to the next QUEUE_NODE_U8_ node */
};
typedef struct QUEUE_NODE_U8_ LST_QUEUE_NODE_U8_ ; /**< LST_QUEUE_NODE_U8_ Node */

/**
**  Data Structure for LST_QUEUE_U8_
*/
typedef struct
{
  LST_QUEUE_NODE_U8_ *front ; /**< Pointer to the front node */
  LST_QUEUE_NODE_U8_ *rear  ; /**< Pointer to the rear node  */
  
}LST_QUEUE_U8_ ;

/***************************************************************************//**
  \details  Create list queue of character (U8) type

  \return   Pointer to LST_QUEUE_U8_ structure
*******************************************************************************/
LST_QUEUE_U8_* LstQueueCreate_U8(void);

/***************************************************************************//**
  \details  To check the list queue is empty or not

  \return   1 --> EMPTY, 0 --> NOT-EMPTY 
*******************************************************************************/
int  LstQueueIsEmpty_U8(LST_QUEUE_U8_ *q);

/***************************************************************************//**
  \details  To insert an character element into the list queue

  \return   None
*******************************************************************************/
void LstEnQueue_U8(LST_QUEUE_U8_ *q, char data);

/***************************************************************************//**
  \details  To pop an character element from the list queue

  \return   The recently popped character element
*******************************************************************************/
char  LstDeQueue_U8(LST_QUEUE_U8_ *q);

/***************************************************************************//**
  \details  To return the front element of the list queue

  \return   The front element of the queue
*******************************************************************************/
char  LstQueueFront_U8(LST_QUEUE_U8_ *q);

/***************************************************************************//**
  \details  To return the rear element of the list queue

  \return   The rear element of the queue
*******************************************************************************/
char  LstQueueRear_U8(LST_QUEUE_U8_ *q);

/***************************************************************************//**
  \details  To find the current size of the queue

  \return   The current size of the queue
*******************************************************************************/
int  LstQueueSize_U8( LST_QUEUE_U8_ *q )   ;

/***************************************************************************//**
  \details  To display the list queue

  \return   None
*******************************************************************************/
void  LstQueueDisplay_U8( LST_QUEUE_U8_ *q )   ;

/***************************************************************************//**
  \details  To delete the list queue (U8 type)

  \return   None
*******************************************************************************/
void LstQueueDelete_U8(LST_QUEUE_U8_ *q);

/** @} */
#endif
