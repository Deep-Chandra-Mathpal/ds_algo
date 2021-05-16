#include<iostream>

int main()
{
    int arr[] = {3,2,5,6,7,1,8,9,4,0};
    int arr_size = 10;
    void quick_sort(int*,int,int);
    int arr_partition(int*,int,int);
    for(int j=0;j<=arr_size-1;j++)
    {
        std::cout<<arr[j]<<" ";
    }
    std::cout<<std::endl;
    quick_sort(arr,0,arr_size-1);
    for(int j=0;j<=arr_size-1;j++)
    {
        std::cout<<arr[j]<<" ";
    }
return 0;
}

int arr_partition(int arr[],int st, int en)
{
    int pivot = arr[en];
    int partition_index = st;
    for(int i=st;i<=en;i++)
    {
         if(arr[i]<=pivot)
         {
             int temp = arr[partition_index];
             arr[partition_index] = arr[i];
             arr[i] = temp;
             partition_index++;
         }
    }
return --partition_index;
}

void quick_sort(int arr[],int st,int en)
{
   if(st>=en) return;
   int pi = arr_partition(arr,st,en);
   quick_sort(arr,st,pi-1);
   quick_sort(arr,pi+1,en);
}
