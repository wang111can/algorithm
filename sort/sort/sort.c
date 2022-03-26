#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"Stack.h"

void TnsertSort (int* arr, int n)//插入排序
{
	for (int i = 0; i < n - 1; i++)
	{	
		int end = i;
		int tmp = arr[end + 1];
		while (end)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}
//shellsort希尔
void ShellSort(int* arr, int n)
{	
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}

}
//堆排序
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void RootSort(int* x,int n,int root)
{
	int pread = root;
	int child = root * 2 + 1;//左孩子
	while (child < n)
	{
		if (child < n - 1 && x[child + 1] >x[child])//防止右孩子越界
		{
			child += 1;//指向较小的孩子
		}
		if (x[pread] <x[child])
		{
			Swap(&x[pread], &x[child]);
			pread = child;
			child = pread * 2 + 1;
		}
		else
			break;
	}

}
void StackSort(int* x, int n)
{
	
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		RootSort(x, n, i);
	}
		
		
		int end = n - 1;
		while (end > 0)
		{
			Swap(&x[0], &x[end]);
			RootSort(x, end, 0);
			end--;
		}
}
//坑快排
//////////////////////////////////////

//左右指针法
int Sort2(int* a, int left, int right)
{
	int key = left;
	int cur = left + 1, prev = left;
	while (cur <= right)
	{
		if (++prev!=cur&&a[cur] <a[key])
		{
			++prev;
			Swap(&a[cur], &a[prev]);
		}
		++cur;

	}
	Swap(&a[key], &a[prev]);
	return prev;
}
int Sort3(int* a, int left, int right)//前后指针
{
	
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <=right)
	{
		if (a[cur] < a[key])
		{
			++prev;
			
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

//挖坑法
int Sort1(int* a, int left, int right)
{
	int end = right;
	int begin = left;
	int pit = begin;
	int key = a[begin];
	while (begin < end)
	{

		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pit] = a[end];
		pit = end;
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	pit = begin;
	a[pit] = key;
	return pit;
}

void QSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	
	int pit = Sort3(a, left, right);
	QSort(a, left, pit - 1);
	QSort(a, pit + 1, right);
}

//

//双指针挖坑
//


//归并


void _GSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >>1;
	_GSort(a, left, mid, tmp);
	_GSort(a, mid + 1, right, tmp);
	int l1 = left, l2 = mid;
	int j1 = mid + 1, j2 = right;
	int begin = left;
	while (l1 <= l2 && j1 <= j2)
	{
		if (a[l1] < a[j1])
		{
			tmp[begin++] = a[l1++];
		}
		else
		{
			tmp[begin++] = a[j1++];
		}
	}
	while (l1 <= l2)
	{

		tmp[begin++] = a[l1++];
	}
	while (j1 <= j2)
	{
		tmp[begin++] = a[j1++];

	}
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
void GSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_GSort(a, 0, n - 1, tmp);
	free(tmp);
}
//非递归快排//数据结构栈结构
void RecuQsort(int *c,int n)
{

	Tc a;
	InitStack(&a);
	AddStack(&a, n-1);//先排左，先入右
	AddStack(&a, 0);
	
	while (PanStack(&a) != -1)
	{
		int left = TopStack(&a);
		PanStack(&a);
		int right = TopStack(&a);
		PanStack(&a);
		int key=Sort2(c, left, right);
		//[left,key-1] [key+1,right-1]
		if (right > key+1)
		{
			AddStack(&a, right);
			AddStack(&a, key-1);

		}
		if (left < key - 1)
		{
			AddStack(&a, key-1);
			AddStack(&a, left);
		}



	}


DesStack(&a);


}




//非递归归并
void RecuSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;
	int gap = 1;
	while (gap < n)
	{


		for (int i = 0; i < n; i += 2 * gap)
		{
			int l1 = i, l2 = i+gap-1;
			int j1 = i+ gap, j2 = i+2*gap-1;
			int begin = i;
			if (j1 >= n)//右半区间不存在
				break;
			if (j2 >= n)//右半区间不够大
				j2 = n - 1;
				while (l1 <= l2 && j1 <= j2)
			{
				if (a[l1] < a[j1])
				{
					tmp[begin++] = a[l1++];
				}
				else
				{
					tmp[begin++] = a[j1++];
				}
			}
			while (l1 <= l2)
			{

				tmp[begin++] = a[l1++];
			}
			while (j1 <= j2)
			{
				tmp[begin++] = a[j1++];

			}
			for (int j = i; j <=j2; j++)
			{
				a[j] = tmp[j];
			}
		gap *= 2;
		}
		
	}
	free(tmp);
}

//桶排序
void Barrel(int* a, int len)
{
	
}

void GSort1(int* a, int left, int right)
{

}
void teat()
{
	int arr[10] = { 0,1,5,67,91,3,5,1,9,52 };
	QSort(arr, 0,9);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));

}
int main()
{
	printf("\a");
	
	//teat();
	return 0;
}