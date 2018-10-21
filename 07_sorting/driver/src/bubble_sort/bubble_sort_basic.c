/***************************************************************************//**
 \addtogroup BUBBLE_SORT_BASIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       bubble_sort_basic.c
 \details    Basic bubble sort Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<bubble_sort.h>

/*******************************************************************************
  PURPOSE:  Basic inplace bubble sort implementation
  COMMENT:
*******************************************************************************/
void bubble_sort_basic(int *arr, unsigned int n)
{
  unsigned int k = 0, ptr = 0;
  for(k=0; k<n-1; k++) {
    for(ptr=0; ptr<n-k-1; ptr++) {
      if(arr[ptr] > arr[ptr+1]) {
        sort_swap(&arr[ptr], &arr[ptr+1]);
      }
    }
  }
  return ;
}
/** @} */