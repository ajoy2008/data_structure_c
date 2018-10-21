/***************************************************************************//**
  \defgroup   SORT COMMON
  @{
*******************************************************************************/
/***************************************************************************//**
  \file       sort_common.h
  \details    Common API implementation for sorting algorithm
  \author     Ajoy Samanta
  \copyright  All Rights Reserved.
  \copyright  Ajoy
  \copyright  16th Main 15th Cross
  \copyright  Bangalore - 560076
*******************************************************************************/
#ifndef _SORT_COMMON_H_
#define _SORT_COMMON_H_  1

#include <stdio.h>

typedef void (*print_arr_callback_t)(const void *);

/***************************************************************************//**
  \details  Swap two elements pass by reference mechanism
  \return   NA
*******************************************************************************/
void sort_swap(
  int *a,
  int *b
  );

/***************************************************************************//**
  \details  Print an integer array
  \return   NA
*******************************************************************************/
void print_array_int(
  int* arr,
  unsigned int n
  );

/***************************************************************************//**
  \details  Print an integer array
  \return   NA
*******************************************************************************/
void print_array_generic(
  int* arr,
  unsigned int n,
  unsigned int el_size,
  print_arr_callback_t print
  );
/** @} */
#endif // _SORT_COMMON_H_
