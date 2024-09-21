#include<iostream>
using namespace std;
void swaps(int a[], int x, int y)
{
	int tem = a[x];
	a[x] = a[y];
	a[y] = tem;
}

int partition(int a[], int left, int right)
{
	int pivot = a[left];// gia tri dau tien 
	int count = 0;
	// dem so luong ben trai pivot 
	for (int i = left + 1; i <= right; i++)
	{
		if (a[i] <= pivot)
		{
			count++;
		}
	}
	// tim vi tri index cho pivot 
	int pivotidx = left + count;

	// hoan vi 
	swaps(a, left, pivotidx);

	int i = left;
	int j = right;
	while (i<pivotidx && j > pivotidx)// i ben trai pivot va j ben phai pivot 
	{
		while (a[i] <= pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j--;
		}
		if (i<pivotidx && j>pivotidx)
		{
			swaps(a, i, j);
		}
	}
	return pivotidx;

}
void quicksort(int a[], int left, int right)
{
	if (left>=right)
	{
		return;
	}
	int pivot = partition(a, left, right);// chia phan tu chot
	quicksort(a, left, pivot - 1);
	quicksort(a, pivot + 1, right);
}
int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;

}