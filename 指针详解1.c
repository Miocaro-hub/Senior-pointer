#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//指针的进阶
//1.字符指针
//2.数组指针
//3.指针数组
//4.数组传参和指针传参
//5.函数指针
//6.函数指针数组
//7.指向函数指针数组的指针
//8.回调函数
//9.指针和数组面试题的解析

//指针的概念 ：
/*
 1.指针就是变量,用来存放地址,地址唯一标识一块内存空间
 2.指针的大小是固定的4/8个字节(32位平台/64位平台)
 3.指针是有类型,指针的类型决定了指针的+-整数的步长,指针解引用操作的时候的权限
 4.指针的运算
*/


//字符指针
//在指针的类型中我们知道有一种指针类型为字符指针char*
int main()
{
	char arr[] = "abcdef";
	char* pc = arr;  //这里不是把一个字符串放到pc指针变量里,本质是把字符串abcdef首字符的地址放到了pc中
	
	//const char* pc = arr; const表示指针所指向的内容是常量不可变
	printf("%s\n", arr);
	printf("%s\n", pc); //字符串不需要解引用
	
	/* *pc = 'w';
	printf("%s\n", pc);*/
	//段错误,虽然可以运行出来,但本质上是错误的,常量字符串不可更改

	//SegmentFault

	char* p = "abcdef"; //"abcdef\0"是一个常量字符串
	printf("%c\n", *p);
	printf("%s\n", p);
	return 0;
}


//面试题:
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	const char* p1 = "abcdef";
	const char* p2 = "abcdef"; //常量字符串
	if (arr1 == arr2)
	{
		printf("xixi\n");
	}
	else
	{
		printf("haha\n");
	}
	//不同元素的首元素地址不一样,在不同的空间,肯定不相等

	if (p1 == p2)
	{
		printf("xixi\n");
	}
	else
	{
		printf("haha\n");
	}
	//"abcdef"为常量字符串,无法修改,没有必要分两个地址
	//所以此时的p1,p2指向的是同一块空间
	return 0;
}


//指针数组
//指针数组是一个存放指针的数组
/*
int* arr1[10] - 整型指针数组
char* arr2[4] - 一级字符指针的数组
char** arr3[5] - 二级字符指针的数组
*/

int main()
{
	int arr[10] = { 0 };  //创建一个整型数组
	char ch[5] = { 0 };  //字符数组
	int* ptr[4];  //存放整型指针的数组 - 指针数组
	char* ch[5];  //存放字符指针的数组 - 指针数组
	return 0;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int* arr[4] = { &a,&b,&c,&d };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(arr[i]));
	}
	return 0;
}

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[] = { arr1,arr2,arr3 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}
	return 0;
}