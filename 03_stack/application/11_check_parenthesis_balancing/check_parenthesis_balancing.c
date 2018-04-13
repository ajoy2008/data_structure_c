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
/*
Input  : a+b*(c^d-e)^(f+g*h)-i
Output : BALANCED

Input  : [5/{7-(1+1)}]-[{2+(1+1)}]
Output : BALANCED

Input  : ((1*2)+3
Output : UNBALANCED

Input  : (1*2)+3)
Output : UNBALANCED
*/
#include <stack.h>
#include <string.h>

#define STK_MAX_SIZE 128
#define BALANCED     0
#define UNBALANCED  -1

/*******************************************************************************
 PURPOSE:  API to verify wheather matching pair exist or not
*******************************************************************************/
int is_matching_pair(char ch1, char ch2)
{
  if (ch1 == '(' && ch2 == ')')
    return 1;
  else if (ch1 == '{' && ch2 == '}')
    return 1;
  else if (ch1 == '[' && ch2 == ']')
    return 1;
  else
    return 0;
}

/*******************************************************************************
 PURPOSE:  Driver function to check the parenthesis balancing program
*******************************************************************************/
int is_parenthesis_balanced(char *src)
{
  STK_S8_ *stk = stk_create_s8(STK_MAX_SIZE);
  int ret = UNBALANCED ;
  /* Start Scanning */
  while(*src) {
    // If left parenthesis encountered then push it into stack
    if(*src == '(' || *src == '{' || *src == '[') {
      stk_push_s8(stk, *src) ;
    } else if(*src == ')' || *src == '}' || *src == ']') {
      if(stk_is_empty_s8(stk)) {
        return (UNBALANCED) ;
      } else if( !is_matching_pair(stk_pop_s8(stk), *src)){
        return (UNBALANCED) ;
      }
    }
    // Scan the next element
    src++ ;
  }

  // At the end empty stack implies Balanced, otherwise unbalanced
  ret = stk_is_empty_s8(stk) ? BALANCED : UNBALANCED ;

  // Delete the stack to free the memory
  stk_delete_s8(stk);

  return(ret);
}

/***************************************************************************//**
  \details  Main program starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char src[STK_MAX_SIZE];
  int result ;
  printf("\nEnter the infix expression :");
  gets(src);

  result = is_parenthesis_balanced(src);
  printf("\n%s\n", result ? "UNBALANCED" : "BALANCED");

  return 0;
}
