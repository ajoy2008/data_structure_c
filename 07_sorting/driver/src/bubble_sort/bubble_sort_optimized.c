/***************************************************************************//**
 \addtogroup BUBBLE_SORT_OPTIMIZED
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       bubble_sort_optimized.c
 \details    Optimized bubble sort Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<bubble_sort.h>

/*******************************************************************************
  PURPOSE:  Optimized bubble sort implementation (Method 1)
  COMMENT:
*******************************************************************************/
void bubble_sort_optimized(int *arr, unsigned int n)
{
  unsigned int k = 0, ptr = 0, done = 0;
  for(k=0; k<n-1; k++) {
    done = 1;
    for(ptr=0; ptr<n-k-1; ptr++) {
      if(arr[ptr] > arr[ptr+1]) {
        sort_swap(&arr[ptr], &arr[ptr+1]);
        done = 0;
      }
    }
    if(done) break;
  }
  return ;
}

#if 0
/*******************************************************************************
  PURPOSE:  Optimized bubble sort implementation (Method 2)
  COMMENT:
*******************************************************************************/
void bubble_sort_optimized(int *arr, unsigned int n)
{
  unsigned int k = 0, ptr = 0, done = 0;
  for(k=0; k<n-1 && !done; k++) {
    done = 1;
    for(ptr=0; ptr<n-k-1; ptr++) {
      if(arr[ptr] > arr[ptr+1]) {
        sort_swap(&arr[ptr], &arr[ptr+1]);
        done = 0;
      }
    }
  }
  return ;
}
#endif
/** @} */
