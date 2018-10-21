/***************************************************************************//**
 \addtogroup INFIX_EVALUATION_SINGLE_PASS
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       infix_evaluation_single_pass.c
 \details    infix evaluation in single pass
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
/*
Infix      : ((5/(7-(1+1)))*3)+(2+(1+1))
Evaluation : 7

Infix      : (1*2)+3
Evaluation : 5

Infix      : ((1*2)+3
Postfix    : ERROR : Invalid expression

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
 PURPOSE:
*******************************************************************************/
char evaluate(char n1, char n2, char op)
{
  char n3 = 0 ;
  switch(op) {
    case '+': n3 = n2+n1 ; break ;
    case '-': n3 = n2-n1 ; break ;
    case '/': n3 = n2/n1 ; break ;
    case '*': n3 = n2*n1 ; break ;
    case '%': n3 = n2%n1 ; break ;
    case '^': n3 = pow(n2,n1) ; break ;
    default : printf("\nUnknown operator"); exit(EXIT_FAILURE);
  }
  return(n3 + '0');
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
int infix_evaluation_single_pass(char *src, char *result)
{
  char operand_1, operand_2, operator;
  size_t i ;
  size_t len = strlen(src);

  // Create a operator stack {for operators and parentheses}
  STK_S8_ *operator_stk = stk_create_s8(STK_MAX_SIZE);
  // Create a operand stack
  STK_S8_ *operand_stk = stk_create_s8(STK_MAX_SIZE);

  // Start Scanning of the source string
  for(i=0; i<len; i++) {
    if(isdigit(src[i])) {
      stk_push_s8(operand_stk, src[i]);
    } else if(src[i] == '(') {
      stk_push_s8(operator_stk, src[i]);
    } else if(src[i] == ')') {
      while(!stk_is_empty_s8(operator_stk) && stk_top_s8(operator_stk) != '(') {
        operand_1 = stk_pop_s8(operand_stk) - '0';
        operand_2 = stk_pop_s8(operand_stk) - '0';
        operator  = stk_pop_s8(operator_stk) ;
        stk_push_s8(operand_stk, evaluate(operand_1, operand_2, operator)) ;
      }
      if(stk_is_empty_s8(operator_stk)) {// This section handle the case like : (1*2)+3)
        printf("\nInvalid Expression !!");
        exit(EXIT_FAILURE);
      } else {
        stk_pop_s8(operator_stk) ;
      }
    } else if (src[i] == '^' || src[i] == '*' || src[i] == '/' ||
               src[i] == '%' || src[i] == '+' || src[i] == '-' ) {
        while(!stk_is_empty_s8(operator_stk) &&
               priority(stk_top_s8(operator_stk)) >= priority(src[i])) {
          operand_1 = stk_pop_s8(operand_stk) - '0';
          operand_2 = stk_pop_s8(operand_stk) - '0';
          operator  = stk_pop_s8(operator_stk) ;
          stk_push_s8(operand_stk, evaluate(operand_1, operand_2, operator)) ;
        }
        stk_push_s8(operator_stk, src[i]) ;
    }
  }
  while(!stk_is_empty_s8(operator_stk)) {
    if(stk_top_s8(operator_stk) != '(') {
      operand_1 = stk_pop_s8(operand_stk) - '0';
      operand_2 = stk_pop_s8(operand_stk) - '0';
      operator  = stk_pop_s8(operator_stk) ;
      stk_push_s8(operand_stk, evaluate(operand_1, operand_2, operator)) ;
    } else {
      printf("\nInvalid Expression !!");
      exit(EXIT_FAILURE);
    }
  }
  if(!stk_is_empty_s8(operand_stk)) {
    *result = stk_pop_s8(operand_stk) - '0';
  } else {
    exit(EXIT_FAILURE);
  }

  // Free up the stack after operation
  stk_delete_s8(operator_stk);
  stk_delete_s8(operand_stk);
  return(EXIT_SUCCESS);
}

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char source[STK_MAX_SIZE];
  char result ;
  printf("\nEnter the infix expression :");
  gets(source);
  printf("\nInfix :");
  puts(source);

  if(EXIT_SUCCESS == infix_evaluation_single_pass(source, &result)) {
    printf("\nResult = %d\n", result);
  } else {
    exit(EXIT_FAILURE);
  }
  return(EXIT_SUCCESS);
}
