#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�������,ָ�����
//��д����ʱҪ������,����ָ�봫������,�����Ĳ���������

//һά���鴫��
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
	//ok(����ָ��)
}

void test2(int* arr[20])
{
	//ok
}

void test2(int** arr)
{
	//ok(��������д��ָ��)
}

int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test(arr2);
	return 0;
}


//��ά���鴫��
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
	//�в���ʡ��
}

void test(int* arr)
{
	//��λ���鴫�δ���Ԫ�صĵ�ַ,��Ԫ��Ϊ��һ�е�Ԫ��
	//err
}

void test(int* arr[5])
{
	//ָ������,arr��5��Ԫ��,ÿ��Ԫ������Ϊint*
	//err
}

void test(int(*arr)[5])
{
	//����arr��ָ��,arrָ���������5��Ԫ��,ÿ��Ԫ�ص�����Ϊint
	//ok
}
void test(int** arr)
{
	//����ָ��,���һ��ָ������ĵ�ַ
	//�����ָ��û������һ������ָ��
	//err
}

int main()
{
	int arr[3][5] = { 0 };
	test(arr); //��λ���鴫��
	return 0;
}
//�ܽ�:��ά���鴫��,�����βε����ֻ��ʡ�Ե�һ��[]������
//��Ϊ��һ����ά����,���Բ�֪���ж�����,���Ǳ���֪��һ�ж���Ԫ��



//һ��ָ�봫��
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
	print(p, sz);  //һ��ָ��p,��������
	return 0;
}

//˼��:��һ�������Ĳ�������Ϊһ��ָ���ʱ��,�����ܽ���ʲô����
//��:
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


//����ָ�봫��
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

//˼��:��һ�������Ĳ�������Ϊ����ָ���ʱ��,�����ܽ���ʲô����
//��:
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
	test(arr); //ָ�����鴫��Ҳ����
	return 0;
}


//����ָ�� - ָ�������ָ��
//����ָ�� - ָ������ָ��
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
	//&������ �� ���������Ǻ����ĵ�ַ

	int arr[10] = { 0 };
	int(*p)[10] = &arr;

	int(*pa)(int, int) = Add;  //����ָ�� - ��ź�����ַ��ָ�� - ����(* )()
	printf("%d\n", (*pa)(2, 3)); //*pa��ʾ����Add����,*����ʡ��(*��ʾ������),�൱��Add(2, 3)
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


//��C�����ȱ�ݡ�
//��Ȥ�Ĵ���:

//����1; (*(void(*)())0)(); 
//void(*)()��ʾһ������ָ������,(void(*)()) 0,��ʾ��0ǿ������ת���ɺ���ָ������ - 0����һ�������ĵ�ַ,��ǰ���*��ʾ������,����0��ַ���ĸú���

//����2; void(*signal(int , void(*)(int)))(int);
//�����void(*           )(int)Ϊһ������ָ������,�м��signal(int , void(*)(int)),intΪ����,void(*)(int)Ϊ����ָ������,signalΪ������,�������Ϊһ������ָ��

//�򻯴���
//typedef void(*pfun_t)(int);  pfun_t��ʾ����ָ������
//pfun_t signal(int,pfun_t);   ���д����������������˼�ʹ���2������˼һ��

//typedf����ʹ�ò���
//ʾ��1:
//int a; �������� ��ͳ�����������ʽ
//int pfun_t; �������� ʹ���µ�������pfun_t;�滻������a
//typedef int pfun_t;; �������� ����俪ͷ����typedef�ؼ��֣�pfun_t;�������Ƕ����������(����)

//ʾ��2:
//void (*p)(int); �������� ��ͳ�������������������ʽ
//void (*pfun_a)(int); �������� ʹ���µ�������pfun_a�滻������p
//typedef void (*pfun_a)(int); �������� ����俪ͷ����typedef�ؼ��֣�pfun_a�������Ƕ����������(����ָ������)