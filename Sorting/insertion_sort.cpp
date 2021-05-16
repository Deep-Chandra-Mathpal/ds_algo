#include <iostream>
int main()
{
    void insertion_sort(int* arr);
    int array[] = { 4,3,5,1,6,9,0,7,2,8 };
    insertion_sort(array);
    for (int k = 0; k < 10; k++)
    {
        std::cout << array[k];
    }
    return 0;
}

void insertion_sort(int *arr)
{
    for (int i = 0; i < 9; i++)
    {
        int j,min_in = i;
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j] <= arr[min_in])
                min_in = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_in];
        arr[min_in] = temp;
    }
}