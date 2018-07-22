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
#define stk_size        arr_stk_size
#define stk_print       arr_stk_print
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
#define stk_print_s32     arr_stk_print_s32
#define stk_delete_s32    arr_stk_delete_s32

#endif

#if defined(__ARR_STK_S8__)
#include <arr_stk_s8.h>

#define STK_S8_          ARR_STK_S8_
#define stk_create_s8    arr_stk_create_s8
#define stk_is_empty_s8  arr_stk_is_empty_s8
#define stk_is_full_s8   arr_stk_is_full_s8
#define stk_push_s8      arr_stk_push_s8
#define stk_pop_s8       arr_stk_pop_s8
#define stk_top_s8       arr_stk_top_s8
#define stk_size_s8      arr_stk_size_s8
#define stk_print_s8     arr_stk_print_s8
#define stk_delete_s8    arr_stk_delete_s8

#endif

#if defined(__ARR_STK_TWO_S32__)
#include <arr_stk_two_s32.h>

#define STK_TWO_S32_          ARR_STK_TWO_S32_
#define stk_two_create_s32    arr_stk_two_create_s32
#define stk_two_is_empty_s32  arr_stk_two_is_empty_s32
#define stk_two_is_full_s32   arr_stk_two_is_full_s32
#define stk_two_push_s32      arr_stk_two_push_s32
#define stk_two_pop_s32       arr_stk_two_pop_s32
#define stk_two_top_s32       arr_stk_two_top_s32
#define stk_two_size_s32      arr_stk_two_size_s32
#define stk_two_print_s32     arr_stk_two_print_s32
#define stk_two_delete_s32    arr_stk_two_delete_s32

#endif

#if defined(__ARR_STK_K_S32__)
#include <arr_stk_k_s32.h>

#define STK_K_S32_            ARR_STK_K_S32_
#define stk_k_create_s32      arr_stk_k_create_s32
#define stk_k_is_empty_s32    arr_stk_k_is_empty_s32
#define stk_k_is_full_s32     arr_stk_k_is_full_s32
#define stk_k_push_s32        arr_stk_k_push_s32
#define stk_k_pop_s32         arr_stk_k_pop_s32
#define stk_k_top_s32         arr_stk_k_top_s32
#define stk_k_size_s32        arr_stk_k_size_s32
#define stk_k_print_s32       arr_stk_k_print_s32
#define stk_k_delete_s32      arr_stk_k_delete_s32
#define stk_k_debug_print_s32 arr_stk_k_debug_print_s32

#endif

#if defined(__LIST_STK_GENERIC__)
#include <list_stk_generic.h>

#define STK_            LIST_STK_
#define stk_create      list_stk_create
#define stk_is_empty    list_stk_is_empty
#define stk_push        list_stk_push
#define stk_pop         list_stk_pop
#define stk_top         list_stk_top
#define stk_size        list_stk_size
#define stk_print       list_stk_print
#define stk_delete      list_stk_delete

#endif

#if defined(__LIST_STK_S32__)
#include <list_stk_s32.h>

#define STK_S32_         LIST_STK_S32_
#define stk_create_s32   list_stk_create_s32
#define stk_is_empty_s32 list_stk_is_empty_s32
#define stk_push_s32     list_stk_push_s32
#define stk_pop_s32      list_stk_pop_s32
#define stk_top_s32      list_stk_top_s32
#define stk_size_s32     list_stk_size_s32
#define stk_print_s32    list_stk_print_s32
#define stk_delete_s32   list_stk_delete_s32

#endif

#if defined(__LIST_STK_S8__)
#include <list_stk_s8.h>

#define STK_S8_          LIST_STK_S8_
#define stk_create_s8    list_stk_create_s8
#define stk_is_empty_s8  list_stk_is_empty_s8
#define stk_push_s8      list_stk_push_s8
#define stk_pop_s8       list_stk_pop_s8
#define stk_top_s8       list_stk_top_s8
#define stk_size_s8      list_stk_size_s8
#define stk_print_s8     list_stk_print_s8
#define stk_delete_s8    list_stk_delete_s8

#endif

/** @} */
#endif
