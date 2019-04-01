#include <stdio.h>
#include <stdlib.h>

/*静态分配*/
#define MaxSize 50  //顺序表的最大长度
typedef struct {
	int data[MaxSize]; //顺序表的元素
	int length;        //顺序表的当前长度
}SqList;

/*动态分配*/
//#define InitSize 100
//typedef struct {
//	int *data;  //动态分配数组的指针
//	int MaxSize, length; //最大容量和当前个数
//}SqList;

/*初始化表*/
void InitList(SqList &L)
{
	L.length = 0;
	printf("初始化成功\n");
}

/*销毁操作*/
void DestroyList(SqList &L)
{
	//free(L.data);
	*L.data = NULL;
	L.length = 0;
	printf("销毁成功\n");
}

/*清空操作*/
void ClearList(SqList &L)
{
	L.length = 0;
	printf("清空成功\n");
}

/*求表长*/
int Length(SqList &L)
{
	if (L.data == NULL)
	{
		return 0;
	}
	else
	{
		return L.length;
	}
}
/*按位查找：查找顺序表第i个元素，即下标为（i-1）的元素*/
int GetElem(SqList &L,int i)
{
	if (i<1 || i>L.length)
	{
		return 0;
	}
	else
	{
		return L.data[i - 1];
	}
}
/*按值查找：在表L中查找值为e的元素的位置*/
int LocateElem(SqList &L,int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}	
	}
}

/*插入操作：将e插入到表L的第i个位置*/
bool ListInsert(SqList &L, int i, int e) {
	if (i<1 || i>L.length + 1)
	{
		printf("插入位置不合法\n");
		return false;
	}
	else if (L.length >= MaxSize)
	{
		printf("顺序表已满\n");
		return false;
	}
	else
	{
		for (int j = L.length; j >= i; j--) //第i个元素及之后元素后移
		{
			L.data[j] = L.data[j - 1];
		}
		L.data[i - 1] = e;
		L.length++;
		printf("插入成功\n");
		return true;
	}

}

/*删除操作：将表L第i个位置的元素删除，并返回元素的值到e*/
bool ListDelete(SqList &L,int i,int &e)
{
	if (L.length < 1)
	{
		printf("表为空\n");
		return false;
	}
	else if (i < 1 || i > L.length)
	{
		printf("删除位置无效\n");
		return false;
	}
	else
	{
		e = L.data[i - 1];
		for (int j = i; j < L.length; j++)
		{
			L.data[j - 1] = L.data[j];
		}
		L.length--;
		printf("删除成功\n");
		return true;
	}

}

/*判空操作*/
bool Empty(SqList &L)
{
	if (L.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*打印表中元素*/
void PrintList(SqList &L)
{
	if (L.length == 0)
	{
		printf("表为空\n");
	}
	else
	{
		printf("表中元素为：\n");
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
}

int main()
{
	SqList L;
	int e;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	PrintList(L);
	printf("表长为：%d\n",Length(L));
	printf("第2个元素为：%d\n",GetElem(L,2));
	printf("元素3在表中的位置为：%d\n",LocateElem(L,3));
	if (ListDelete(L, 1, e))
	{
		printf("删除表中的第1个元素：%d\n", e);
	}
	if (!Empty(L))
	{
		ClearList(L);
	}
	printf("%d\n",L.length);
	DestroyList(L);
	return 0;
}
