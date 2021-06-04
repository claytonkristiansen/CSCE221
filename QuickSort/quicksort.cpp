#include "quicksort_helpers.h"



template<typename T>
void QuickSortRec(T* arr, int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(arr, low, high);          // O(n)
        QuickSortRec(arr, low, pivot - 1);              //
        QuickSortRec(arr, pivot + 1, high);             //
    }
}

template<typename T>
void QuickSort(T* arr, int size)
{
    QuickSortRec(arr, 0, size - 1);
}

int main()
{
    int size = 30;
    int array[] = {423, 4325, 54, 7, 243, 5, 3, 7, 5, 76, 23, 675, 23, 534, 645, 12, 3, 21, 321, 43, 43, 23453, -20, 21, 1, -5, -6, 32, 2, 12};
    PrintArray(array, size);
    QuickSort(array, size);
    PrintArray(array, size);
    return 0;
}