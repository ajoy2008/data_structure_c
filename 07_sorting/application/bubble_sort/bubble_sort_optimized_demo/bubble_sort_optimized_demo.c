/***************************************************************************//**
 \addtogroup BUBBLE_SORT_OPTIMIZED_DEMO
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       bubble_sort_optimized_demo.c
 \details    Optimized bubble sort demonstration
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <bubble_sort.h>

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  int arr[] = {20, 10, 7, 25, 50, 30, 1, 17} ;
  unsigned int size = sizeof(arr)/sizeof(arr[0]);
  printf("Input Array :\n");
  print_array_int(arr, size);
  
  bubble_sort_optimized(arr, size);
  
  printf("Output Array after basic bubble sort :\n");
  print_array_int(arr, size);
  return 0 ;
}
