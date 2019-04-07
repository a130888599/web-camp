#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"
int Type;       //记录选择的数据类型
int k = 0;      //判断是否已经初始化
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Type = getType();
    k = 1;
    Q->front = Q->rear = NULL;
    Q->length = 0;
    printf("初始化成功\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列!\n");
        return ;
    }

    ClearLQueue(Q);
    k = 0;
    printf("销毁成功\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列");
        return FALSE;
    }

    if(!Q->length)
    {
        printf("该队列为空！\n");
        return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
        return FALSE;

    memcpy(e, Q->front->data, getSize(Type));
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }

    if(!Q->rear)
        Q->front = Q->rear = (Node *)malloc(sizeof(Node));
    else
    {
        Q->rear->next = (Node *)malloc(sizeof(Node));
        Q->rear = Q->rear->next;
    }
    Q->rear->next = NULL;

    Q->rear->data = malloc(getSize(Type));
    memcpy(Q->rear->data, data, getSize(Type));
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
        return FALSE;

    Node *p = Q->front;
    Q->front = Q->front->next;
    Q->length--;
    free(p->data);
    free(p);
    printf("出队成功\n");
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return ;
    }

    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front->data);
        free(Q->front);
        Q->front = Q->rear;
    }
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if(!k)
    {
        printf("请先初始化队列\n");
        return FALSE;
    }

    Node *p = Q->front;
    if(!p)
        printf("队列为空\n");
    while(p)
    {
        foo(p->data);
        p = p->next;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q)
{
    if(Type == 1)
        printf("%d  ", *(int*)q);
    if(Type == 2)
        printf("%.3f  ", *(float*)q);
}
