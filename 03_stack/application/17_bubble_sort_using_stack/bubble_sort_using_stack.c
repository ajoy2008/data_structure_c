/***************************************************************************//**
 \addtogroup QUICK_SORT
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       bubble_sort_using_stack.c
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
  for(i=0; i<size; i++) {
    printf("%d  ",arr[i]);
  }
  printf("\n");
  return;
}

/*******************************************************************************
  PURPOSE:  Bubble sort using stack
  COMMENT:
*******************************************************************************/
void bubble_sort(int *arr, int size)
{
  int temp ;
  int i ;
  STK_S32_ *stk_1 = stk_create_s32(size);
  STK_S32_ *stk_2 = stk_create_s32(size);
  
  // Push all elements of array in 1st stack
  for(i=0; i<size; i++) {
    stk_push_s32(stk_1, arr[i]);
  }
  
  for (i=0; i<size; i++) {
    // alternatively
    if(i%2 == 0) {
      while (!stk_is_empty_s32(stk_1)) {
        if(!stk_is_empty_s32(stk_2) && stk_top_s32(stk_2) > stk_top_s32(stk_1)) {
		  temp = stk_pop_s32(stk_2) ;
		  stk_push_s32(stk_2, stk_pop_s32(stk_1));
		  stk_push_s32(stk_2, temp);
		} else {
		  stk_push_s32(stk_2, stk_pop_s32(stk_1));
		}
      }
	  // tricky step
      arr[size-i-1] = stk_pop_s32(stk_2);
    } else {
      while(!stk_is_empty_s32(stk_2)) {
        if(!stk_is_empty_s32(stk_1) && stk_top_s32(stk_1) > stk_top_s32(stk_2)) {
		  temp = stk_pop_s32(stk_1) ;
		  stk_push_s32(stk_1, stk_pop_s32(stk_2));
		  stk_push_s32(stk_1, temp);
		} else {
		  stk_push_s32(stk_1, stk_pop_s32(stk_2));
		}
      }
      // tricky step
      arr[size-i-1] = stk_pop_s32(stk_1);
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
  print_array(arr, MAX_SIZE);
  bubble_sort(arr, MAX_SIZE);
  printf("\nAfter bubble sort :\n");
  print_array(arr, MAX_SIZE);
  return 0;
}
