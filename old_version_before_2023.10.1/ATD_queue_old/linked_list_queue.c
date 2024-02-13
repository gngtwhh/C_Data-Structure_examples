/*
链表实现队列---双向链表
 */
#include "myqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

 //定义一个结构体存储队列元素,其中next字段将指向堆栈的下一个元素
typedef struct QUEUE_NODE {
	struct QUEUE_NODE* fwd;
	QUEUE_TYPE value;
	struct QUEUE_NODE* bwd;

} QueueNode;

/*//队列的根指针结点---头指针和尾指针在一个结点内,该节点的值字段不会被使用
static QueueNode*queue;*/
static QueueNode* front = NULL;
static QueueNode* back = NULL;

//销毁队列
//该函数只适用于链式和动态分配数组的队列
void destory_queue(void) {
	if (is_empty())
		return;
	QueueNode* temp;
	while (front != NULL) {
		temp = front;
		front = front->bwd;
		//front->fwd=NULL;
		free(temp);
	}
	back = NULL;
}

//添加新元素
void insert_queue(QUEUE_TYPE value) {
	QueueNode* new_node = malloc(sizeof(QueueNode));
	assert(new_node != NULL);
	new_node->value = value;
	
	new_node->bwd = NULL;
	new_node->fwd = back;
	
	if (front == NULL) {
		front = back=new_node;
	}
	else {
		back->bwd = new_node;
		back = new_node;
	}
}

//删除一个元素并丢弃
void delete_queue(void) {
	QueueNode* front_node;
	assert(!is_empty());
	front_node = front;
	front = front->bwd;
	if (front == NULL) {
		back = NULL;
	}
	else {
		front->fwd = NULL;
	}
	free(front_node);
}

//返回队列中第一个元素的值
QUEUE_TYPE first(void) {
	assert(!is_empty());
	return front->value;
}

//如果队列为空返回TRUE,否则返回FALSE
int is_empty(void) {
	return front == NULL;
}

//如果队满返回TRUE,否则返回FALSE
int is_full(void) {
	return FALSE;
}