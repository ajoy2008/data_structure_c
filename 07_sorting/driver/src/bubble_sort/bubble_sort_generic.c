/***************************************************************************//**
 \addtogroup BUBBLE_SORT_GENERIC
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       bubble_sort_generic.c
 \details    Generic bubble sort implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<bubble_sort.h>

/*******************************************************************************
  PURPOSE:  Generic bubble sort implementation (Method 1)
  COMMENT:
*******************************************************************************/
void bubble_sort_generic(int *arr, unsigned int n, unsigned int el_size, arr_sort_cmp_callback_t compare)
{
  unsigned int i, k, ptr, done ;
  char temp ;
  done = 0 ;
  for(k=0; k<n-1 && !done; k++) {
    done = 1 ;
    for(ptr=0; ptr<n-k-1; ptr++) {
      if( compare((char *)(arr + ptr*el_size), (char *)(arr + ptr*el_size + el_size)) ) {
	    for(i=0; i<el_size; i++) {
	      temp = *((char *)(arr+ptr*el_size+i));
	      *((char *)(arr + ptr*el_size +i )) = *((char *)(arr+ ptr*el_size + el_size + i));
	      *((char *)(arr+ptr*el_size+el_size+i)) = temp ;
	    }
	    done = 0 ;
	  }
	}
  }
  return ;
}
/** @} */
