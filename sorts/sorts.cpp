#ifndef SORTS_CPP
#define SORTS_CPP

#include "sorts.hpp"

using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void bubble_sort(T *array, const int &size, int (*criteria)(T, T))
{
    int count;
    do
    {
        count = 0;
        for (int i = 1; i < size; ++i)
        {
            if (criteria(array[i - 1], array[i]) == 1)
            {
                Swap(array[i - 1], array[i]);
                ++count;
            }
        }
    } while (count);
}

template <typename T>
void selection_sort(T *array, const int &size, int (*criteria)(T, T))
{
    int size_ = size - 1;
    for (int i = 0; i < size_; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (criteria(array[i], array[j]) == 1)
                Swap(array[i], array[j]);
        }
    }
}

template <typename T>
int _partition_(T *array, const int &left, const int &right, int (*criteria)(T, T))
{
    int l = left;
    int r = right - 1;
    T pivot = array[right];
    while (1)
    {
        while (l <= r && criteria(array[l], pivot) != 1) //<
            ++l;
        while (l <= r && criteria(array[r], pivot) != -1) //>
            --r;
        if (l >= r)
            break;
        Swap(array[l], array[r]);
        ++l;
        --r;
    }
    Swap(array[l], array[right]);
    return l;
}

template <typename T>
void driverQ(T *array, const int &left, const int &right, int (*criteria)(T, T))
{
    if (left <= right)
    {
        int pivot = _partition_(array, left, right, criteria);
        driverQ(array, pivot + 1, right, criteria);
        driverQ(array, left, pivot - 1, criteria);
    }
}

template <typename T>
void quick_sort(T *array, const int &size, int (*criteria)(T, T))
{
    driverQ(array, 0, size - 1, criteria);
}

template <typename T>
void _merge_(T *array, const int &left, const int &right, const int &mid, int (*criteria)(T, T))
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T *tmp_arr1 = new T(n1);
    T *tmp_arr2 = new T(n2);
    for (int i = 0; i < n1; ++i)
        tmp_arr1[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        tmp_arr2[i] = array[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (criteria(tmp_arr1[i], tmp_arr2[j]) == 1)
        {
            array[k] = tmp_arr2[j];
            ++j;
        }
        else
        {
            array[k] = tmp_arr1[i];
            ++i;
        }
        ++k;
    }
    while (i < n1)
    {
        array[k] = tmp_arr1[i];
        ++k;
        ++i;
    }
    while (j < n2)
    {
        array[k] = tmp_arr2[j];
        ++k;
        ++j;
    }
    delete[] tmp_arr1;
    delete[] tmp_arr2;
}

template <typename T>
void driverM(T *array, const int &left, const int &right, int (*criteria)(T, T))
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        driverM(array, left, mid, criteria);
        driverM(array, mid + 1, right, criteria);
        _merge_(array, left, right, mid, criteria);
    }
}

template <typename T>
void merge_sort(T *array, const int &size, int (*criteria)(T, T))
{
    driverM(array, 0, size - 1, criteria);
}

template <typename T>
void insertion_sort(T *array, const int &size, int (*criteria)(T, T))
{
    int j;
    T tmp;
    for (int i = 1; i < size; ++i)
    {
        j = i - 1;
        tmp = array[i];
        while (j >= 0 && criteria(tmp, array[j]) == -1)
        {
            array[j + 1] == array[j];
            --j;
        }
        array[j + 1] = tmp;
    }
}

template <typename T>
void heapConstruct(T *ar, int index, int last, int (*criteria)(T, T))
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left > last)
        return;
    if (right > last)
    {
        if (criteria(ar[left], ar[index]) == 1)
            swap(ar[left], ar[index]);
    }
    else
    {
        if (criteria(ar[index], ar[left]) >= 0 && criteria(ar[index], ar[right]) >= 0)
            return;
        if (ar[right] >= ar[left])
            swap(ar[right], ar[index]);
        else
            swap(ar[left], ar[index]);
    }
}

template <typename T>
void heap_sort(T *ar, int size, int (*criteria)(T, T))
{
    if (size <= 1)
        return;
    int last = size - 1;
    for (int i = last / 2; i >= 0; --i)
        heapConstruct(ar, i, last, criteria);
    swap(ar[last], ar[0]);
    heap_sort(ar, size - 1, criteria);
}
#endif