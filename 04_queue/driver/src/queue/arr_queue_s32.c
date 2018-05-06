/***************************************************************************//**
 \addtogroup ARR_QUEUE_S32
 @{
*******************************************************************************/
/***************************************************************************//**
 \file       arr_queue_s32.c
 \details    Arr Queue S32 API Implementation
 \author     Ajoy Samanta
 \copyright  All Rights Reserved.
 \copyright  Ajoy
 \copyright  House No 30, 16th Main 15th Cross
 \copyright  Bangalore - 560076
*******************************************************************************/
#include<arr_queue_s32.h>

/*******************************************************************************
  PURPOSE:  To create an S32 array queue
  COMMENT:
*******************************************************************************/
ARR_QUEUE_S32_* arr_queue_create_s32(unsigned int queue_size)
{
  ARR_QUEUE_S32_ *q = (ARR_QUEUE_S32_ *)malloc(sizeof(ARR_QUEUE_S32_));
  if(q == NULL)
    return NULL ;

  q->capacity = queue_size;
  q->front = 0 ;
  q->rear  = q->capacity - 1 ;
  q->size  = 0 ;
  q->arr = (int *)malloc(q->capacity * sizeof(int));
  if(q->arr == NULL)
    return NULL ;
  else
    return (q);
}

/*******************************************************************************
 PURPOSE:  To check the array queue is empty or not
 COMMENT:
*******************************************************************************/
int arr_queue_is_empty_s32(ARR_QUEUE_S32_ *q)
{
  return(q->size == 0);
}

/*******************************************************************************
 PURPOSE:  To check the queue is full or not
 COMMENT:
*******************************************************************************/
int arr_queue_is_full_s32(ARR_QUEUE_S32_ *q)
{
  return(q->size == q->capacity);
}

/*******************************************************************************
 PURPOSE:  To enqueue an element into Queue
 COMMENT:
*******************************************************************************/
void arr_queue_push_s32(ARR_QUEUE_S32_ *q, int data)
{
  if(arr_queue_is_full_s32(q)) {
    printf("\nQueue Overflow Error\n");
    exit(EXIT_FAILURE);
  } else {
    q->rear = (q->rear + 1) % q->capacity ;
    q->arr[q->rear] = data ;
    q->size = q->size + 1  ;
  }
  return ;
}
/*******************************************************************************
 PURPOSE:  To dequeue an element from the queue
 COMMENT:
*******************************************************************************/
int arr_queue_pop_s32(ARR_QUEUE_S32_ *q)
{
  int item ;
  if(arr_queue_is_empty_s32(q)) {
    printf("\nQueue Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  item = q->arr[q->front];
  q->arr[q->front] = 0   ;
  q->size = q->size - 1  ;
  if(arr_queue_is_empty_s32(q)) {
    q->front = 0;
    q->rear = q->capacity - 1 ;
  } else {
    q->front = (q->front + 1) % q->capacity ;
  }
  return(item);
}

/***************************************************************************//**
 PURPOSE:
 COMMENT:
*******************************************************************************/
int arr_queue_front_s32(ARR_QUEUE_S32_ *q)
{
  if(arr_queue_is_empty_s32(q)) {
    printf("\nQueue Underflow Error\n");
    exit(EXIT_FAILURE);
  } 
  return(q->arr[q->front]);
}

/***************************************************************************//**
 PURPOSE:
 COMMENT:
*******************************************************************************/
int arr_queue_rear_s32(ARR_QUEUE_S32_ *q)
{
  if(arr_queue_is_empty_s32(q)) {
	printf("\nQueue Underflow Error\n");
    exit(EXIT_FAILURE);
  }
  return(q->arr[q->rear]);
}

/*******************************************************************************
 PURPOSE:  To find the current size of the queue
 COMMENT:
*******************************************************************************/
int arr_queue_size_s32(ARR_QUEUE_S32_ *q)
{
  return(q->size) ;
}

/***************************************************************************//**
 PURPOSE:  To print queue contents
 COMMENT:
*******************************************************************************/
void  arr_queue_print_s32( ARR_QUEUE_S32_ *q )
{
  int i ;
  if(!arr_queue_is_empty_s32(q)) {
    printf("\nQueue : Front--> ");
    if(q->front <= q->rear){
      for(i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    } else {
      for(i = q->front; i <= (q->capacity + q->rear); i++)
        printf("%d ", q->arr[i%q->capacity]);
    }
    printf("<--Rear\n");
  }
}

/*******************************************************************************
 PURPOSE:  To delete the S32 array queue
 COMMENT:
*******************************************************************************/
void arr_queue_delete_s32(ARR_QUEUE_S32_ *q)
{
  if(q) {
    if(q->arr) {
      free(q->arr);
    }
    free(q);
  }
  return ;
}
/** @} */