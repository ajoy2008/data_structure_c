/***************************************************************************//**
 \addtogroup REVERSE_STRING
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       reverse_string_using_stack.c
 \details    Reverse string with help of stack data structure
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
/*
input      : "Nataraj"
output     : jarataN

input      : "Geeks"
output     : skeeG

*/

#include <stack.h>
#include <string.h>
#include <ctype.h>

#define STK_MAX_SIZE 128

/*******************************************************************************
 PURPOSE: To reverse string using stack
*******************************************************************************/
int reverse_string(char *src)
{
  STK_S8_ *stk_s8 = stk_create_s8(STK_MAX_SIZE);
  size_t i = 0;

  for(i=0; src[i]; i++) {
    stk_push_s8(stk_s8, src[i]);
  }
  for(i=0; src[i]; i++) {
    src[i] = stk_pop_s8(stk_s8);
  }
  // Delete the stack to free the memory
  stk_delete_s8(stk_s8);
  return(EXIT_SUCCESS);
}

/***************************************************************************//**
  \details  Main program starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char src[STK_MAX_SIZE];
  int choice = 0 ;

  printf("0 : Program Exit\n");
  printf("1 : Reverse String\n");

  do {
    printf("\nYour Choice : ");
    scanf("%d",&choice);
    switch(choice){
      case 0 :
        printf("\nProgram Exited!\n");
        break ;
      case 1 :
        printf("\nEnter string to be reversed : ");
        getchar();
        gets(src);
        reverse_string(src);
        printf("\nAfter reversing :");
        puts(src);
        break ;
      default :
        printf("\nUnavailable choice!\n");
        exit(EXIT_FAILURE);
    }
  } while(choice) ;
  return 0;
}
