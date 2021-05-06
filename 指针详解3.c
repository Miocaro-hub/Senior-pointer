#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//数组参数,指针参数
//在写代码时要把数组,或者指针传给函数,函数的参数如何设计

//一维数组传参
void test(int arr[])
{
	//ok
}

void test(int arr[10])
{
	//ok
}

void test(int* arr)
{
	//ok(数组指针)
}

void test2(int* arr[20])
{
	//ok
}

void test2(int** arr)
{
	//ok(参数部分写成指针)
}

int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test(arr2);
	return 0;
}


//二维数组传参
void test(int arr[3][5])
{
	//ok
}

void test(int arr[][5])
{
	//ok
}

void test(int arr[3][])
{
	//err
	//行不能省略
}

void test(int* arr)
{
	//二位数组传参传首元素的地址,首元素为第一行的元素
	//err
}

void test(int* arr[5])
{
	//指针数组,arr有5个元素,每个元素类型为int*
	//err
}

void test(int(*arr)[5])
{
	//首先arr做指针,arr指向的数组有5个元素,每个元素的类型为int
	//ok
}
void test(int** arr)
{
	//二级指针,存放一级指针变量的地址
	//数组的指针没法放在一个二级指针
	//err
}

int main()
{
	int arr[3][5] = { 0 };
	test(arr); //二位数组传参
	return 0;
}
//总结:二维数组传参,函数形参的设计只能省略第一个[]的数字
//因为对一个二维数组,可以不知道有多少行,但是必须知道一行多少元素



//一级指针传参
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *(p + i));
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(p, sz);  //一级指针p,传给参数
	return 0;
}

//思考:当一个函数的参数部分为一级指针的时候,函数能接收什么参数
//例:
void test1(int* p)
{

}

void test2(char* p)
{

}

int main()
{
	int a = 10;
	int* p1 = &a;
	test1(&a);//ok
	test1(p1);//ok

	char ch = 'w';
	char* pc = &ch;
	test2(&ch);
	test2(pc);
	return 0;
}


//二级指针传参
void test(int** ptr)
{
	print("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);
	test(&p);
	return 0;
}

//思考:当一个函数的参数部分为二级指针的时候,函数能接收什么参数
//例:
void test(int** p)
{

}
int main()
{
	int* ptr;
	int** ppc = &ptr;
	test(&ptr);
	test(ppc);

	int* arr[10];
	test(arr); //指针数组传参也可以
	return 0;
}


//数组指针 - 指向数组的指针
//函数指针 - 指向函数的指针
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("%d\n", Add(a, b));

	//printf("%p\n", &Add);
	//printf("%p\n", Add);
	//&函数名 和 函数名都是函数的地址

	int arr[10] = { 0 };
	int(*p)[10] = &arr;

	int(*pa)(int, int) = Add;  //函数指针 - 存放函数地址的指针 - 类型(* )()
	printf("%d\n", (*pa)(2, 3)); //*pa表示引用Add函数,*可以省略(*表示解引用),相当于Add(2, 3)
	return 0;
}


void Print(char*str)
{
	printf("%s\n", str);
}
int main()
{
	void(*p)(char*) = Print;
	(*p)("hello world");
	return 0;
}


//《C陷阱和缺陷》
//有趣的代码:

//代码1; (*(void(*)())0)(); 
//void(*)()表示一个函数指针类型,(void(*)()) 0,表示将0强制类型转换成函数指针类型 - 0就是一个函数的地址,最前面的*表示解引用,调用0地址处的该函数

//代码2; void(*signal(int , void(*)(int)))(int);
//整体的void(*           )(int)为一个函数指针类型,中间的signal(int , void(*)(int)),int为整型,void(*)(int)为函数指针类型,signal为函数名,整体代码为一个函数指针

//简化代码
//typedef void(*pfun_t)(int);  pfun_t表示函数指针类型
//pfun_t signal(int,pfun_t);   两行代码合起来所表达的意思和代码2表达的意思一致

//typedf具体使用步骤
//示例1:
//int a; ———— 传统变量声明表达式
//int pfun_t; ———— 使用新的类型名pfun_t;替换变量名a
//typedef int pfun_t;; ———— 在语句开头加上typedef关键字，pfun_t;就是我们定义的新类型(整型)

//示例2:
//void (*p)(int); ———— 传统变量（函数）声明表达式
//void (*pfun_a)(int); ———— 使用新的类型名pfun_a替换变量名p
//typedef void (*pfun_a)(int); ———— 在语句开头加上typedef关键字，pfun_a就是我们定义的新类型(函数指针类型)