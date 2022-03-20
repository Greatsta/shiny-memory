#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
	ElemType e,i,n;
	LinkedList L,p,q;
	L = (LinkedList)malloc(sizeof(LNode));
	p = (LinkedList)malloc(sizeof(LNode));
	q = (LinkedList)malloc(sizeof(LNode));
	InitList(&L);
	printf(":::链表模式:::\n0)链表初始化\n1)创建链表\n2)清空链表\n3)插入成员\n4)删除成员\n5）遍历链表\n");
	while(1)
	{
		printf("请输入你想要的模式:\n");
		scanf_s("%d",&i);
		switch (i)
		{
			case 0:
				break;
			case 1:
				printf("初始化链表成功！\n请输入你要构建的节点数：");
				scanf_s("%d",&n);
				CreatListHead(&L,n);
				printf("创建成功！\n");
				break;
			case 2:
				DestroyList(&L);
				printf("毁灭成功！！！！\n");
				break;
			case 3:
				printf("请输入你要插入的结点的位置：\n");
				scanf_s("%d",&i);
				printf("请输入你要插入的节点的数据：\n");
				scanf_s("%d",&e);
				*p = *L;                    //设p为头结点，依次往后找
				while (p && n < i)
				{
					p = p->next;
					n++;
				}
				q = (LinkedList)malloc(sizeof(LNode));
				q->data = e;
				InsertList(p, q);
				printf("插入成功！\n");
				break;
			case 4:
				DeleteList(p,&e);
				printf("删除成功！");
				break;
			case 5:
				TraverseList(L, visit);
				break; 
	    }
	}
}

Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));  //分配内存
	if (L == NULL)                           
	{
		printf("内存分配失败\n");
		return ERROR;
	}                
	(*L)->next = NULL;                       //创建一个空链表
	return SUCCESS;
}

Status CreatListHead(LinkedList* L,int n)
{
	LinkedList p,r;
	int i,d;
	*L = (LinkedList)malloc(sizeof(LNode));
	r = *L;               //r为指向尾部的结点
	for (i = 0; i < n; i++)
	{
		p = (LinkedList)malloc(sizeof(LNode));  //生成新结点
		printf("请输入第%d个结点的数据：",i+1);   //输入结点数据
		scanf_s("%d",&d);
		p->data = d;
		r->next = p;              //将p插入在链表尾部
		r = p;                    //将当前新结点再作为尾部结点
	}
	return SUCCESS;
}

void DestroyList(LinkedList* L)
{
	LinkedList p,q;
	p = (*L)->next;                         //保留头结点
	while (p)
	{
		q = p ->next;                      //移动结点
		free(p);                             //释放当前结点
		p = q;
	}
}

Status InsertList(LNode* p, LNode* q)
{
	if (p == NULL || q == NULL)    
	{
		printf("内存分配失败\n");
		return ERROR;
	}
	q->next = p->next;                       //将未改动前p后的结点赋给q
	p->next = q;                             //让现在p的后续指向q
	return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL || p->next == NULL)
	{
		printf("内存分配失败\n");
		return ERROR;
	}
	printf("请输入你要删除后节点的前节点数据：\n");
	scanf_s("%d", p);
	LNode* q;
	q = p->next;                             //将P的下一个结点存放在q中
	p->next = q->next;                       //将P的下下个结点地址，也就是q的后继赋给p的后继
	*e = q->data;                            //将q结点中的数据赋给e
	free(q);                                 //释放删除的结点的内存
	return SUCCESS;

}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	if (L == NULL )
	{
		printf("内存分配失败\n");
	}
	LNode* p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
}

void visit(ElemType e)
{
	printf("%d ", e);
}
