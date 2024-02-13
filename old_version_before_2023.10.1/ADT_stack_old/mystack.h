/*
**一个堆栈模块的接口
 */
#include <stdint.h>
#define STACK_TYPE int/*堆栈所存储的值的类型*/
/*
push
把一个新值压入到堆栈中,参数为需要被压入的值
 */
void push(STACK_TYPE value);

/*
pop
从堆栈弹出一个值并丢弃
 */
void pop(void);

/*
top
返回堆栈顶部元素,但不对堆栈进行修改
 */
STACK_TYPE top(void);

/*
如果堆栈为空,返回TRUE,否则返回FALSE
 */
int is_empty(void);

/*
如果堆栈已满,返回TRUE,否则返回FALSE
 */
int is_full(void);

/*
动态数组实现新函数
 */
/*
create_stack
创建堆栈
 */
void create_stack(size_t size);
/*
destory_stack
销毁堆栈
 */
void destory_stack(void);
