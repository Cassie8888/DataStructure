#include <stdio.h>
#include <stdlib.h>

/*��̬����*/
#define MaxSize 50  //˳������󳤶�
typedef struct {
	int data[MaxSize]; //˳����Ԫ��
	int length;        //˳���ĵ�ǰ����
}SqList;

/*��̬����*/
//#define InitSize 100
//typedef struct {
//	int *data;  //��̬���������ָ��
//	int MaxSize, length; //��������͵�ǰ����
//}SqList;

/*��ʼ����*/
void InitList(SqList &L)
{
	L.length = 0;
	printf("��ʼ���ɹ�\n");
}

/*���ٲ���*/
void DestroyList(SqList &L)
{
	//free(L.data);
	*L.data = NULL;
	L.length = 0;
	printf("���ٳɹ�\n");
}

/*��ղ���*/
void ClearList(SqList &L)
{
	L.length = 0;
	printf("��ճɹ�\n");
}

/*���*/
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
/*��λ���ң�����˳����i��Ԫ�أ����±�Ϊ��i-1����Ԫ��*/
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
/*��ֵ���ң��ڱ�L�в���ֵΪe��Ԫ�ص�λ��*/
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

/*ɾ������������L��i��λ�õ�Ԫ��ɾ����������Ԫ�ص�ֵ��e*/
bool ListDelete(SqList &L,int i,int &e)
{
	if (L.length < 1)
	{
		printf("��Ϊ��\n");
		return false;
	}
	else if (i < 1 || i > L.length)
	{
		printf("ɾ��λ����Ч\n");
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
		printf("ɾ���ɹ�\n");
		return true;
	}

}

/*�пղ���*/
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

int main()
{
	SqList L;
	int e;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	PrintList(L);
	printf("��Ϊ��%d\n",Length(L));
	printf("��2��Ԫ��Ϊ��%d\n",GetElem(L,2));
	printf("Ԫ��3�ڱ��е�λ��Ϊ��%d\n",LocateElem(L,3));
	if (ListDelete(L, 1, e))
	{
		printf("ɾ�����еĵ�1��Ԫ�أ�%d\n", e);
	}
	if (!Empty(L))
	{
		ClearList(L);
	}
	printf("%d\n",L.length);
	DestroyList(L);
	return 0;
}
