/***************************************************************************//**
  \defgroup   BUBBLE SORT
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       bubble_sort.h
  \details    Bubble sort API implementation
  \author     Ajoy Samanta
  \copyright  All Rights Reserved.
  \copyright  Ajoy
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_  1

#include <sort_common.h>

typedef int (*arr_sort_cmp_callback_t)(const void *, const void *);

/***************************************************************************//**
  \details  Basic inplace implementation of bubble sort in an integer array
  \return   NA
*******************************************************************************/
void bubble_sort_basic(
  int *arr,               ///< [In] Input array which needs to be sorted
  unsigned int n          ///< [In] Size of the array
  );

/***************************************************************************//**
  \details  Optimized version of bubble sort
  \return   NA
*******************************************************************************/
void bubble_sort_optimized(
  int *arr,               ///< [In] Input array which needs to be sorted
  unsigned int n          ///< [In] Size of the array
  );

/***************************************************************************//**
  \details  Generic version of bubble sort
  \return   NA
*******************************************************************************/
void bubble_sort_generic(
    int *arr,
	unsigned int n,
	unsigned int el_size,
	arr_sort_cmp_callback_t compare
	);
/** @} */
#endif // _BUBBLE_SORT_H_
