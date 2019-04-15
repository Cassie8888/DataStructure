#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50                          //˳������󳤶�
typedef struct {
	int data[MaxSize];                      //˳����Ԫ��
	int length;                             //˳���ĵ�ǰ����
}SqList;

void InitList(SqList &L);                    //��ʼ����
bool ListInsert(SqList &L, int i, int e);    //�����������e���뵽��L�ĵ�i��λ��
void CreateList(SqList &L);                  //����˳���
bool DeleteSmallest(SqList &L, int &min);    //ɾ��������С��Ԫ�أ��ճ���λ�������һ��Ԫ���
void DeleteX(SqList &L, int x);              //ɾ������ֵΪx��Ԫ�أ�ʹʱ�临�Ӷ�ΪO(n)
bool DeleteST(SqList &L, int s, int t);      //ɾ��ֵ��(s,t)֮���Ԫ��
bool DeleteSame(SqList &L);                  //ɾ���������ֵ�ظ���Ԫ��
void PrintList(SqList &L);                   //��ӡ����Ԫ��
bool ListReverse(SqList &L, int m, int n);   //����˳����m������n��Ԫ��Ԫ��
bool ListExchange(SqList &L, int m, int n);  //����[0,m-1]��Ԫ�����[m,m+n-1]��Ԫ�ؽ���
void SearchExchange(SqList &L, int x);       //��������в���ֵΪx��Ԫ�ز�����Ԫ�ؽ������Ҳ��������x��ʹ��������
int ListMiddle(SqList& L, SqList &Q);        //�������ȳ��������е���λ��
void ListMajority(SqList &L);                //����˳�������ֵͬ����������һ���Ԫ��
int FindMinPositive(SqList &L);              //����˳�����δ���ֵ���С����������Ҫ��ʱ���Ч

/*��ʼ����*/
void InitList(SqList &L)
{
	L.length = 0;
	printf("��ʼ���ɹ�\n");
}
/*�����������e���뵽��L�ĵ�i��λ��*/
bool ListInsert(SqList &L, int i, int e) {
	if (i<1 || i>L.length + 1)
	{
		printf("����λ�ò��Ϸ�\n");
		return false;
	}
	else if (L.length >= MaxSize)
	{
		printf("˳�������\n");
		return false;
	}
	else
	{
		for (int j = L.length; j >= i; j--) //��i��Ԫ�ؼ�֮��Ԫ�غ���
		{
			L.data[j] = L.data[j - 1];
		}
		L.data[i - 1] = e;
		L.length++;
		printf("����ɹ�\n");
		return true;
	}

}
/*����˳���*/
void CreateList(SqList &L)
{
	printf("����˳����ֵ����-1������\n");
	int x = 0;
	int i = 1;
	scanf("%d", &x);
	while (x != -1)
	{
		ListInsert(L, i, x);
		i++;
		scanf("%d", &x);
	}
	printf("˳������ɹ���\n");
}
/*ɾ��������С��Ԫ�أ��ճ���λ�������һ��Ԫ���*/
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
/*ɾ������ֵΪx��Ԫ�أ�ʹʱ�临�Ӷ�ΪO(n)*/
void DeleteX(SqList &L, int x)
{
	printf("ɾ��ֵΪ%d��Ԫ��\n", x);
	int k = 0;//��k����¼ֵΪx��Ԫ��
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x) 
		{
			k++;//����ֵΪx��Ԫ��
		}
		else
		{
			L.data[i - k] = L.data[i];//��ǰ�ƶ�k��Ԫ��
		}
	}
	L.length = L.length - k;
}
/*ɾ��ֵ��(s,t)֮���Ԫ��*/
bool DeleteST(SqList &L, int s, int t)
{
	printf("ɾ��ֵ��%d��%d֮���Ԫ��\n", s, t);
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
/*ɾ���������ֵ�ظ���Ԫ��*/
//��Ϊ�������������ֵͬ��Ԫ�ػ���һ��
bool DeleteSame(SqList &L)
{
	printf("ɾ��������ֵͬ��Ԫ�أ�\n");
	//���ù���ָ��j
	int i = 0;
	int j = 1;
	if (L.length == 0)
	{
		return false;
	}
	for (i = 0, j = 1; j < L.length; j++)
	{
		//�ҵ���һ����data[i]����ͬ��Ԫ��ǰ��
		if (L.data[i] != L.data[j])
		{
			i++;
			L.data[i] = L.data[j];
		}
	}
	L.length = i+1;
	return true;
}
/*��ӡ����Ԫ��*/
void PrintList(SqList &L)
{
	if (L.length == 0)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		printf("����Ԫ��Ϊ��\n");
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
}
/*����˳���Ԫ��*/
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
/*����[0,m-1]��Ԫ�����[m,m+n-1]��Ԫ�ؽ���*/
//(a1,...am)��(b1,...bn)
bool ListExchange(SqList &L, int m, int n)
{
	//��˳���ȫ�����ã���Ϊ(bn,...,b1,am,...,a1)
	ListReverse(L, 0, m+n-1);
	//��(bn,...,b1)���ñ�Ϊ(b1,...bn,am,...,a1)
	ListReverse(L, 0, n-1);
	//��(am,...,a1)���ñ�Ϊ(b1,...bn,a1,...am)
	ListReverse(L, n, n+m-1);
	return true;
}
/*��������в���ֵΪx��Ԫ�ز�����Ԫ�ؽ������Ҳ��������x��ʹ��������*/
void SearchExchange(SqList &L, int x)
{
	int low, high, mid;
	low = 0;
	high = L.length - 1;
	//ʹ���۰���ҷ��ҵ���xֵ��ͬ��Ԫ��
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
	//���ҵ�����L.data[mid]Ϊ�����ҵ�Ԫ�ء������������һ��Ԫ�أ���Ϊ��������Ԫ�ؽ���
	if (L.data[mid] == x&&mid != L.length-1)
	{
		int temp = L.data[mid];
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = temp;
		printf("�Ѳ��ҵ�ֵΪ%d��Ԫ�أ�����������Ԫ�ؽ�����\n",x);
	}
	//��δ�ҵ��������x
	else 
	{
		//x��λ��Ӧ��high֮��
		int i;
		for (i = L.length - 1; i > high; i--)
		{
			//��������Ԫ��
			L.data[i + 1] = L.data[i];
		}
		L.data[i + 1] = x;
		L.length++;
		printf("δ���ҵ�ֵΪ%d��Ԫ�أ��ѽ������˳���\n",x);
	}
}
/*�������ȳ��������е���λ��*/
int ListMiddle(SqList& L, SqList &Q)
{
	printf("������������λ��Ϊ��\n");
	//����˳������βԪ�ؼ���λ��
	int sl = 0, el = L.length - 1, ml;
	int sq = 0, eq = Q.length - 1, mq;
	while (sl != el || sq != eq)
	{
		ml = (sl + el) / 2;
		mq = (sq + eq) / 2;
		//���������е���λ�����
		if (L.data[ml] == Q.data[mq])
		{
			return L.data[ml];
		}
		if (L.data[ml] < Q.data[mq])
		{
			//Ԫ�ظ���Ϊ����
			if ((sl + el) % 2 == 0)
			{
				//����ml֮ǰ��Ԫ�غ�mq֮���Ԫ��
				sl = ml;
				eq = mq;
			}
			//Ԫ�ظ���Ϊż��
			else
			{
				//����ml��ml֮ǰ��Ԫ�غ�mq֮���Ԫ��
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
/*����˳�������ֵͬ����������һ���Ԫ��*/
void ListMajority(SqList &L)
{
	int m = L.data[0];
	int count = 1;
	//���ҿ���Ϊ��Ԫ�صĿ���ֵ
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
		printf("˳������Ԫ��Ϊ��%d\n", m);
	}
	else
	{
		printf("Error with -1!\n");
	}
}
/*����˳�����δ���ֵ���С����������Ҫ��ʱ���Ч*/
//Ҫ��ʱ���Ч���ÿռ任ʱ��
int FindMinPositive(SqList &L)
{
	//˳����������L.length����ֵͬ��Ԫ��
	//����B[0,...,L.length-1]
	printf("˳�����δ���ֵ���С������Ϊ��");
	int i;
	int *B = (int *)malloc(sizeof(int)*L.length);
	memset(B, 0, sizeof(int)*L.length);
	for (i = 0; i < L.length; i++)
	{
		//��������Ԫ�أ���Ϊ��������������B����Ӧ��ֵ��0��Ϊ1
		if (L.data[i] > 0 && L.data[i] <= L.length)
		{
			B[L.data[i] - 1] = 1;
		}
	}
	//��������B�е�һ��ֵΪ0�������±�
	for (i = 0; i < L.length; i++)
	{
		if (B[i] == 0)
			break;
	}
	//1��ӦB[0],���Ӧ��һ
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