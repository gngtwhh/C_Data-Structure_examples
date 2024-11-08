//
// Created by WAHAHA on 2023/10/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrCircularQueue.h"

// make and destroy
queue_t new_queue(void) {
    queue_t new_queue = NULL;
    new_queue = (queue_t) malloc(sizeof(queue_obj_t));
    if (NULL == new_queue) {
        printf("error in malloc!new_queue malloc failed!\n");
        exit(-1);
    }
    new_queue->front = 0;
    new_queue->rear = 0;
    new_queue->length = 0;
    return new_queue;
}

bool destroy_queue(queue_t *Q) {
    if (NULL == Q) return false;
    queue_t temp = *Q;
    if (NULL == temp) return false;
    clear_queue(temp);
    free(temp);
    *Q = NULL;
    return true;
}

// check status
bool is_empty_queue(queue_t Q) {
    return Q->front == Q->rear ? true : false;
}

int queue_length(queue_t Q) {
    return Q->length;
}

//operations
bool push_queue(queue_t Q, q_elem_type e) {
    if (Q->length == QUEUE_SIZE) {
        printf("error in push_queue()!the queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % (QUEUE_SIZE + 1);
    Q->length++;
    return true;
}

bool pop_queue(queue_t Q, q_elem_type *e) {
    if (is_empty_queue(Q)) {
        printf("error in pop_queue()!the queue is empty!\n");
        return false;
    }
    if (NULL != e) {
        *e = Q->data[Q->front];
    }
    Q->front = (Q->front + 1) % (QUEUE_SIZE + 1);
    Q->length--;
    return true;
}

q_elem_type front_queue(queue_t Q) {
    if (is_empty_queue(Q)) {
        printf("error in front_queue()!the queue is empty!\n");
        exit(-1);
    }
    return Q->data[Q->front];
}

q_elem_type back_queue(queue_t Q) {
    if (is_empty_queue(Q)) {
        printf("error in back_queue()!the queue is empty!\n");
        exit(-1);
    }
    // rear指向的是队尾元素的下一个位置
    // 所以要减1,同时由于队列数组的长度为QUEUE_SIZE+1
    // 所以要加QUEUE_SIZE+1再取模
    return Q->data[(Q->rear - 1 + QUEUE_SIZE + 1) % (QUEUE_SIZE + 1)];
}

bool clear_queue(queue_t Q){
    Q->front = Q->rear = Q->length = 0;
    return true;
}
