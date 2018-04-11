/***************************************************************************//**
 \addtogroup CHECK_PARENTHESIS_BALANCING
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       check_parenthesis_balancing.c
 \details    Check for parenthesis balancing
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <stack.h>
#include <string.h>

#define STK_MAX_SIZE 128
#define BALANCED     0
#define UNBALANCED  -1

/*******************************************************************************
 PURPOSE:  Driver function to check the parenthesis balancing program
*******************************************************************************/
int is_parenthesis_balanced(char *src)
{
  int ret ;
  char pop ;
  STK_U8_ *stk = stk_create_u8(STK_MAX_SIZE);
	
  /* Start Scanning */
  while(*src) {
    // If left parenthesis encountered then push it into stack
    if(*src == '(') {
      stk_push_u8(stk, *src) ; 
    }
    // If right parenthesis encountered... 
    if(*src == ')') {
      // if stack is empty then return error
      if(stk_is_empty_u8(stk)) {
        ret  = UNBALANCED ;
        return (ret) ;
      } else { // Otherwise, Start popping till the left parenthesis reached
        pop = stk_pop_u8(stk) ;
        while(pop != '(') {
		  if(! stk_is_empty_u8(stk))
            pop = stk_pop_u8(Stk);
	      else
		    break ;
        }
      }        
    }

    // Scan the next element
    Src++ ;
  }

  // At the end empty stack implies success, otherwise failure
  ex = StkIsEmpty_U8(Stk) ? BALANCED : UNBALANCED ;

  // Delete the stack to free the memory
  StkDelete_U8(Stk);

  return(ex);
}



/***************************************************************************//**
  \details  Main program starts from here
  \return   Zero
*******************************************************************************/
int  main(void)
{
  char src[STK_MAX_SIZE];
  int result ;
  printf("\nEnter the infix expression :");
  gets(src);

  result = is_parenthesis_balanced(src);
   
  if(result != BALANCED)
    printf("\nUNBALANCED\n");
  else
    printf("\nBALANCED\n");

  return 0;
}
