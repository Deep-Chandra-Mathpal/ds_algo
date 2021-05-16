#include <iostream>
int main()
{
    void bubble_sort(int arr[],int n);
    void swap(int *x,int *y);
    int arr[] = {8,56,4,3,23,9,0,121,3438};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    for(int k=0;k<size;k++)
        std::cout<<arr[k]<<"  ";
    return 0;
}
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}
