#include <iostream>
using namespace std;
int main()
{
    void heapify(int[], int, int);
    void heap_sort(int[], int);
    int arr[] = { 50, 21, 1, 89, 232, 35,67,23,0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, n);
    cout << "Sorted array is \n";
    for(int x : arr) std::cout<<x<<" ";
}
void heapify(int arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
