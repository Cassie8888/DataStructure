#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

/*������*/
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

/*ջ*/
typedef struct
{
	int arr[MaxSize];
	int top;
}Stack;

LinkList List_TailInsert(LinkList &L);           /*β�巨����������*/
LNode *GetElem(LinkList &L, int i);              /*����Ų��ҽ��ֵ����������L��i������ֵ*/
int LocateElem(LinkList &L, int e);              /*��ֵ���ұ��㣺���ر�L��ֵΪe�Ľ�����*/
void DeleteX(LinkList &L, int x);                /*ɾ��ֵΪx�Ľ��*/
void ListPrint(LinkList &L);                     /*��ӡ�б�*/
int List_Length(LinkList &L);                    /*�������*/
void ReverseList(LinkList &L);                   /*�����������*/
LinkList DeleteMin(LinkList &L);                 /*������Сֵ���Ψһ��ɾ������ֵ��С�Ľ��*/
LinkList ReverseList2(LinkList &L);              /*��������ʹ�ռ临�Ӷ�Ϊ1*/
void SortList(LinkList &L);                      /*��������������*/
LinkList DeleteBt(LinkList &L, int x, int y);    /*ɾ��ֵ��x��y֮��Ľ��*/
int CountDownK(LinkList &L, int k);              /*���������е�����k�����*/
LinkList DeleteCommonAbs(LinkList &L, int n);    /*ɾ�������о���ֵ��ͬ�Ľ�㣬ֻ������һ�γ��ֵĽ��*/

/*β�巨����������*/
LinkList List_TailInsert(LinkList &L)
{
	printf("��������ֵ��\n");
	//��ʼΪ������
	L = (LinkList)malloc(sizeof(LNode));
	LNode *r = L;//����β���
	//�����½��
	LNode *s;
	int x;
	//�������ֵ
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
	printf("������ɹ���\n");
	return L;
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
	while ((p != NULL) && (p->data != e))
	{
		p = p->next;
		j++;
	}
	return j;
}

/*ɾ��ֵΪx�Ľ��*/
void DeleteX(LinkList &L, int x)
{
	LNode *p = L->next;
	LNode *pre = L;
	LNode *q;       //�������ֵΪx�Ľ�㣬����ͷ�
	while (p != NULL)
	{
		if (p->data == x)
		{
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else
		{
			//ָ�����
			pre = p;
			p = p->next;
		}
	}
	printf("ɾ��ֵΪ%d�Ľ��\n", x);
}

/*��ӡ�б�*/
void ListPrint(LinkList &L)
{
	LNode *p;
	p = L->next;
	printf("���ڴ�ӡ����...\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/*�����������*/
void ReverseList(LinkList &L)
{
	printf("�����������\n");
	Stack S;
	int x;
	S.top = -1;
	LNode *p = L->next;
	while (p != NULL)
	{
		x = p->data;
		S.arr[++S.top] = x;
		p = p->next;
	}
	while (S.top != -1)
	{
		printf("%d ", S.arr[S.top--]);
	}
	printf("\n");
}

/*������Сֵ���Ψһ��ɾ������ֵ��С�Ľ��*/
LinkList DeleteMin(LinkList &L)
{
	printf("ɾ��ֵ��С�Ľ�㣺\n");
	LNode *pre = L;
	LNode *p = L->next;
	LNode *minpre = pre;
	LNode *min = p;
	//�ҵ�ֵ��С�Ľ��
	while (p != NULL)
	{
		if (p->data < min->data)
		{
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	//ɾ��ֵ��С�Ľ��
	minpre->next = min->next;
	free(min);
	return L;
}

/*��������ʹ�ռ临�Ӷ�Ϊ1*/
LinkList ReverseList2(LinkList &L)
{
	printf("��������\n");
	LNode *pre;
	LNode *p = L->next;
	LNode *r = p->next; //��Զָ��p�ĺ�һ�����
	p->next = NULL;     //��һ�������β��㣬ָ��NULL
	while (r != NULL)   //��ʱpָ�����һ�����
	{
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;  //ָ�뷴ת
	}
	L->next = p;  //ͷ���ָ��ԭ������һ�����
	return L;
}

/*��������������*/
void SortList(LinkList &L)
{
	LNode *pre; //ָ�����������һ�����
	LNode *p = L->next;
	LNode *r = p->next;
	p->next = NULL;
	//����һ�������ڶ������ָ���ӵڶ�����㿪ʼ�������λ��
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		//�Ȳ���ȵ�һ�����ֵ��Ľ��
		while (pre->next != NULL && p->data > pre->next->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
/*ɾ��ֵ��x��y֮��Ľ��*/
LinkList DeleteBt(LinkList &L, int x, int y)
{
	LNode *pre = L;
	LNode *p = L->next;
	while (p != NULL)
	{
		if (p->data > x &&p->data < y)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return L;
}

/*���������е�����k�����*/
int CountDownK(LinkList &L, int k)
{
	LNode *p = L->next;
	LNode *q = L->next;
	int i = 0;
	while (i < k)
	{
		p = p->next;
		i++;
	}
	while (p != NULL)
	{
		p = p->next;
		q = q->next;
	}
	printf("������%d��ֵΪ��%d\n", k, q->data);
	return 1;
}

/*ɾ�������о���ֵ��ͬ�Ľ�㣬ֻ������һ�γ��ֵĽ��*/
/*���ֵ�ľ���ֵ������n*/
LinkList DeleteCommonAbs(LinkList &L, int n)
{
	LNode *p = L->next;
	LNode *pre = L;
	int m;
	//�������飬δ���ֹ��Ľ��ֵ������ֵΪ0
	int *a = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i < n + 1; i++)
	{
		*(a + i) = 0;
	}
	while (pre->next != NULL)
	{
		m = pre->next->data > 0 ? pre->next->data : -pre->next->data;
		if (*(a + m) == 0)  //��һ�γ��֣���������
		{
			pre = pre->next;
			*(a + m) = 1;   //����ֵ��1
		}
		else                //�ڶ��γ��֣�ɾ��
		{
			p = pre->next;
			pre->next = p->next;
			free(p);
		}
	}
	free(a);
	return L;
}

int main()
{
	LinkList L;
	int n;
	List_TailInsert(L);
	ListPrint(L);
	//DeleteX(L, 2);
	//ListPrint(L);
	//ReverseList2(L);
	//DeleteMin(L);
	//SortList(L);
	//DeleteBt(L,3,9);
	//CountDownK(L, 3);
	DeleteCommonAbs(L, 6);
	ListPrint(L);
}