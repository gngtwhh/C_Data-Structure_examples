#include <stdlib.h>

#define QUEUE_TYPE int

//创建队列,参数指定队列可以存储的元素的最大数量
//该函数只适用于动态分配数组的队列
void create_queue(size_t size);

//销毁队列
//该函数只适用于链式和动态分配数组的队列
void destory_queue(void);

//添加新元素
void insert_queue(QUEUE_TYPE value);

//删除一个元素并丢弃
void delete_queue(void);

//返回队列中第一个元素的值
QUEUE_TYPE first(void);

//如果队列为空返回TRUE,否则返回FALSE
int is_empty(void);

//如果队满返回TRUE,否则返回FALSE
int is_full(void);