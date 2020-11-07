#ifndef SORTS_CPP
#define SORTS_CPP

#include "sorts.hpp"

using namespace std;

// bubble sort

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
                swap(array[i - 1], array[i]);
                ++count;
            }
        }
    } while (count);
}

// selection sort

template <typename T>
void selection_sort(T *array, const int &size, int (*criteria)(T, T))
{
    int size_ = size - 1;
    for (int i = 0; i < size_; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (criteria(array[i], array[j]) == 1)
                swap(array[i], array[j]);
        }
    }
}

// quick sort (choose last element as pivot)

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
        swap(array[l], array[r]);
        ++l;
        --r;
    }
    swap(array[l], array[right]);
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

// merge sort

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

// insertion sort

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

// heap sort

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

// median of three quick sort

template <typename T>
int sortMLR(T *ar, int left, int right, int (*criteria)(T, T))
{
    int mid = left + (right - left) / 2;
    if (criteria(ar[left], ar[mid]) == 1)
        swap(ar[left], ar[mid]);
    if (criteria(ar[mid], ar[right]) == 1)
        swap(ar[mid], ar[right]);
    if (criteria(ar[left], ar[mid]) == 1)
        swap(ar[left], ar[mid]);
    return mid;
}

template <typename T>
int partitionMO3(T *ar, int left, int right, int (*criteria)(T, T))
{
    int l = left + 1;
    int r = right - 2;
    int pivot_i = sortMLR(ar, left, right, criteria);
    T pivot_v = ar[pivot_i];
    swap(ar[pivot_i], ar[right - 1]);
    while (1)
    {
        while (l <= r && criteria(ar[l], pivot_v) != 1) //<
            ++l;
        while (l <= r && criteria(ar[r], pivot_v) != -1) //>
            --r;
        if (l >= r)
            break;
        swap(ar[l], ar[r]);
        ++l;
        --r;
    }
    swap(ar[l], ar[right - 1]);
    return l;
}

template <typename T>
void driverMO3_qsort(T *ar, int left, int right, int (*criteria)(T, T))
{
    if (right - left + 1 < 3)
    {
        heap_sort(ar, 2, criteria);
        return;
    }
    int pivot = partitionMO3(ar, left, right, criteria);
    driverMO3_qsort(ar, left, pivot - 1, criteria);
    driverMO3_qsort(ar, pivot + 1, right, criteria);
}

template <typename T>
void mo3_qsort(T *ar, int size, int (*criteria)(T, T))
{
    driverMO3_qsort(ar, 0, size - 1, criteria);
}

// binary insertion sort
template <typename T>
int binary_search(T *ar, T key, int left, int right, int (*criteria)(T, T))
{
    if (right <= left)
    {
        if (key > ar[left])
            return left + 1;
        return left;
    }
    int mid = (right + left) / 2;
    if (criteria(ar[mid], key) == 1)
        return binary_search(ar, key, left, mid - 1, criteria);
    else if (criteria(ar[mid], key) == -1)
        return binary_search(ar, key, mid + 1, right, criteria);
    else
        return mid + 1;
}
template <typename T>
void binary_insertion_sort(T *ar, int size, int (*criteria)(T, T))
{
    int loc, j;
    T sel;
    for (int i = 1; i < size; ++i)
    {
        j = i - 1;
        sel = ar[i];
        loc = binary_search(ar, sel, 0, j, criteria);
        while (j >= loc)
        {
            ar[j + 1] = ar[j];
            --j;
        }
        ar[j + 1] = sel;
    }
}

#endif