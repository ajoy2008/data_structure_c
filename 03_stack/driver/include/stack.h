/***************************************************************************//**
  \defgroup   STACK STACK
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       stack.h
  \details    stack abstraction layer
  \author     Ajoy Samanta
  \copyright  All Rights Reserved.
  \copyright  Ajoy, Inc.
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _STACK_H_
#define _STACK_H_  1

#if defined(__ARR_STK_GENERIC__)
#include <arr_stk_generic.h>

#define STK_            ARR_STK_
#define stk_create      arr_stk_create
#define stk_is_empty    arr_stk_is_empty
#define stk_is_full     arr_stk_is_full
#define stk_push        arr_stk_push
#define stk_pop         arr_stk_pop
#define stk_top         arr_stk_top
#define stk_top_index   arr_stk_top_index
#define stk_size        arr_stk_size
#define stk_delete      arr_stk_delete

#endif

#if defined(__ARR_STK_S32__)
#include <arr_stk_s32.h>

#define STK_S32_          ARR_STK_S32_
#define stk_create_s32    arr_stk_create_s32
#define stk_is_empty_s32  arr_stk_is_empty_s32
#define stk_is_full_s32   arr_stk_is_full_s32
#define stk_push_s32      arr_stk_push_s32
#define stk_pop_s32       arr_stk_pop_s32
#define stk_top_s32       arr_stk_top_s32
#define stk_size_s32      arr_stk_size_s32
#define stk_delete_s32    arr_stk_delete_s32

#endif

#if defined(__ARR_STK_U8__)
#include <arr_stk_u8.h>

#define STK_U8_          ARR_STK_U8_
#define stk_create_u8    arr_stk_create_u8
#define stk_is_empty_u8  arr_stk_is_empty_u8
#define stk_is_full_u8   arr_stk_is_full_u8
#define stk_push_u8      arr_stk_push_u8
#define stk_pop_u8       arr_stk_pop_u8
#define stk_top_u8       arr_stk_top_u8
#define stk_size_u8      arr_stk_size_u8
#define stk_delete_u8    arr_stk_delete_u8

#endif

#if defined(__LIST_STK_S32__)
#include <list_stk_s32.h>

#define STK_S32_         LIST_STK_S32_
#define stk_create_s32   list_stk_create_s32
#define stk_is_empty_s32 list_stk_is_empty_s32
#define stk_push_s32     list_stk_push_s32
#define stk_pop_s32      list_stk_pop_s32
#define stk_top_s32      list_stk_top_s32
#define stk_delete_s32   list_stk_delete_s32

#endif

#if defined(__LIST_STK_U8__)
#include <list_stk_u8.h>

#define STK_U8_          LIST_STK_U8_
#define stk_create_u8    list_stk_create_u8
#define stk_is_empty_u8  list_stk_is_empty_u8
#define stk_push_u8      list_stk_push_u8
#define stk_pop_u8       list_stk_pop_u8
#define stk_top_u8       list_stk_top_u8
#define stk_delete_u8    list_stk_delete_u8

#endif

/** @} */
#endif
