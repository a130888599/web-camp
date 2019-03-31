#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

void welcome()
{
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t-----1.创建链表                                                ------\n");
	printf("\t\t-----2.销毁链表                                                ------\n");
	printf("\t\t-----3.插入节点                                                ------\n");
	printf("\t\t-----4.删除节点                                                ------\n");
	printf("\t\t-----5.打印链表                                                ------\n");
	printf("\t\t-----6.搜索结点                                                ------\n");
	printf("\t\t-----7.反转链表                                                ------\n");
	printf("\t\t-----8.判断是否为循环链表                                      ------\n");
	printf("\t\t-----9.反转偶数结点                                            ------\n");
	printf("\t\t-----10.寻找中间节点                                           ------\n");
	printf("\t\t-----11.清屏                                                   ------\n");
	printf("\t\t-----0.返回（退出）                                            ------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n\n");
}

void visit(ElemType e)
{
	printf("%d  ", e);
}

void error(int i)
{
	if (i == 0)
		printf("未创建链表！！！\n");
	if(i == 1)
		printf("创建链表失败\n\n");
	if (i == 2)
		printf("插入节点失败\n\n");
	if (i == 3)
		printf("删除结点失败\n\n");
	if (i == 6)
		printf("结点不存在\n\n");
	if (i == 8)
		printf("该链表不是循环链表\n\n");
	if (i == 7)
		printf("链表中不存在此数据,请重新选择功能\n\n");
}

void pow_3(LinkedList *L)
{
	if (!(*L) || !(*L)->next) {
		error(0);
		return;
	}
	printf("请输入要插入的结点数据：");
	LinkedList temp = (LinkedList)malloc(sizeof(LNode));
	scanf("%d", &temp->data);
	TraverseList(*L, visit);
	printf("请选择要插在哪个数据之后：");
	int num;
	scanf("%d", &num);
	
	LinkedList cur = *L;
	while (cur->data != num)
		cur = cur->next;
	if (!cur) {
		error(7);
		return;
	}
	int a = InsertList(cur, temp);
	if (a == ERROR)
		error(2);
	else
		printf("插入节点成功\n");
	TraverseList(*L, visit);
}

void pow_4(LinkedList *L)
{
	if (!(*L) || !(*L)->next) {
		error(0);
		return;
	}
	TraverseList(*L, visit);
	printf("请选择要删除的结点：");
	int e;
	scanf("%d", &e);
	
	LinkedList p = *L;
	while (p->next->data != e) {
		p = p->next;
	}
	if (!p) {
		error(7);
		return;
	}
	int m = DeleteList(p, e);
	if (m == ERROR)
		error(3);
	else
		printf("删除成功\n");
	printf("链表：");
	TraverseList(*L, visit);
}

void pow_6(LinkedList *L)
{
	if (!(*L) || !(*L)->next) {
		error(0);
		return;
	}
	printf("请输入要搜索的结点：");
	ElemType e;
	scanf("%d", &e);
	int a = SearchList(*L, e);
	if (a == SUCCESS) {
		printf("结点存在\n\n");
		return;
	}
	else error(6);
}
