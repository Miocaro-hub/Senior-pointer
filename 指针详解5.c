#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void Bubble_Sort(int arr[], int sz)  //只能用于整型的比较
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

//void qsort(void* base, size_t num, size_t width, int(*compare)(const void*elem1, const void*elem2));   //qsort函数
//第一个参数:待排序数组的首元素地址
//第二个参数:待排序数组的元素个数
//第三个参数:待排序数组的每个元素的大小 - 单位是字节
//第四个参数:是函数指针,比较两个元素的所用的函数的地址(使用者自己实现)
//           函数指针的两个参数是:待比较的两个元素的地址

int cmp_int(const void*elem1, const void*elem2)
{
	//此函数用来比较两个整型值的函数
	return *(int*)elem1 - *(int*)elem2;  //强制类型转换为int*
}

int cmp_float(const void*elem1, const void*elem2)
{
	//也可以用来比较两个浮点型值的函数
	return *(float*)elem1 - *(float*)elem2;
	//return ((int)(*(float*)elem1 - *(float*)elem2));
}


/*-------------------------------------------------------------*/


//结构体排序
int cmp_stu_by_age(const void*elem1,const void*elem2)
{
	return （(struct Stu*)elem1）->age - （(struct Stu*)elem2）->age;

}

int cmp_stu_by_name(const void*elem1, const void*elem2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用<>=来比较,应该用strcmp函数
	//strcmp函数是string compare(字符串比较)的缩写,用于比较两个字符串并根据比较结果返回整数
	//基本形式为strcmp(str1,str2),若str1=str2,则返回零;若str1<str2,则返回负数;若str1>str2,则返回正数
    return strcmp(（(struct Stu*)elem1）->name , （(struct Stu*)elem2）->name)
}

void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++
	}
}

void bubble_sort(void*base, int sz, int width,int(*cmp)(void* elem1,void* elem2))
{
	int i = 0;  
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素比较
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0)
			{
				//交换元素
				Swap((char*)base + j * width, (char*)base + (j + 1)*width,width);
			}
		}
	}
}

void test()
{
	struct Stu s[3] = { {{"张三",18},{"李四",19},{"王五",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qosort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	//qosort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}

int main()  //冒泡排序函数
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	struct Stu s[3] = { {"张三",18},{"李四",19},{"王五",20} };  //无法进行排序,传参时的类型相同,此时的冒泡排序只能排整型
	qsort(arr,sz,sizeof(arr[0]),cmp_int);

	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
	qsort(f, sz, sizeof(f[0]), cmp_float);
	Bubble_Sort(arr, sz);
	

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}


/*---------------------------------------------------*/
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
