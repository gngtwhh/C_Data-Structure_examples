//
// Created by WAHAHA on 2023/10/15.
//

#ifndef ADT_ARR_CIRCULAR_QUEUE_H
#define ADT_ARR_CIRCULAR_QUEUE_H

#define QUEUE_SIZE 20
#define bool int
#define true 1
#define false 0

typedef int q_elem_type;

typedef struct queue_obj_s{
    q_elem_type data[QUEUE_SIZE + 1];
    int front;
    int rear;
    int length;
} queue_obj_t, *queue_t;

// make and destroy
queue_t new_queue(void);
bool destroy_queue(queue_t *Q);

// check status
bool is_empty_queue(queue_t Q);
int queue_length(queue_t Q);

//operations
bool push_queue(queue_t Q, q_elem_type e);
bool pop_queue(queue_t Q, q_elem_type* e);
q_elem_type front_queue(queue_t Q);
q_elem_type back_queue(queue_t Q);
bool clear_queue(queue_t Q);

#endif // ADT_ARR_CIRCULAR_QUEUE_H
