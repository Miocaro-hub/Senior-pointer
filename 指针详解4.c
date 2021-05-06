#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//函数指针数组
//数组的定义:一个存放相同类型数据的存储空间

//例如指针数组: int* arr[10];
//要把函数的地址存放到一个数组中,那这个数组就叫函数指针数组

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
	int* arr[5];  //指针数组

    //int (*pa)(int , int) = Add/Sub/Mul/Div
	//如果要把四个函数的地址都存起来,就需要一个数组来存储,而这个数组就被称为函数指针数组

	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };  //函数指针数组
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


//练习:
char* my_strcpy(char* dest, const char* src);
//1.写一个函数指针pf,能够指向my_strcpy
//char* (*pf)(char* , const char*)

//2.写一个函数指针数组pfArr,能够存放4个my_strcpy函数的地址
//char* (*pfArr[4])(char*,const char*)


//实现计算器
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n",Add(x,y));
			break;
		case 2:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x, y));
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}
	while (input);

	return 0;
}


//简化代码
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div }; //之所以函数指针数组定义5个函数是要和菜单中的1,2,3,4对应起来,以达到更好的用户体验
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if(input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误\n");
		}
	} while (input);

	return 0;
}

//函数指针数组的用途:转移表,计算器就是一个很好的例子