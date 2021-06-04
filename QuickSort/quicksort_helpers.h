#include <iostream>


template<typename T>
inline void PrintArray(T* arr, int size)
{
    std::cout << "[";
    for(int i = 0; i < size; ++i)
    {
        if(i == size - 1)
        {
            std::cout << arr[i] << "]\n";    
            return;
        }
        std::cout << arr[i] << ", ";
    }
}

template<typename T>
inline void Swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
inline int Partition(T* arr, int low, int high)
{
    int pivotDex = high;
    T pivot = arr[pivotDex];
    int i = low;
    for(int k = low; k <= high; ++k)
    {
        if(arr[k] < pivot)
        {
            Swap(&arr[i], &arr[k]);
            ++i;
        }
    }
    Swap(&arr[i], &arr[high]);
    return i;
}