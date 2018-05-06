/***************************************************************************//**
  \defgroup   STACK STACK
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       stack.h
  \details    stack abstraction layer
  \author     Ajoy Samanta
  \copyright  All Rights Reserved.
  \copyright  Ajoy
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_  1

#if defined(__ARR_QUEUE_S32__)
#include <arr_queue_s32.h>

#define QUEUE_S32_          ARR_QUEUE_S32_
#define queue_create_s32    arr_queue_create_s32
#define queue_is_empty_s32  arr_queue_is_empty_s32
#define queue_is_full_s32   arr_queue_is_full_s32
#define queue_push_s32      arr_queue_push_s32
#define queue_pop_s32       arr_queue_pop_s32
#define queue_front_s32     arr_queue_front_s32
#define queue_rear_s32      arr_queue_rear_s32
#define queue_print_s32     arr_queue_print_s32
#define queue_delete_s32    arr_queue_delete_s32

#endif

/** @} */
#endif
