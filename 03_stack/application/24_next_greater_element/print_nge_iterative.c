/***************************************************************************//**
 \addtogroup PRINT_NGE_ITERATIVE
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       print_nge_iterative.c
 \details    Print next greater element using iterative method
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
  size_t i, j;
  int next ;
  for (i=0; i<size; i++) {
    next = -1;
    for (j = i+1; j<size; j++) {
      if (arr[j] > arr[i]) {
        next = arr[j];
        break;
      }
    }
    printf("%2d --> %2d\n", arr[i], next);
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
