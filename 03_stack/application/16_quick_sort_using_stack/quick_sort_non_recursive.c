/***************************************************************************//**
 \addtogroup QUICK_SORT
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       quick_sort_non_recursive.c
 \details    Array sorting using non recursive quick sort method
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<stdio.h>
#include<stack.h>

#define MAX_SIZE 10

/*******************************************************************************
  PURPOSE:  Print an array
  COMMENT:
*******************************************************************************/
void print_array(int *arr, int size)
{
  unsigned int i;
  for(i=0; i<=size; i++) {
    printf("%d  ",arr[i]);
  }
  printf("\n");
  return;
}

/*******************************************************************************
  PURPOSE:  Swap the two elements (Call by address mechanism)
  COMMENT:
*******************************************************************************/
void swap(int *x, int *y)
{
  int temp ;
  temp = *x ;
  *x   = *y ;
  *y   = temp;
}

/*******************************************************************************
  PURPOSE:  To partition the list based on pivot element
  COMMENT:
*******************************************************************************/
int partition(int *arr, int low, int high)
{
  int pivot = arr[low];
  int l, h ;
  l = low+1 ;
  h = high ;
  while(h>=l){
    while(pivot > arr[l]){
      l++ ;
    }
    while(pivot < arr[h]){
      h-- ;
    }
    if(h > l) {
      swap(&arr[l], &arr[h]);
    }
  }
  swap(&arr[low], &arr[h]);
  return h ;
}

/*******************************************************************************
  PURPOSE:  Non-Recursive quick sort
  COMMENT:
*******************************************************************************/
void quick_sort_nr(int *arr, int low, int high)
{
  int mid ;
  STK_S32_ *stk = stk_create_s32(high-low+1);
  stk_push_s32(stk, low);
  stk_push_s32(stk, high);

  while(!stk_is_empty_s32(stk))
  {
    high = stk_pop_s32(stk) ;
    low  = stk_pop_s32(stk) ;
    mid  = partition(arr, low, high);
    if( low < mid-1) {
      stk_push_s32(stk, low);
      stk_push_s32(stk, mid - 1) ;
    }
    if( high > mid+1) {
      stk_push_s32(stk, mid+1);
      stk_push_s32(stk, high) ;
    }
  }
}
/*******************************************************************************
  PURPOSE:  Quick sort main routine
  COMMENT:
*******************************************************************************/
int main(void)
{
  int arr[MAX_SIZE] = {11,2,9,13,57,25,17,1,90,3};
  printf("\nArray contents are in below :\n");
  print_array(arr, MAX_SIZE-1);
  quick_sort_nr(arr, 0, MAX_SIZE-1);
  printf("\nAfter quick sort :\n");
  print_array(arr, MAX_SIZE-1);
  return 0;
}
