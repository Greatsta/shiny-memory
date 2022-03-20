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
	printf(":::����ģʽ:::\n0)�����ʼ��\n1)��������\n2)�������\n3)�����Ա\n4)ɾ����Ա\n5����������\n");
	while(1)
	{
		printf("����������Ҫ��ģʽ:\n");
		scanf_s("%d",&i);
		switch (i)
		{
			case 0:
				break;
			case 1:
				printf("��ʼ������ɹ���\n��������Ҫ�����Ľڵ�����");
				scanf_s("%d",&n);
				CreatListHead(&L,n);
				printf("�����ɹ���\n");
				break;
			case 2:
				DestroyList(&L);
				printf("����ɹ���������\n");
				break;
			case 3:
				printf("��������Ҫ����Ľ���λ�ã�\n");
				scanf_s("%d",&i);
				printf("��������Ҫ����Ľڵ�����ݣ�\n");
				scanf_s("%d",&e);
				*p = *L;                    //��pΪͷ��㣬����������
				while (p && n < i)
				{
					p = p->next;
					n++;
				}
				q = (LinkedList)malloc(sizeof(LNode));
				q->data = e;
				InsertList(p, q);
				printf("����ɹ���\n");
				break;
			case 4:
				DeleteList(p,&e);
				printf("ɾ���ɹ���");
				break;
			case 5:
				TraverseList(L, visit);
				break; 
	    }
	}
}

Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));  //�����ڴ�
	if (L == NULL)                           
	{
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}                
	(*L)->next = NULL;                       //����һ��������
	return SUCCESS;
}

Status CreatListHead(LinkedList* L,int n)
{
	LinkedList p,r;
	int i,d;
	*L = (LinkedList)malloc(sizeof(LNode));
	r = *L;               //rΪָ��β���Ľ��
	for (i = 0; i < n; i++)
	{
		p = (LinkedList)malloc(sizeof(LNode));  //�����½��
		printf("�������%d���������ݣ�",i+1);   //����������
		scanf_s("%d",&d);
		p->data = d;
		r->next = p;              //��p����������β��
		r = p;                    //����ǰ�½������Ϊβ�����
	}
	return SUCCESS;
}

void DestroyList(LinkedList* L)
{
	LinkedList p,q;
	p = (*L)->next;                         //����ͷ���
	while (p)
	{
		q = p ->next;                      //�ƶ����
		free(p);                             //�ͷŵ�ǰ���
		p = q;
	}
}

Status InsertList(LNode* p, LNode* q)
{
	if (p == NULL || q == NULL)    
	{
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	q->next = p->next;                       //��δ�Ķ�ǰp��Ľ�㸳��q
	p->next = q;                             //������p�ĺ���ָ��q
	return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e)
{
	if (p == NULL || p->next == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	printf("��������Ҫɾ����ڵ��ǰ�ڵ����ݣ�\n");
	scanf_s("%d", p);
	LNode* q;
	q = p->next;                             //��P����һ���������q��
	p->next = q->next;                       //��P�����¸�����ַ��Ҳ����q�ĺ�̸���p�ĺ��
	*e = q->data;                            //��q����е����ݸ���e
	free(q);                                 //�ͷ�ɾ���Ľ����ڴ�
	return SUCCESS;

}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	if (L == NULL )
	{
		printf("�ڴ����ʧ��\n");
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
