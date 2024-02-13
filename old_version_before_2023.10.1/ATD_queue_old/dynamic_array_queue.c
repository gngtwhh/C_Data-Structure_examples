/*
动态数组实现队列,所以使用"循环数组"
基本类似静态数组
该代码使用"不完全填满数组"的技巧来区分空队列和满队列,即使数组中一个元素始终保留不用
队列为空时rear比front小1
 */

#include "myqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//#define QUEUE_SIZE 100//队列中元素的最大数量

//用于指向(存储队列元素的数组)的指针,和指向队列头和尾的指针
static size_t front = 1;
static size_t rear = 0;	
static QUEUE_TYPE *queue;
//数组的长度
size_t array_size=0;


//创建队列,参数指定队列可以存储的元素的最大数量
//该函数只适用于动态分配数组的队列
void create_queue(size_t size){
	array_size=size+1;
	queue=malloc(sizeof(QUEUE_TYPE)*array_size);
	assert(queue!=NULL);
}

//销毁队列
//该函数只适用于链式和动态分配数组的队列
void destory_queue(void){
	assert(array_size>0);
	array_size=0;
	free(queue);
	queue=NULL;
}

//添加新元素
void insert_queue(QUEUE_TYPE value) {
	assert(!is_full());
	rear = (rear + 1) % array_size;
	queue[rear] = value;
}

//删除一个元素并丢弃
void delete_queue(void) {
	assert(!is_empty());
	front = (front + 1) % array_size;
}

//返回队列中第一个元素的值
QUEUE_TYPE first(void) {
	assert(!is_empty());
	return queue[front];
}

//如果队列为空返回TRUE,否则返回FALSE
int is_empty(void) {
	return (rear + 1) % array_size == front;
}

//如果队满返回TRUE,否则返回FALSE
int is_full(void) {
	return (rear + 2) % array_size == front;
}