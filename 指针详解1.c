#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ָ��Ľ���
//1.�ַ�ָ��
//2.����ָ��
//3.ָ������
//4.���鴫�κ�ָ�봫��
//5.����ָ��
//6.����ָ������
//7.ָ����ָ�������ָ��
//8.�ص�����
//9.ָ�������������Ľ���

//ָ��ĸ��� ��
/*
 1.ָ����Ǳ���,������ŵ�ַ,��ַΨһ��ʶһ���ڴ�ռ�
 2.ָ��Ĵ�С�ǹ̶���4/8���ֽ�(32λƽ̨/64λƽ̨)
 3.ָ����������,ָ������;�����ָ���+-�����Ĳ���,ָ������ò�����ʱ���Ȩ��
 4.ָ�������
*/


//�ַ�ָ��
//��ָ�������������֪����һ��ָ������Ϊ�ַ�ָ��char*
int main()
{
	char arr[] = "abcdef";
	char* pc = arr;  //���ﲻ�ǰ�һ���ַ����ŵ�pcָ�������,�����ǰ��ַ���abcdef���ַ��ĵ�ַ�ŵ���pc��
	
	//const char* pc = arr; const��ʾָ����ָ��������ǳ������ɱ�
	printf("%s\n", arr);
	printf("%s\n", pc); //�ַ�������Ҫ������
	
	/* *pc = 'w';
	printf("%s\n", pc);*/
	//�δ���,��Ȼ�������г���,���������Ǵ����,�����ַ������ɸ���

	//SegmentFault

	char* p = "abcdef"; //"abcdef\0"��һ�������ַ���
	printf("%c\n", *p);
	printf("%s\n", p);
	return 0;
}


//������:
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	const char* p1 = "abcdef";
	const char* p2 = "abcdef"; //�����ַ���
	if (arr1 == arr2)
	{
		printf("xixi\n");
	}
	else
	{
		printf("haha\n");
	}
	//��ͬԪ�ص���Ԫ�ص�ַ��һ��,�ڲ�ͬ�Ŀռ�,�϶������

	if (p1 == p2)
	{
		printf("xixi\n");
	}
	else
	{
		printf("haha\n");
	}
	//"abcdef"Ϊ�����ַ���,�޷��޸�,û�б�Ҫ��������ַ
	//���Դ�ʱ��p1,p2ָ�����ͬһ��ռ�
	return 0;
}


//ָ������
//ָ��������һ�����ָ�������
/*
int* arr1[10] - ����ָ������
char* arr2[4] - һ���ַ�ָ�������
char** arr3[5] - �����ַ�ָ�������
*/

int main()
{
	int arr[10] = { 0 };  //����һ����������
	char ch[5] = { 0 };  //�ַ�����
	int* ptr[4];  //�������ָ������� - ָ������
	char* ch[5];  //����ַ�ָ������� - ָ������
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