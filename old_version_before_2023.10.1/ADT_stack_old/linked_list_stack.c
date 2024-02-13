#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

/*
定义一个结构以存储堆栈元素,其中next字段将指向堆栈的下一个元素
 */
typedef struct STACK_NODE {
	STACK_TYPE value;
	struct STACK_NODE*next;

} stack_node;
/*
指向堆栈中第一个节点的指针
 */
static stack_node*stack;

/*
push
 */
void push(STACK_TYPE value) {
	stack_node *new_node;

	new_node = malloc(sizeof(stack_node));
	assert(new_node != NULL);
	new_node->next = stack;
	stack = new_node;
}

/*
pop
 */
void pop(void) {
	stack_node *first_node;
	assert(!is_empty());
	first_node = stack;
	stack = first_node->next;
	free(first_node);
}
/*
top
 */
STACK_TYPE top(void) {
	assert(!is_empty());
	return stack->value;
}

/*
is_empty
 */
int is_empty(void) {
	return stack == NULL;
}

/*
is_full
 */
int is_full(void) {
	return FALSE;
}

/*
create_stack
 */
void create_stack(size_t size) {
	//不再需要
}


/*
destory_stack
 */
void destory_stack(void) {
	while (!is_empty())
		pop();
}