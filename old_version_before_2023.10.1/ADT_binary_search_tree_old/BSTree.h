#include <stdlib.h>

#define TREE_TYPE int

//插入
void insert(TREE_TYPE value);

//查找
TREE_TYPE* find(TREE_TYPE value);

//检查是否为空树
int is_empty(void);

//删除
void delete_BSTree(void);

//前序遍历(pre_order_traverse)
void pre_order_traverse(void (*call_back)(TREE_TYPE value));

//中序遍历(in_order_traverse)
void in_order_traverse(void (*call_back)(TREE_TYPE value));

//后序遍历(post_order_traverse)
void post_order_traverse(void (*call_back)(TREE_TYPE value));