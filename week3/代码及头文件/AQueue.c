#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"
int Type;       //记录选择的数据类型
int k = 0;      //判断是否已经初始化

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Type = getType();
    k = 1;
    Q->front = Q->rear = Q->length = 0;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("未初始化列队！\n");
        return ;
    }

   ClearAQueue(Q);
   k = 0;
   printf("销毁成功\n");
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
	{
		printf("队列已满！\n");
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if (!Q->length)
	{
		printf("队列为空！\n");
		return TRUE;
	}
	return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
        return FALSE;

    memcpy(e, Q->data[Q->front], getSize(Type));
    return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列！\n");
        return FALSE;
    }

    return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(!k)
    {
        printf("请先初始化队列！\n");
        return FALSE;
    }
    if(IsFullAQueue(Q))
        return FALSE;

    Q->data[Q->rear] = malloc(getSize(Type));
    memcpy(Q->data[Q->rear], data, getSize(Type));
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->length++;
    return TRUE;
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;

    free(Q->data[Q->front]);
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->length--;
    printf("出队成功！\n");
    return TRUE;
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    if (!k)
    {
        printf("请先初始化队列！\n");
        return ;
    }
    Q->front = Q->rear = Q->length = 0;
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(!k)
    {
        printf("请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
        return FALSE;

    int p = Q->front;
    while(p < Q->length + Q->front)
        foo(Q->data[p++ % MAXQUEUE]);
    return TRUE;
}


/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
{
    if(Type == 1)
        printf("%d  ", *(int *)q);
    if(Type == 2)
        printf("%.3f  ", *(float *)q);
}
