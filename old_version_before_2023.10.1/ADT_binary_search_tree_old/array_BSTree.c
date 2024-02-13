#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"

#define FALSE 0
#define TREE_SIZE 100//树的最大存储范围
#define ARRAY_SIZE (TREE_SIZE+1)//数组的大小

//用于存储树的所有节点的数组
static TREE_TYPE tree[ARRAY_SIZE];


/*
**以下为内部函数
*/
//计算左孩子的下标
static int left_child(int current) {
	return current * 2;
}

//计算右孩子的下标
static int right_child(int current) {
	return current * 2 + 1;
}

//前序遍历(pre_order_traverse)
void do_pre_order_traverse(int current, void (*call_back)(TREE_TYPE value)) {
	if (current < ARRAY_SIZE && tree[current] != 0) {
		call_back(tree[current]);
		do_pre_order_traverse(left_child(current), call_back);
		do_pre_order_traverse(right_child(current), call_back);
	}
}

//中序遍历(in_order_traverse)
void do_in_order_traverse(int current, void (*call_back)(TREE_TYPE value)){
	if (current < ARRAY_SIZE && tree[current] != 0) {
		do_pre_order_traverse(left_child(current), call_back);
		call_back(tree[current]);
		do_pre_order_traverse(right_child(current), call_back);
	}
}

//后序遍历(post_order_traverse)
void do_post_order_traverse(int current, void (*call_back)(TREE_TYPE value)){
	if (current < ARRAY_SIZE && tree[current] != 0) {
		do_pre_order_traverse(left_child(current), call_back);
		do_pre_order_traverse(right_child(current), call_back);
		call_back(tree[current]);
	}
}


/*
**以下为接口部分
*/
//插入
void insert(TREE_TYPE value) {
	int current = 1;
	//0值用于提示一个未使用的节点
	assert(value != 0);
	while (tree[current] != 0) {
		if (value < tree[current]) {
			current = left_child(current);
		} else {
			assert(value != tree[current]);
			current = right_child(current);
		}
		assert(current < ARRAY_SIZE);
	}
	tree[current] = value;
}

//查找
TREE_TYPE* find(TREE_TYPE value) {
	int current = 1;
	//该函数可以优化?---搜索到值为0的结点说明该节点已经为空?
	while (current < ARRAY_SIZE && tree[current] != value) {
		if (value < tree[current])
			current = left_child(current);
		else
			current = right_child(current);
	}
	if (current < ARRAY_SIZE)
		return tree + current;
	else
		return NULL;
}

//删除
void delete_BSTree(void) {

}

//检查是否为空树
int is_empty(void){
	return !tree[1];
}

//前序遍历(pre_order_traverse)
void pre_order_traverse(void (*call_back)(TREE_TYPE value)) {
	do_pre_order_traverse(1, call_back);
}

//中序遍历(in_order_traverse)
void in_order_traverse(void (*call_back)(TREE_TYPE value)) {
	do_in_order_traverse(1, call_back);
}

//后序遍历(post_order_traverse)
void post_order_traverse(void (*call_back)(TREE_TYPE value)) {
	do_post_order_traverse(1, call_back);
}