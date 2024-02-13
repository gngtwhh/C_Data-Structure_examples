/*
链表实现二叉搜索树
功能包括插入,删除,搜索,遍历(前中后序)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"

//#define BSTree_MAX 100
#define FALSE 0

//定义结构体用于保存树中的元素
typedef struct BSTree_NODE {
    int value;
    struct BSTree_NODE *left;
    struct BSTree_NODE *right;
} tree_node;

//定义树根指针
static tree_node*tree = NULL;

/*
**下面为内部函数
 */

//前序遍历(pre_order_traverse)
void do_pre_order_traverse(tree_node *current, void (*call_back)(TREE_TYPE value)) {
    if (current != NULL) {
        call_back(current->value);
        do_pre_order_traverse(current->left, call_back);
        do_pre_order_traverse(current->right, call_back);
    }
}

//中序遍历(in_order_traverse)
void do_in_order_traverse(tree_node *current, void (*call_back)(TREE_TYPE value)) {
    if (current != NULL) {
        do_pre_order_traverse(current->left, call_back);
        call_back(current->value);
        do_pre_order_traverse(current->right, call_back);
    }
}

//后序遍历(post_order_traverse)
void do_post_order_traverse(tree_node *current, void (*call_back)(TREE_TYPE value)) {
    if (current != NULL) {
        do_pre_order_traverse(current->left, call_back);
        do_pre_order_traverse(current->right, call_back);
        call_back(current->value);
    }
}

/*
**下面为接口部分
 */

//插入
void insert(TREE_TYPE value) {
    tree_node *current;
    tree_node **link = &tree;
    while ((current = *link) != NULL) {
        if (value < current->value)
            link = &current->left;
        else {
            assert(value != current->value);
            link = &current->right;
        }
    }
    current = malloc(sizeof(tree_node));
    assert(current != NULL);
    current->value = value;
    current->left = current->right = NULL;
    *link = current;
    /*
    **此处需使用二级指针才能对树做出有影响的修改,否则只是修改局部指针变量的值而已
    */
}

//查找
TREE_TYPE* find(TREE_TYPE value) {
    tree_node *current;
    current = tree;
    while (current != NULL && value != current->value) {
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (current != NULL)
        return &current->value;
    else
        return NULL;
}

//删除
void delete_BSTree(void);

//前序遍历接口
void pre_order_traverse(void (*call_back)(TREE_TYPE value)) {
    do_pre_order_traverse(tree, call_back);
}

//中序遍历接口
void in_order_traverse(void (*call_back)(TREE_TYPE value)) {
    do_in_order_traverse(tree, call_back);
}

//后序遍历接口
void post_order_traverse(void (*call_back)(TREE_TYPE value)) {
    do_post_order_traverse(tree, call_back);
}
