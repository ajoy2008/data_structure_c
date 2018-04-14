/***************************************************************************//**
 \addtogroup INFIX_TO_POSTFIX
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       infix_to_postfix.c
 \details    infix to postfix conversion and postfix evaluation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
/*
Infix      : a+b*(c^d-e)^(f+g*h)-i
Postfix    : abcd^e-fgh*+^*+i-
Evaluation : Not supported currently for character. Will implement in future.

Infix      : ((5/(7-(1+1)))*3)-(2+(1+1))
Postfix    : 5 7 1 1 + - / 3 * 2 1 1 + + -
Evaluation : -1

Infix      : (1*2)+3
Postfix    : 12*3+
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
 PURPOSE:  Evaluation of postfix expression
*******************************************************************************/
int postfix_evaluation(char *postfix, char *result)
{
  STK_S8_ *stk = stk_create_s8(STK_MAX_SIZE);
  char n1, n2, n3 ;
  // Start scanning the postfix expression
  while(*postfix) {
    // Ignore spaces in the postfix string
    if(*postfix == ' '|| *postfix == '\t') {
      postfix++ ;
      continue ;
    }
    if(isalpha(*postfix)) {
      printf("\nPostfix of Alphabet is not implemented. Please provide digits!");
      exit(EXIT_FAILURE);
    } else if(isdigit(*postfix)) { // If digits encountered then put it into postfix string
      stk_push_s8(stk, *postfix) ;
    }
    else {
      n1 = (stk_pop_s8(stk) - '0');
      n2 = (stk_pop_s8(stk) - '0');

      switch(*postfix) {
        case '+':
          n3 = n2+n1 ;
          break ;
        case '-':
          n3 = n2-n1 ;
          break ;
        case '/':
          n3 = n2/n1 ;
          break ;
        case '*':
          n3 = n2*n1 ;
          break ;
        case '%':
          n3 = n2%n1 ;
          break ;
        case '^':
          n3 = pow(n2,n1) ;
          break ;
        default :
          printf("\nUnknown operator");
          exit(EXIT_FAILURE);
      }
      stk_push_s8(stk, n3 + '0');
    }
    postfix++ ;
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
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char infix[STK_MAX_SIZE], postfix[STK_MAX_SIZE] ;
  char result ;
  printf("\nEnter the infix expression :");
  gets(infix);
  printf("\nInfix :");
  puts(infix);

  if(EXIT_SUCCESS == infix_to_postfix(infix, postfix)) {
    printf("\nPostfix :");
    puts(postfix);
  } else {
    exit(EXIT_FAILURE);
  }
  printf("\nEvaluating postfix expression....");
  if(EXIT_SUCCESS == postfix_evaluation(postfix, &result)) {
    printf("\nResult = %d\n", result);
  } else {
    exit(EXIT_FAILURE);
  }
  return(EXIT_SUCCESS);
}
