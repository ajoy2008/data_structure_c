/***************************************************************************//**
 \addtogroup IS_PALINDROME
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       is_palindrome.c
 \details    Check wheather a string is palindrome or not ??
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
/*
input      : "Madam"
output     : PALINDROME

input      : "12321"
output     : PALINDROME

input      : "Geeks"
output     : NOT PALINDROME

*/


#include <stack.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define STK_MAX_SIZE 128

#define STK_MAX_SIZE 128
#define PALINDROME      1
#define NOT_PALINDROME  0


/*******************************************************************************
 PURPOSE:  Driver function to check the parenthesis balancing program
*******************************************************************************/
int is_palindrome(char *src)
{
  STK_S8_ *stk_s8 = stk_create_s8(STK_MAX_SIZE);
  char *src_lwr = strlwr(src);
  size_t i = 0;

  for(i=0; src_lwr[i]; i++) {
    stk_push_s8(stk_s8, src_lwr[i]);
  }
  for(i=0; src_lwr[i]; i++) {
    if(src_lwr[i] != stk_pop_s8(stk_s8)) {
      stk_delete_s8(stk_s8);
      return(NOT_PALINDROME);
    }
  }
  // Delete the stack to free the memory
  stk_delete_s8(stk_s8);
  return(PALINDROME);
}

/***************************************************************************//**
  \details  Main program starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char src[STK_MAX_SIZE];
  int result ;
  printf("\nEnter the input string :");
  gets(src);

  result = is_palindrome(src);
  printf("\n%s\n", result ? "PALINDROME" : "NOT PALINDROME");

  return 0;
}
