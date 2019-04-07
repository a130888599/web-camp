#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"
int Type;       //��¼ѡ�����������
int k = 0;      //�ж��Ƿ��Ѿ���ʼ��
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Type = getType();
    k = 1;
    Q->front = Q->rear = NULL;
    Q->length = 0;
    printf("��ʼ���ɹ�\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ������!\n");
        return ;
    }

    ClearLQueue(Q);
    k = 0;
    printf("���ٳɹ�\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ������");
        return FALSE;
    }

    if(!Q->length)
    {
        printf("�ö���Ϊ�գ�\n");
        return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
        return FALSE;

    memcpy(e, Q->front->data, getSize(Type));
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
        return FALSE;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
        return FALSE;

    Node *p = Q->front;
    Q->front = Q->front->next;
    Q->length--;
    free(p->data);
    free(p);
    printf("���ӳɹ�\n");
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if(!k)
    {
        printf("���ȳ�ʼ������\n");
        return FALSE;
    }

    Node *p = Q->front;
    if(!p)
        printf("����Ϊ��\n");
    while(p)
    {
        foo(p->data);
        p = p->next;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
    if(Type == 1)
        printf("%d  ", *(int*)q);
    if(Type == 2)
        printf("%.3f  ", *(float*)q);
}
