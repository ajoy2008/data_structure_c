/***************************************************************************//**
 \addtogroup INFIX_TO_PREFIX
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       infix_to_prefix.c
 \details    infix to prefix conversion and prefix expression evaluation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
/*
Infix      : a+b*(c^d-e)^(f+g*h)-i
Prefix     : +a-*b^-^cde+f*ghi
Evaluation : Not supported currently for character. Will implement in future.

Infix      : ((5/(7-(1+1)))*3)-(2+(1+1))
Prefix     : - * / 5 - 7 + 1 1 3 + 2 + 1 1
Evaluation : -1

Infix      : (1*2)+3
Prefix     : +*123
Evaluation : 5

Infix      : ((1*2)+3
Prefix     : ERROR : Invalid expression

Infix      : (1*2)+3)
Postfix    : ERROR : Invalid expression
*/

/*
NOTE :
For array based stack operation, enable the flag __ARR_STK_S8__ in Makefile.
For linked list based stack operation enable flag __LIST_STK_S8__ in Makefile.
Currently default selection in Makefile is array based stack __ARR_STK_S8__
*/

/*
 LIMITATION :
 - This implementation only evaluates the expression of single digits numeric operands.
*/

#include <stack.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define STK_MAX_SIZE 128

/*******************************************************************************
 PURPOSE:  Evaluation of prefix expression
*******************************************************************************/
int prefix_evaluation(char *prefix, char *result)
{
  STK_S8_ *stk = stk_create_s8(STK_MAX_SIZE);
  size_t i, len ;
  char n1, n2, n3 ;
  strrev(prefix);
  len = strlen(prefix);
  for(i= 0; i<len; i++) {
    if(isalpha(prefix[i])) {
      printf("\nPrefix evaluation of Alphabet is not implemented. Please provide digits!");
      exit(EXIT_FAILURE);
    } else if(isdigit(prefix[i])) {
      stk_push_s8(stk, prefix[i]);
    } else if(prefix[i] == '^' || prefix[i] == '*' || prefix[i] == '/' ||
              prefix[i] == '%' || prefix[i] == '+' || prefix[i] == '-') {
      n1 = (stk_pop_s8(stk) - '0');
      n2 = (stk_pop_s8(stk) - '0');
      switch(prefix[i]) {
        case '+': n3 = n1+n2 ; break ;
        case '-': n3 = n1-n2 ; break ;
        case '/': n3 = n1/n2 ; break ;
        case '*': n3 = n1*n2 ; break ;
        case '%': n3 = n1%n2 ; break ;
        case '^': n3 = pow(n1,n2) ; break ;
        default : printf("\nUnknown operator"); exit(EXIT_FAILURE);
      }
      stk_push_s8(stk, n3 + '0');
    }
  }
  *result = (stk_pop_s8(stk) - '0');
  return EXIT_SUCCESS;
}

/*******************************************************************************
 PURPOSE:  To determine the priority of the operator
*******************************************************************************/
int priority(char operator)
{
  int prio ;
  if(operator == '^')
    prio = 3 ;
  else if(operator == '*' || operator == '/' || operator == '%')
    prio = 2 ;
  else if(operator == '+' || operator == '-')
    prio = 1 ;
  else
    prio = 0 ;

  return (prio);
}

/*******************************************************************************
 PURPOSE:  Infix to postfix conversion
*******************************************************************************/
int infix_to_postfix(char *infix, char *postfix)
{
  size_t i ;
  size_t len = strlen(infix);

  // Create a character array stack
  STK_S8_ *stk = stk_create_s8(STK_MAX_SIZE);

  // Start Scanning of the infix string
  for(i=0; i<len; i++) {
    // If digits or alphabet encountered during scanning then put it into postfix string
    if (isdigit(infix[i]) || isalpha(infix[i])) {
      *postfix++ = infix[i] ;
    }
    // If left parenthesis encountered during scanning then push it into stack
    else if(infix[i] == '(') {
      stk_push_s8(stk, infix[i]) ;
    }
    /* If right parenthesis encountered during scanning, then
    pop the element from stack till left parenthesis reached and
    each time add the popped element into postfix string */
    else if(infix[i] == ')') {
      while (!stk_is_empty_s8(stk) && stk_top_s8(stk) != '(') {
       *postfix++ = stk_pop_s8(stk) ;
      }
      if (stk_is_empty_s8(stk)) {// This section handle the case like : (1*2)+3)
        printf("\nInvalid Expression !!");
        exit(EXIT_FAILURE);
      } else {
        stk_pop_s8(stk) ;
      }
    }
    // If any of the operator encountered ?
    else if(infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || 
	        infix[i] == '%' || infix[i] == '+' || infix[i] == '-') {
      /*
      If the priority of top operator is higher than the
      current scanned operator, then POP the operator from stack
      and put it into postfix string,
      otherwise add the current scanned operator in stack */
      while( !stk_is_empty_s8(stk) && priority(stk_top_s8(stk)) >= priority(infix[i])) {
        *postfix++ = stk_pop_s8(stk) ;
      }
      stk_push_s8(stk, infix[i]) ;
    }
  }
  /* POP the elements from stack till it becomes empty
  and add to the postfix string simultaneously */
  while(!stk_is_empty_s8(stk)) {
    if(stk_top_s8(stk) != '(') {
      *postfix++ = stk_pop_s8(stk) ;
    } else { // This section handles the case like : ((1*2)+3
      printf("\nInvalid Expression !!");
      exit(EXIT_FAILURE);
    }
  }
  *postfix = '\0' ;
  // Free up the stack after operation
  stk_delete_s8(stk);
  return(EXIT_SUCCESS);
}

/***************************************************************************//**
  \details  Infix to prefix conversion
  \return   Zero
*******************************************************************************/
int infix_to_prefix(char *infix, char *prefix)
{
  size_t len = strlen(infix);
  // Reverse the infix expression
  strrev(infix);
  // Replace ( with ) and vice versa
  for (int i = 0; i < len; i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
    } else if (infix[i] == ')') {
      infix[i] = '(';      
    }
  }
  infix_to_postfix(infix, prefix);
  strrev(prefix);
  return(EXIT_SUCCESS);
}

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char infix[STK_MAX_SIZE], prefix[STK_MAX_SIZE] ;
  char result ;
  printf("\nEnter the infix expression :");
  gets(infix);
  printf("\nInfix :");
  puts(infix);

  if(EXIT_SUCCESS == infix_to_prefix(infix, prefix)) {
    printf("\nPrefix :");
    puts(prefix);
  } else {
    exit(EXIT_FAILURE);
  }
  printf("\nEvaluating prefix expression....");
  if(EXIT_SUCCESS == prefix_evaluation(prefix, &result)) {
    printf("\nResult = %d\n", result);
  } else {
    exit(EXIT_FAILURE);
  }
  return(EXIT_SUCCESS);
}
