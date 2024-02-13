/*
静态数组实现队列,所以使用"循环数组"
该代码使用"不完全填满数组"的技巧来区分空队列和满队列,即使数组中一个元素始终保留不用
队列为空时rear比front小1
 */

#include "myqueue.h"
#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE 100//队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE+1)//数组的长度

//用于存储队列元素的数组和指向队列头和尾的指针
static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

//添加新元素
void insert_queue(QUEUE_TYPE value) {
	assert(!is_full());
	rear = (rear + 1) % ARRAY_SIZE;
	queue[rear] = value;
}

//删除一个元素并丢弃
void delete_queue(void) {
	assert(!is_empty());
	front = (front + 1) % ARRAY_SIZE;
}

//返回队列中第一个元素的值
QUEUE_TYPE first(void) {
	assert(!is_empty());
	return queue[front];
}

//如果队列为空返回TRUE,否则返回FALSE
int is_empty(void) {
	return (rear + 1) % ARRAY_SIZE == front;
}

//如果队满返回TRUE,否则返回FALSE
int is_full(void) {
	return (rear + 2) % ARRAY_SIZE == front;
}