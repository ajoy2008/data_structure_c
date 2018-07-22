/***************************************************************************//**
 \addtogroup PRINT_NGE_USING_STACK
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       print_nge_stack.c
 \details    Print next greater element using stack
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#define STK_MAX_SIZE 16

void printNGE(int *arr, size_t size)
{
  size_t i = 0;
  STK_S32_ *stk = stk_create_s32(STK_MAX_SIZE);
  stk_push_s32(stk, arr[0]);
  for (i = 1; i < size; i++) {
    while (!stk_is_empty_s32(stk) && arr[i] > stk_top_s32(stk)) {
        printf("%2d --> %2d\n", stk_pop_s32(stk), arr[i]);
    }
    stk_push_s32(stk, arr[i]);
  }
  while (!stk_is_empty_s32(stk)) {
    printf("%2d --> %2d\n", stk_pop_s32(stk), -1);
  }
}
/***************************************************************************//**
  \details  The main function starts from here

  \return   Zero
*******************************************************************************/
int main(void)
{
  int arr[] = {11, 13, 21, 3};
  size_t n = sizeof(arr) / sizeof(arr[0]);
  printNGE(arr, n);
  return 0;
}
