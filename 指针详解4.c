#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����ָ������
//����Ķ���:һ�������ͬ�������ݵĴ洢�ռ�

//����ָ������: int* arr[10];
//Ҫ�Ѻ����ĵ�ַ��ŵ�һ��������,���������ͽк���ָ������

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int Sub(int x, int y)
{
	int z = 0;
	z = x - y;
	return z;
}

int Mul(int x, int y)
{
	int z = 0;
	z = x * y;
	return z;
}

int Div(int x, int y)
{
	int z = 0;
	z = x / y;
	return z;
}

int main()
{
	int* arr[5];  //ָ������

    //int (*pa)(int , int) = Add/Sub/Mul/Div
	//���Ҫ���ĸ������ĵ�ַ��������,����Ҫһ���������洢,���������ͱ���Ϊ����ָ������

	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };  //����ָ������
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](2, 3));  //5  -1  6  0
	}

	//int (*parr1[4])();  corr
	//int *parr2[4]();  err
	//int (*)()parr3[10];  err

	return 0;
}


//��ϰ:
char* my_strcpy(char* dest, const char* src);
//1.дһ������ָ��pf,�ܹ�ָ��my_strcpy
//char* (*pf)(char* , const char*)

//2.дһ������ָ������pfArr,�ܹ����4��my_strcpy�����ĵ�ַ
//char* (*pfArr[4])(char*,const char*)


//ʵ�ּ�����
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("**********************************\n");
	printf("****1.Add  2.Sub  3.Mul  4.Div****\n");
	printf("**             0.exit           **\n");
	printf("**********************************\n");
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			printf("%d\n",Add(x,y));
			break;
		case 2:
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}
	while (input);

	return 0;
}


//�򻯴���
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div }; //֮���Ժ���ָ�����鶨��5��������Ҫ�Ͳ˵��е�1,2,3,4��Ӧ����,�Դﵽ���õ��û�����
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if(input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("ѡ�����\n");
		}
	} while (input);

	return 0;
}

//����ָ���������;:ת�Ʊ�,����������һ���ܺõ�����