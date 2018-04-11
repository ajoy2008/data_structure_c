/***************************************************************************//**
 \addtogroup ARR_STK_S8
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_stk_s8.c
 \details    Array Stack S8 API Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy Inc
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include <arr_stk_s8.h>

/*******************************************************************************
  PURPOSE:  To create an array stack
  COMMENT:
*******************************************************************************/
ARR_STK_S8_* arr_stk_create_s8(unsigned int stk_size)
{
    ARR_STK_S8_ *s = (ARR_STK_S8_ *)malloc(sizeof(ARR_STK_S8_));
    if(s == NULL)
        return NULL ;

    s->capacity = stk_size ;
    s->top = -1 ;
    s->arr = (char *)malloc(s->capacity * sizeof(char));
    if(s->arr == NULL)
        return NULL ;
    else
        return (s);
}

/*******************************************************************************
 PURPOSE:  To check the array stack is empty or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_empty_s8(ARR_STK_S8_ *s)
{
    return(s->top == -1);
}

/*******************************************************************************
 PURPOSE:  To check the stack is full or not
 COMMENT:
*******************************************************************************/
int arr_stk_is_full_s8(ARR_STK_S8_ *s)
{
    return(s->top == s->capacity - 1);
}

/*******************************************************************************
 PURPOSE:  To push an element into stack
 COMMENT:
*******************************************************************************/
void arr_stk_push_s8(ARR_STK_S8_ *s, char data)
{
    if(arr_stk_is_full_s8(s)) {
        printf("\nStack Overflow Error\n");
        exit(EXIT_FAILURE);
    }
    s->arr[++s->top] = data ;
}
/*******************************************************************************
 PURPOSE:  To pop an element from the stack
 COMMENT:
*******************************************************************************/
char arr_stk_pop_s8(ARR_STK_S8_ *s)
{
    if(arr_stk_is_empty_s8(s)) {
        printf("\nStack Underflow Error\n");
        exit(EXIT_FAILURE);
    }
    return(s->arr[s->top--]);
}

/*******************************************************************************
 PURPOSE:  To return the top element from the stack without popping
 COMMENT:
*******************************************************************************/
char arr_stk_top_s8(ARR_STK_S8_ *s)
{
    if(arr_stk_is_empty_s8(s)) {
        printf("\nStack underflow error\n");
        exit(EXIT_FAILURE);
    }
    return(s->arr[s->top]);
}

/*******************************************************************************
 PURPOSE:  To find the number of elements stored in the stack
 COMMENT:
*******************************************************************************/
int arr_stk_size_s8(ARR_STK_S8_ *s)
{
    if(arr_stk_is_full_s8(s)) {
        return(s->capacity);
    }
    else {
        return(s->top + 1);
    }
}

/*******************************************************************************
 PURPOSE:  To delete the array stack
 COMMENT:
*******************************************************************************/
void arr_stk_delete_s8(ARR_STK_S8_ *s)
{
    if(s) {
        if(s->arr){
            free(s->arr);
        }
        free(s);
    }
    return ;
}
/** @} */
