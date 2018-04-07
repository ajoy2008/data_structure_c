/***************************************************************************//**
 \addtogroup INFIX_TO_POSTFIX
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       infix_to_postfix.c
 \details    infix to postfix conversion
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
For array based stack operation, enable the flag __ARR_STK_U8__ in Makefile.
For linked list based stack operation enable flag __LIST_STK_U8__ in Makefile.
Currently default selection in Makefile is array based stack __ARR_STK_U8__
*/

#include <stack.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define STK_MAX_SIZE 128

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
int infix_to_postfix(char *src, char *tgt)
{
  char top;
  size_t i ;
  size_t len = strlen(src);

  // Create a character array stack
  STK_U8_ *stk = stk_create_u8(STK_MAX_SIZE);

  // push a sentinel '$' in the stack
  stk_push_u8(stk, '$');

  // Start Scanning of the source string
  for(i=0; i<len; i++) {
    // If digits or alphabet encountered during scanning then put it into target string
    if (isdigit(src[i]) || isalpha(src[i])) {
      *tgt++ = src[i] ;
    }
    // If left parenthesis encountered during scanning then push it into stack
    else if(src[i] == '(') {
      stk_push_u8(stk, src[i]) ;
    }
    /* If right parenthesis encountered during scanning, then
    pop the element from stack till left parenthesis reached and
    each time add the popped element into target string */
    else if(src[i] == ')') {
      top = stk_top_u8(stk) ;
      while (top != '$' && top != '(') {
       *tgt = stk_pop_u8(stk) ;
        tgt++;
        top = stk_top_u8(stk) ;
      }
      if (top == '$') {   // This section handle the case like : (1*2)+3)
        printf("\nInvalid Expression !!");
        exit(EXIT_FAILURE);
      } else {
        stk_pop_u8(stk) ;
      }
    }
    // If any of the operator encountered ?
    else if(src[i] == '^' || src[i] == '*' || src[i] == '/' || 
	        src[i] == '%' || src[i] == '+' || src[i] == '-') {
      /*
      If the priority of top operator is higher than the
      current scanned operator, then POP the operator from stack
      and put it into target string,
      otherwise add the current scanned operator in stack */
      top = stk_top_u8(stk) ;
      while( top != '$' && priority(top) >= priority(src[i])) {
        *tgt = stk_pop_u8(stk) ;
        tgt++;
        top = stk_top_u8(stk) ;
      }
      stk_push_u8(stk, src[i]) ;
    }
  }
  /* POP the elements from stack till it becomes empty
  and add to the target string simultaneously */
  top = stk_top_u8(stk) ;
  while(top != '$') {
    if(top != '(') {
      *tgt = stk_pop_u8(stk) ;
      tgt++ ;
      top = stk_top_u8(stk) ;
    } else { // This section handles the case like : ((1*2)+3
      printf("\nInvalid Expression !!");
      exit(EXIT_FAILURE);
    }
  }
  *tgt = '\0' ;
  // Free up the stack after operation
  stk_delete_u8(stk);
  return(EXIT_SUCCESS);
}

/*******************************************************************************
 PURPOSE:  Evaluation of postfix expression
*******************************************************************************/
int postfix_evaluation(char *src, long int *result)
{
  STK_U8_ *stk = stk_create_u8(STK_MAX_SIZE);
  long int n1, n2, n3 ;
  while(*src) {
    // Ignore spaces in the source string
    if(*src == ' '|| *src == '\t') {
      src++ ;
      continue ;
    }
    // If digits encountered during scanning then put it into target string
    if(isalpha(*src)) {
      printf("\nPostfix of Alphabet is not implemented. Please provide digits!");
      exit(EXIT_FAILURE);
    }
    else if(isdigit(*src)) {
      stk_push_u8(stk, *src) ;
    }
    else {
      n1 = (stk_pop_u8(stk) - '0');
      n2 = (stk_pop_u8(stk) - '0');

      switch(*src) {
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
      stk_push_u8(stk, n3 + '0');
    }
    src++ ;
  }
  *result = (stk_pop_u8(stk) - '0');
  return EXIT_SUCCESS;
}

/***************************************************************************//**
  \details  The main function starts from here
  \return   Zero
*******************************************************************************/
int main(void)
{
  char source[STK_MAX_SIZE], target[STK_MAX_SIZE] ;
  long int result ;
  printf("\nEnter the infix expression :");
  gets(source);
  printf("\nInfix :");
  puts(source);

  if(EXIT_SUCCESS == infix_to_postfix(source, target)) {
    printf("\nPostfix :");
    puts(target);
  } else {
    exit(EXIT_FAILURE);
  }
  printf("\nEvaluating postfix expression....");
  if(EXIT_SUCCESS == postfix_evaluation(target, &result)) {
    printf("\nResult = %ld\n", result);
  } else {
    exit(EXIT_FAILURE);
  }
  return(EXIT_SUCCESS);
}
