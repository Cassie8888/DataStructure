#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50                          //顺序表的最大长度
typedef struct {
	int data[MaxSize];                      //顺序表的元素
	int length;                             //顺序表的当前长度
}SqList;

void InitList(SqList &L);                    //初始化表
bool ListInsert(SqList &L, int i, int e);    //插入操作：将e插入到表L的第i个位置
void CreateList(SqList &L);                  //创建顺序表
bool DeleteSmallest(SqList &L, int &min);    //删除表中最小的元素，空出的位置由最后一个元素填补
void DeleteX(SqList &L, int x);              //删除所有值为x的元素，使时间复杂度为O(n)
bool DeleteST(SqList &L, int s, int t);      //删除值在(s,t)之间的元素
bool DeleteSame(SqList &L);                  //删除有序表中值重复的元素
void PrintList(SqList &L);                   //打印表中元素
bool ListReverse(SqList &L, int m, int n);   //逆置顺序表第m个至第n个元素元素
bool ListExchange(SqList &L, int m, int n);  //将第[0,m-1]个元素与第[m,m+n-1]个元素交换
void SearchExchange(SqList &L, int x);       //在有序表中查找值为x的元素并与后继元素交换；找不到则插入x，使表仍有序
int ListMiddle(SqList& L, SqList &Q);        //求两个等长升序序列的中位数
void ListMajority(SqList &L);                //查找顺序表中相同值个数超过表长一般的元素
int FindMinPositive(SqList &L);              //查找顺序表中未出现的最小的正整数，要求时间高效

/*初始化表*/
void InitList(SqList &L)
{
	L.length = 0;
	printf("初始化成功\n");
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
/*创建顺序表*/
void CreateList(SqList &L)
{
	printf("输入顺序表的值，以-1结束：\n");
	int x = 0;
	int i = 1;
	scanf("%d", &x);
	while (x != -1)
	{
		ListInsert(L, i, x);
		i++;
		scanf("%d", &x);
	}
	printf("顺序表创建成功！\n");
}
/*删除表中最小的元素，空出的位置由最后一个元素填补*/
bool DeleteSmallest(SqList &L, int &min)
{
	min = L.data[0];
	int count = 0;
	if (L.length == 0)
	{
		printf("error");
		return false;
	}
	else
	{
		for (int i = 0; i < L.length; i++)
		{
			if (L.data[i] < min)
			{
				min = L.data[i];
				count = i;
			}
		}
		L.data[count] = L.data[L.length - 1];
		L.length--;
		return true;
	}
}
/*删除所有值为x的元素，使时间复杂度为O(n)*/
void DeleteX(SqList &L, int x)
{
	printf("删除值为%d的元素\n", x);
	int k = 0;//用k来记录值为x的元素
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x) 
		{
			k++;//舍弃值为x的元素
		}
		else
		{
			L.data[i - k] = L.data[i];//向前移动k个元素
		}
	}
	L.length = L.length - k;
}
/*删除值在(s,t)之间的元素*/
bool DeleteST(SqList &L, int s, int t)
{
	printf("删除值在%d到%d之间的元素\n", s, t);
	int k = 0;
	if (L.length == 0 || s >= t)
	{
		return false;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i]<t && L.data[i]>s)
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
	}
	L.length = L.length - k;
	return true;
}
/*删除有序表中值重复的元素*/
//因为是有序表，所以相同值的元素会在一起
bool DeleteSame(SqList &L)
{
	printf("删除表中相同值的元素：\n");
	//设置工作指针j
	int i = 0;
	int j = 1;
	if (L.length == 0)
	{
		return false;
	}
	for (i = 0, j = 1; j < L.length; j++)
	{
		//找到下一个与data[i]不相同的元素前移
		if (L.data[i] != L.data[j])
		{
			i++;
			L.data[i] = L.data[j];
		}
	}
	L.length = i+1;
	return true;
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
/*逆置顺序表元素*/
bool ListReverse(SqList &L, int m, int n)
{
	int temp;
	int mid = (int)(m + n + 1) / 2;
	if (m >= n || n > L.length)
	{
		return false;
	}
	for (int i = m; i < mid; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[m + n - i];
		L.data[m + n - i] = temp;
	}
	return true;
}
/*将第[0,m-1]个元素与第[m,m+n-1]个元素交换*/
//(a1,...am)与(b1,...bn)
bool ListExchange(SqList &L, int m, int n)
{
	//将顺序表全部倒置，变为(bn,...,b1,am,...,a1)
	ListReverse(L, 0, m+n-1);
	//将(bn,...,b1)倒置变为(b1,...bn,am,...,a1)
	ListReverse(L, 0, n-1);
	//将(am,...,a1)倒置变为(b1,...bn,a1,...am)
	ListReverse(L, n, n+m-1);
	return true;
}
/*在有序表中查找值为x的元素并与后继元素交换，找不到则插入x，使表仍有序*/
void SearchExchange(SqList &L, int x)
{
	int low, high, mid;
	low = 0;
	high = L.length - 1;
	//使用折半查找法找到与x值相同的元素
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.data[mid] == x)
		{
			break;
		}	
		else if (x < L.data[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	//若找到，则L.data[mid]为所查找的元素。但不能是最后一个元素，因为不能与后继元素交换
	if (L.data[mid] == x&&mid != L.length-1)
	{
		int temp = L.data[mid];
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = temp;
		printf("已查找到值为%d的元素，并将其与后继元素交换！\n",x);
	}
	//若未找到，则插入x
	else 
	{
		//x的位置应在high之后
		int i;
		for (i = L.length - 1; i > high; i--)
		{
			//后移其他元素
			L.data[i + 1] = L.data[i];
		}
		L.data[i + 1] = x;
		L.length++;
		printf("未查找到值为%d的元素，已将其插入顺序表！\n",x);
	}
}
/*求两个等长升序序列的中位数*/
int ListMiddle(SqList& L, SqList &Q)
{
	printf("两个升序表的中位数为：\n");
	//两个顺序表的首尾元素及中位数
	int sl = 0, el = L.length - 1, ml;
	int sq = 0, eq = Q.length - 1, mq;
	while (sl != el || sq != eq)
	{
		ml = (sl + el) / 2;
		mq = (sq + eq) / 2;
		//若两个序列的中位数相等
		if (L.data[ml] == Q.data[mq])
		{
			return L.data[ml];
		}
		if (L.data[ml] < Q.data[mq])
		{
			//元素个数为奇数
			if ((sl + el) % 2 == 0)
			{
				//舍弃ml之前的元素和mq之后的元素
				sl = ml;
				eq = mq;
			}
			//元素个数为偶数
			else
			{
				//舍弃ml及ml之前的元素和mq之后的元素
				sl = ml + 1;
				eq = mq;
			}
		}
		else
		{
			if ((sq + eq) % 2 == 0)
			{
				sq = mq;
				el = ml;
			}
			else
			{
				sq = mq + 1;
				el = ml;
			}
		}
	}
	return L.data[sl] < Q.data[sq] ? L.data[sl] : Q.data[sq];
}
/*查找顺序表中相同值个数超过表长一般的元素*/
void ListMajority(SqList &L)
{
	int m = L.data[0];
	int count = 1;
	//查找可能为主元素的可能值
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] == m)
			count++;
		else
		{
			if (count > 0)
				count--;
			else 
			{
				m = L.data[i];
				count = 1;
			}
		}
	}
	if (count > 0)
	{
		count = 0;
		for (int i = 0; i < L.length; i++)
		{
			if (L.data[i] == m)
			{
				count++;
			}
		}
	}
	if (count > L.length / 2)
	{
		printf("顺序表的主元素为：%d\n", m);
	}
	else
	{
		printf("Error with -1!\n");
	}
}
/*查找顺序表中未出现的最小的正整数，要求时间高效*/
//要求时间高效，用空间换时间
int FindMinPositive(SqList &L)
{
	//顺序表中最多有L.length个不同值的元素
	//数组B[0,...,L.length-1]
	printf("顺序表中未出现的最小正整数为：");
	int i;
	int *B = (int *)malloc(sizeof(int)*L.length);
	memset(B, 0, sizeof(int)*L.length);
	for (i = 0; i < L.length; i++)
	{
		//遍历表中元素，若为正整数，则将数组B中相应的值由0置为1
		if (L.data[i] > 0 && L.data[i] <= L.length)
		{
			B[L.data[i] - 1] = 1;
		}
	}
	//查找数组B中第一个值为0的数组下标
	for (i = 0; i < L.length; i++)
	{
		if (B[i] == 0)
			break;
	}
	//1对应B[0],结果应加一
	return i + 1;
}

int main()
{
	SqList L;
	//SqList Q;
	//int e;
	InitList(L);
	CreateList(L);
	//InitList(Q);
	//CreateList(Q);
	//DeleteSmallest(L, e);
	PrintList(L);
	//PrintList(Q);
	//ListReverse(L,0,7);
	//DeleteX(L, 0);
	//PrintList(L);
	//DeleteST(L, 2, 5);
	//DeleteSame(L);
	//ListExchange(L, 3, 4);
	//SearchExchange(L, 5);
	/*int mid = ListMiddle(L, Q);
	printf("%d\n", mid);*/
	//ListMajority(L);
	int min = FindMinPositive(L);
	printf("%d\n", min);
	PrintList(L);
}