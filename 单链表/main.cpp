#include <stdio.h>
#include <stdlib.h>

/*������*/
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void ListPrint(LinkList &L);

/*ͷ�巨����������*/
LinkList List_HeadInsert(LinkList &L)
{
	//��ʼΪ������
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	//�����½��
	LNode *s;
	int x;
	//�������ֵ
	scanf("%d",&x);
	while (x != -1)//��-1Ϊ������־
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

/*β�巨����������*/
LinkList List_TailInsert(LinkList &L)
{
	//��ʼΪ������
	L = (LinkList)malloc(sizeof(LNode));
	//����β���
	LNode *r=L;
	//�����½��
	LNode *s;
	int x;
	scanf("%d", &x);
	while (x != -1)//��-1Ϊ������־
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

/*����Ų��ҽ��ֵ����������L��i������ֵ*/
LNode *GetElem(LinkList &L, int i)
{
	int j = 1;
	LNode *p = L->next; //ָ��pָ���һ�����
	if (i == 0) 
	{
		return L;//����ͷ���
	}
	else if (i < 1)
	{
		return NULL;//i��Ч
	}
	else
	{
		while (p && j < i)
		{
			p = p->next;
			j++;
		}
		return p;
	}
}

/*��ֵ���ұ��㣺���ر�L��ֵΪe�Ľ�����*/
int LocateElem(LinkList &L, int e)
{
	int j = 1;
	LNode *p = L->next;
	while ((p!=NULL) && (p->data != e))
	{
		p = p->next;
		j++;
	}
	return j;
}

/*��ǰ�����������ֵΪx���½����뵽��L�ĵ�i��λ��*/
void List_FrontInsert(LinkList &L, int i, int x)
{
	LNode *p = GetElem(L, i-1);
	//�����½��
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	ListPrint(L);
}

/*��������������½����뵽ָ�����p���ٽ���������ֵ*/
void List_BehindInsert(LinkList &L, LNode *p, int x)
{
	//����ֵΪx���½��
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	//����
	s->next = p->next;
	p->next = s;
	//��������
	int temp = p->data;
	p->data = s->data;
	s->data = temp;
	ListPrint(L);
}

/*ͨ��ǰ�����ɾ������������L��i�����ɾ��*/
void List_FrontDelete(LinkList &L, int i)
{
	LNode *p = GetElem(L, i - 1);
	LNode *q;//qΪ��ɾ�����
	q = p->next;
	p->next = q->next;
	free(q);
	ListPrint(L);
}

/*ͨ����̽��ɾ�����ͺ�̽�㽻��ֵ��ɾ����̽��*/
void List_BehindDelete(LinkList &L, LNode *q)
{
	LNode *s;//sΪq�ĺ�̽��
	s = q->next;
	q->data = q->next->data;
	q->next = s->next;
	free(s);
	ListPrint(L);
}

/*�������*/
int List_Length(LinkList &L)
{
	LNode *p = L->next;
	int j = 0;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

/*��ӡ�б�*/
void ListPrint(LinkList &L)
{
	LNode *p;
	p = L->next;
	printf("���ڴ�ӡ����...\n");
	while (p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LNode *L;
	//List_HeadInsert(L);
	List_TailInsert(L);
	ListPrint(L);
	printf("��2�����ֵΪ��%d\n",*GetElem(L, 2));
	printf("ֵΪ6�Ľ�����Ϊ��%d\n", LocateElem(L, 6));
	printf("�ڵ�3����㴦����ֵΪ7�Ľ��...\n");
	List_FrontInsert(L, 3, 7);
	printf("�ڵ�2����㴦����ֵΪ8�Ľ��...\n");
	LNode *p = GetElem(L, 2);//pָ���2�����
	List_BehindInsert(L, p, 8);
	printf("��Ϊ��%d\n",List_Length(L));
	printf("ɾ����2�����...\n");
	List_FrontDelete(L, 2);
	printf("ɾ����3�����...\n");
	LNode *q = GetElem(L, 3);
	List_BehindDelete(L, q);
	printf("��Ϊ��%d\n", List_Length(L));
	return 0;
}