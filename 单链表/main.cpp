#include <stdio.h>
#include <stdlib.h>

/*单链表*/
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void ListPrint(LinkList &L);

/*头插法建立单链表*/
LinkList List_HeadInsert(LinkList &L)
{
	//初始为空链表
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	//创建新结点
	LNode *s;
	int x;
	//输入结点的值
	scanf("%d",&x);
	while (x != -1)//以-1为结束标志
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

/*尾插法建立单链表*/
LinkList List_TailInsert(LinkList &L)
{
	//初始为空链表
	L = (LinkList)malloc(sizeof(LNode));
	//创建尾结点
	LNode *r=L;
	//创建新结点
	LNode *s;
	int x;
	scanf("%d", &x);
	while (x != -1)//以-1为结束标志
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

/*按序号查找结点值：返回链表L第i个结点的值*/
LNode *GetElem(LinkList &L, int i)
{
	int j = 1;
	LNode *p = L->next; //指针p指向第一个结点
	if (i == 0) 
	{
		return L;//返回头结点
	}
	else if (i < 1)
	{
		return NULL;//i无效
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

/*按值查找表结点：返回表L中值为e的结点序号*/
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

/*向前插入操作：将值为x的新结点插入到表L的第i个位置*/
void List_FrontInsert(LinkList &L, int i, int x)
{
	LNode *p = GetElem(L, i-1);
	//创建新结点
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	ListPrint(L);
}

/*向后插入操作：将新结点插入到指定结点p后，再交换两结点的值*/
void List_BehindInsert(LinkList &L, LNode *p, int x)
{
	//创建值为x的新结点
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	//插入
	s->next = p->next;
	p->next = s;
	//交换数据
	int temp = p->data;
	p->data = s->data;
	s->data = temp;
	ListPrint(L);
}

/*通过前驱结点删除操作：将表L第i个结点删除*/
void List_FrontDelete(LinkList &L, int i)
{
	LNode *p = GetElem(L, i - 1);
	LNode *q;//q为被删除结点
	q = p->next;
	p->next = q->next;
	free(q);
	ListPrint(L);
}

/*通过后继结点删除：和后继结点交换值后删除后继结点*/
void List_BehindDelete(LinkList &L, LNode *q)
{
	LNode *s;//s为q的后继结点
	s = q->next;
	q->data = q->next->data;
	q->next = s->next;
	free(s);
	ListPrint(L);
}

/*求表长操作*/
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

/*打印列表*/
void ListPrint(LinkList &L)
{
	LNode *p;
	p = L->next;
	printf("正在打印链表...\n");
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
	printf("第2个结点值为：%d\n",*GetElem(L, 2));
	printf("值为6的结点序号为：%d\n", LocateElem(L, 6));
	printf("在第3个结点处插入值为7的结点...\n");
	List_FrontInsert(L, 3, 7);
	printf("在第2个结点处插入值为8的结点...\n");
	LNode *p = GetElem(L, 2);//p指向第2个结点
	List_BehindInsert(L, p, 8);
	printf("表长为：%d\n",List_Length(L));
	printf("删除第2个结点...\n");
	List_FrontDelete(L, 2);
	printf("删除第3个结点...\n");
	LNode *q = GetElem(L, 3);
	List_BehindDelete(L, q);
	printf("表长为：%d\n", List_Length(L));
	return 0;
}