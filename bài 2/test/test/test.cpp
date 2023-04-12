#include<iostream>
#include<fstream>
using namespace std;

int doc_file(int a[])
{
	fstream iput("Data1.txt");
	int n = 0;
	while (iput >> a[n])
	{
		n++;
	}
	return n;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int pivition(int a[], int left, int right)
{
	int pi = a[right];
	int i = left - 1;
	for (int j = left; j < right ; j++) {
		if (a[j] < pi) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return (i + 1);
}
void quicksort(int a[], int left, int right)
{
	if (left < right)
	{
		int pivot = pivition(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
	}
}




void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[100];
	int n = doc_file(a);
	xuat(a, n);
	quicksort(a, 0, n - 1);
	xuat(a, n);
	return 0;
}