#include <iostream>
int main()
{
    int arr[] = { 3,6 ,33,56,87,2,889,0,25,9987,564,90};
	void merge_sort(int[], int, int);
	void merge_(int[], int, int, int);
	int n = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr,0,n-1);
	for (int x : arr) std::cout << x << " ";
	return 0;
}
void merge_(int arr[], int l, int mid, int r)
{
	int nl = (mid - l + 1),nr = (r - mid),larr[nl],rarr[nr];
	for (int i = 0; i < nl; i++) larr[i] = arr[l + i];
	for (int j = 0; j < nr; j++) rarr[j] = arr[mid + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < nl && j < nr) (larr[i] <= rarr[j])? arr[k++] = larr[i++] : arr[k++] = rarr[j++];
	while (i < nl) arr[k++] = larr[i++];
	while (j < nr) arr[k++] = rarr[j++];
}
void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
     int mid = l + (r-l) / 2;
	 merge_sort(arr, l, mid);
	 merge_sort(arr, mid + 1, r);
	 merge_(arr, l, mid, r);
	}
}
