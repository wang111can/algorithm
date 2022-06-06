#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

const int N = 100010;

int arr[N];


void Sort(int arr[], int n)
{

	
	for (int gap = n / 2; gap; gap /= 2)
	{
		for (int i = 0; i <= n - gap; i += gap)
		{
			int j = i - gap, t = arr[i];
			while (j >= 0)
			{
				if (arr[j] < t) arr[j + gap] = arr[j];
				else break;
				j -= gap;
			}
			arr[j + gap] = t;
		}
	}



}

void Insert_Sort(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int j = i - 1, t = arr[i];
		while (j >= 0)
		{
			if (arr[j] < t) arr[j + 1] = arr[j];
			else break;
			j--;
		}
		arr[j + 1] = t;
	}

}

int main()
{
	srand((int)time(nullptr));
	int n = 20;

	for (int i = 0; i < n; i++)
		arr[i] = rand() % 101;
	Sort(arr, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}