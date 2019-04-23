#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

/*单链表*/
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

/*栈*/
typedef struct
{
	int arr[MaxSize];
	int top;
}Stack;

LinkList List_TailInsert(LinkList &L);           /*尾插法建立单链表*/
LNode *GetElem(LinkList &L, int i);              /*按序号查找结点值：返回链表L第i个结点的值*/
int LocateElem(LinkList &L, int e);              /*按值查找表结点：返回表L中值为e的结点序号*/
void DeleteX(LinkList &L, int x);                /*删除值为x的结点*/
void ListPrint(LinkList &L);                     /*打印列表*/
int List_Length(LinkList &L);                    /*求表长操作*/
void ReverseList(LinkList &L);                   /*反向输出链表*/
LinkList DeleteMin(LinkList &L);                 /*假设最小值结点唯一，删除表中值最小的结点*/
LinkList ReverseList2(LinkList &L);              /*逆置链表使空间复杂度为1*/
void SortList(LinkList &L);                      /*变成有序递增链表*/
LinkList DeleteBt(LinkList &L, int x, int y);    /*删除值在x和y之间的结点*/
int CountDownK(LinkList &L, int k);              /*查找链表中倒数第k个结点*/
LinkList DeleteCommonAbs(LinkList &L, int n);    /*删除链表中绝对值相同的结点，只保留第一次出现的结点*/

/*尾插法建立单链表*/
LinkList List_TailInsert(LinkList &L)
{
	printf("请输入结点值：\n");
	//初始为空链表
	L = (LinkList)malloc(sizeof(LNode));
	LNode *r = L;//创建尾结点
	//创建新结点
	LNode *s;
	int x;
	//输入结点的值
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
	printf("插入结点成功！\n");
	return L;
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
	while ((p != NULL) && (p->data != e))
	{
		p = p->next;
		j++;
	}
	return j;
}

/*删除值为x的结点*/
void DeleteX(LinkList &L, int x)
{
	LNode *p = L->next;
	LNode *pre = L;
	LNode *q;       //用来标记值为x的结点，最后释放
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
			//指针后移
			pre = p;
			p = p->next;
		}
	}
	printf("删除值为%d的结点\n", x);
}

/*打印列表*/
void ListPrint(LinkList &L)
{
	LNode *p;
	p = L->next;
	printf("正在打印链表...\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/*反向输出链表*/
void ReverseList(LinkList &L)
{
	printf("反向输出链表：\n");
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

/*假设最小值结点唯一，删除表中值最小的结点*/
LinkList DeleteMin(LinkList &L)
{
	printf("删除值最小的结点：\n");
	LNode *pre = L;
	LNode *p = L->next;
	LNode *minpre = pre;
	LNode *min = p;
	//找到值最小的结点
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
	//删除值最小的结点
	minpre->next = min->next;
	free(min);
	return L;
}

/*逆置链表使空间复杂度为1*/
LinkList ReverseList2(LinkList &L)
{
	printf("逆置链表：\n");
	LNode *pre;
	LNode *p = L->next;
	LNode *r = p->next; //永远指向p的后一个结点
	p->next = NULL;     //第一个结点变成尾结点，指向NULL
	while (r != NULL)   //此时p指向最后一个结点
	{
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;  //指针反转
	}
	L->next = p;  //头结点指向原本最后的一个结点
	return L;
}

/*变成有序递增链表*/
void SortList(LinkList &L)
{
	LNode *pre; //指向排序后的最后一个结点
	LNode *p = L->next;
	LNode *r = p->next;
	p->next = NULL;
	//将第一个结点与第二个结点分割开，从第二个结点开始插入合适位置
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		//先插入比第一个结点值大的结点
		while (pre->next != NULL && p->data > pre->next->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
/*删除值在x和y之间的结点*/
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

/*查找链表中倒数第k个结点*/
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
	printf("倒数第%d的值为：%d\n", k, q->data);
	return 1;
}

/*删除链表中绝对值相同的结点，只保留第一次出现的结点*/
/*结点值的绝对值不大于n*/
LinkList DeleteCommonAbs(LinkList &L, int n)
{
	LNode *p = L->next;
	LNode *pre = L;
	int m;
	//辅助数组，未出现过的结点值的数组值为0
	int *a = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i < n + 1; i++)
	{
		*(a + i) = 0;
	}
	while (pre->next != NULL)
	{
		m = pre->next->data > 0 ? pre->next->data : -pre->next->data;
		if (*(a + m) == 0)  //第一次出现，不做处理
		{
			pre = pre->next;
			*(a + m) = 1;   //数组值置1
		}
		else                //第二次出现，删除
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