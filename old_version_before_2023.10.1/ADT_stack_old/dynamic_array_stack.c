#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define STACK_SIZE 100/*堆栈中值数量的最大限制*/

/*
用于存储堆栈元素的数组和指向堆栈顶部元素的指针
 */
static STACK_TYPE *stack;
static size_t stack_size;
static int top_element=-1;


/*
push
 */
void push(STACK_TYPE value){
	assert(!is_full());
	top_element+=1;
	stack[top_element]=value;
}

/*
pop
 */
void pop(void){
	assert(!is_empty());
	top_element-=1;
}
/*
top
 */
STACK_TYPE top(void){
	assert(!is_empty());
	return stack[top_element];
}

/*
is_empty
 */
int is_empty(void){
	assert(stack_size>0);
	return top_element==-1;
}

/*
is_full
 */
int is_full(void){
	assert(stack_size>0);
	return top_element==STACK_SIZE-1;
}

/*
create_stack
 */
void create_stack(size_t size){
	assert(stack_size==0);
	stack_size=size;
	stack=malloc(stack_size*sizeof(STACK_TYPE));
	assert(stack!=NULL);
}


/*
destory_stack
 */
void destory_stack(void){
	assert(stack_size>0);
	stack_size=0;
	free(stack);
	stack=NULL;
}