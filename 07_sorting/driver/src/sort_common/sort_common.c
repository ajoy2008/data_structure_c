/***************************************************************************//**
 \addtogroup SORT_OOMMON
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       sort_common.c
 \details    Basic bubble sort Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<sort_common.h>

/*******************************************************************************
  PURPOSE:  To create an S32 array queue
  COMMENT:
*******************************************************************************/
void sort_swap(int *x, int *y)
{
  int temp = 0;
  temp = *x ;
  *x = *y;
  *y = temp;
  return ;
}

/*******************************************************************************
  PURPOSE:  To print an integer array
  COMMENT:
*******************************************************************************/
void print_array_int(int* arr, unsigned int n)
{
  unsigned int i;
  for(i=0; i<n; i++) {
    printf("%d	",arr[i]);
  }
  printf("\n");
  return;
}

/*******************************************************************************
  PURPOSE:  To print an integer array
  COMMENT:
*******************************************************************************/
void print_array_generic(int* arr, unsigned int n, unsigned int el_size, print_arr_callback_t print)
{
  unsigned int i ;
  printf("\n");
  for(i=0; i<n; i++) {
    print((char*)(arr+i*el_size));
  }
  printf("\n");
}

/** @} */
