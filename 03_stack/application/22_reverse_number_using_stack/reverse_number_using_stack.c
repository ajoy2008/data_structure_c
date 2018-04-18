/***************************************************************************//**
 \addtogroup REVERSE_NUMBER
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       reverse_number_using_stack.c
 \details    Reverse number with help of stack data structure
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <stdio.h>

#define MAX_STK_SIZE 16

/***************************************************************************//**
  \details  Print individual digits of integer
  \return
*******************************************************************************/
unsigned int reverse_number(unsigned int num) {
  STK_S8_ *stk_s8 = stk_create_s8(MAX_STK_SIZE);
  unsigned int rev = 0;
  unsigned int i = 1;
  while(num > 0) {
    stk_push_s8(stk_s8, num%10);
    num = num/10;
  }
  while (!stk_is_empty_s8(stk_s8)){
    rev = rev + i * stk_pop_s8(stk_s8);
    i = i * 10 ;
  }
  stk_delete_s8(stk_s8) ;
  return(rev) ;
}

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  unsigned int num = 0 ;
  int choice = 0 ;

  printf("0 : Program Exit\n");
  printf("1 : Reverse number\n");

  do {
    printf("\nYour Choice : ");
    scanf("%d",&choice);
    switch(choice){
      case 0 :
        printf("\nProgram Exited!\n");
        break ;
      case 1 :
        printf("\nEnter number to be reversed : ");
        scanf("%u", &num);
        printf("\nAfter reversing :%u", reverse_number(num));
        printf("\n");
        break ;
      default :
        printf("\nUnavailable choice!\n");
        exit(EXIT_FAILURE);
    }
  } while(choice) ;
  return 0;
}
