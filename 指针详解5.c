#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ָ����ָ�������ָ����һ��ָ��,ָ��ָ��һ������,�����Ԫ�ض��Ǻ���ָ��
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int a = 10;
	int b = 20;

	int* arr[10]; //ָ������
	int* (*pa)[10] = &arr;  //����ָ��
	int (*pAdd)(int , int) = Add;  //����ָ��

	int sum = (pAdd)(a, b);  //int sum = (*pAdd)(a, b);
	printf("%d\n", sum);

	int(*pArr[5])(int, int);  //����ָ������

	//ָ����ָ�������ָ��
	int(*(*ppArr)[5])(int, int) = &pArr;
	return 0;
}


//�ص�����
/*
�ص���������һ��ͨ������ָ����õĺ���.
����Ѻ�����ָ��(��ַ)��Ϊ�������ݸ���һ������,�����ָ�뱻������������ָ��ĺ���ʱ,�ͱ���Ϊ�ص�����
*/


//qsort�⺯�� - ���������������͵�����
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

void qsort(void* base, size_t num, size_t width, int(*compare)(const void*elem1, const void*elem2)); //qsort����

int cmp_int(const void*elem1, const void*elem2)
{
	//�˺��������Ƚ���������ֵ�ĺ���
}

int main()  //ð��������
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	struct Stu s[3] = { {"����",18},{"����",19},{"����",20} };  //�޷���������,����ʱ��������ͬ,��ʱ��ð������ֻ��������
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
	//void* ���͵�ָ��,���Խ����������͵ĵ�ַ
	return 0;
}