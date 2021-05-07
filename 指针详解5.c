#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//指向函数指针数组的指针是一个指针,指针指向一个数组,数组的元素都是函数指针
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 10;
	int b = 20;

	int* arr[10]; //指针数组
	int* (*pa)[10] = &arr;  //数组指针
	int (*pAdd)(int , int) = Add;  //函数指针

	int sum = (pAdd)(a, b);  //int sum = (*pAdd)(a, b);
	printf("%d\n", sum);

	int(*pArr[5])(int, int);  //函数指针数组

	//指向函数指针数组的指针
	int(*(*ppArr)[5])(int, int) = &pArr;
	return 0;
}


//回调函数
/*
回调函数就是一个通过函数指针调用的函数.
如果把函数的指针(地址)作为参数传递给另一个函数,当这个指针被用来调用其所指向的函数时,就被称为回调函数
*/


//qsort库函数 - 可以排序任意类型的数据
void Bubble_Sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

struct stu
{
	char name[20];
	int age;
};

void qsort(void* base, size_t num, size_t width, int(*compare)(const void*elem1, const void*elem2)); //qsort函数

int cmp_int(const void*elem1, const void*elem2)
{
	//此函数用来比较两个整型值的函数
}

int main()  //冒泡排序函数
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	struct Stu s[3] = { {"张三",18},{"李四",19},{"王五",20} };  //无法进行排序,传参时的类型相同,此时的冒泡排序只能排整型
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	Bubble_Sort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}


/*-------------------------*/
int main()
{
	int a = 10;
	int* pa = &a;
	//char* pc = &a err
	char ch = 'w';
	void* p = &a;  //corr
	p = &ch;
	//void* 类型的指针,可以接收任意类型的地址
	return 0;
}