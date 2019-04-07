#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AQueue.h"
int Type;       //��¼ѡ�����������
int k = 0;      //�ж��Ƿ��Ѿ���ʼ��

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("δ��ʼ���жӣ�\n");
        return ;
    }

   ClearAQueue(Q);
   k = 0;
   printf("���ٳɹ�\n");
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
	{
		printf("����������\n");
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if (!Q->length)
	{
		printf("����Ϊ�գ�\n");
		return TRUE;
	}
	return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (!k)
    {
        printf("���ȳ�ʼ������\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
        return FALSE;

    memcpy(e, Q->data[Q->front], getSize(Type));
    return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ�����У�\n");
        return FALSE;
    }

    return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(!k)
    {
        printf("���ȳ�ʼ�����У�\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(!k)
    {
        printf("���ȳ�ʼ�����У�\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;

    free(Q->data[Q->front]);
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->length--;
    printf("���ӳɹ���\n");
    return TRUE;
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    if (!k)
    {
        printf("���ȳ�ʼ�����У�\n");
        return ;
    }
    Q->front = Q->rear = Q->length = 0;
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(!k)
    {
        printf("���ȳ�ʼ�����У�\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{
    if(Type == 1)
        printf("%d  ", *(int *)q);
    if(Type == 2)
        printf("%.3f  ", *(float *)q);
}
