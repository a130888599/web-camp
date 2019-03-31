#include "../head/linkedList.h"
#include<stdlib.h>
#include<stdio.h>
void visit(int a);
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value 创建链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	printf("请输入链表长度:");
	int len;
	scanf("%d", &len);
	printf("请输入链表数据：");
	LinkedList pre = NULL, cur = NULL;
	//*L = (LinkedList)malloc(sizeof(LNode));		//头结点不存数据
	pre = *L;
	while (len--)
	{
		cur = (LinkedList)malloc(sizeof(LNode));
		scanf("%d", &cur->data);
		pre->next = cur;
		pre = cur;
	}
	pre->next = NULL;
	printf("创建链表成功\n\n");
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes	销毁链表
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	if (!(*L)||!(*L)->next) {
		error(0);
		return;
	}
	LinkedList cur = (*L)->next, nx = NULL;
    while(cur){
        nx = cur->next;
        free(cur);
        cur = nx;
    }
	(*L)->next = NULL;
	printf("销毁链表成功\n\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p	插入节点
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (!p || !q) {
		error(0);
		return ERROR;
	}
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node anfter the ode p and assign its value to e		删除节点
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if (!p) {
		error(0);
		return ERROR;
	}
	LinkedList nx = p->next;
	e = nx->data;
	p->next = nx->next;
	free(nx);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit		打印节点
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	if (!L ||!L->next) {
		error(0);
		return;
	}
	LinkedList cur = L->next;
	while (cur)
	{
		visit(cur->data);
		cur = cur->next;
	}
	printf("\n\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e	搜索节点
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if (!L) {
		error(0);
		return ERROR;
	}
	for (LinkedList cur = L->next; cur; cur = cur->next)
		if (cur->data == e)
			return SUCCESS;
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list		反转链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if (!(*L) || !(*L)->next) {
		error(0);
		return ERROR;
	}
	LinkedList cur = (*L)->next, pre = NULL, nx = NULL;
	while (cur->next)
	{
		nx = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nx;
	}
	cur->next = pre;
	(*L)->next = cur;
	TraverseList(*L, visit);
	printf("\n");
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped		判断循环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if (!L || !L->next) {
		error(0);
		return ERROR;
	}
	LinkedList fast = L, slow = L;
	while (slow && fast) {
		slow = slow->next;
		fast = fast->next ? fast->next->next : fast->next;
		if (slow == fast) {
			printf("该链表为循环链表\n\n");
			return SUCCESS;
		}
	}
	error(8);
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if (!(*L) || !(*L)->next) {
		error(0);
		return NULL;
	}
	printf("原链表:");
	TraverseList(*L, visit);
	LinkedList cur = *L;
	while (cur)
	{
		LinkedList first = cur->next;
		if (!first)
			break;
		LinkedList second = first->next;
		if (!second)
			break;

		cur->next = second;
		first->next = second->next;
		second->next = first;
		cur = first;
	}
	printf("\n修改后链表：");
	TraverseList(*L, visit);
	printf("\n\n");
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list		找中点
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if (!(*L)||!(*L)->next) {
		error(0);
		return NULL;
	}
	LinkedList fast = *L, slow = *L;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("中间节点：%d \n\n", slow->data);
	return slow;
}
