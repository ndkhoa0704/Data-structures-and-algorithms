#ifndef SORTS_HPP
#define SORTS_HPP

#include <iostream>

template <typename T>
void bubble_sort(T *array, const size_t &size, bool (*criteria)(T, T));

template <typename T>
void selection_sort(T *array, const size_t &size, bool (*criteria)(T, T));

template <typename T>
void driver(T *array, const int &left, const int &right, int (*criteria)(T, T));

template <typename T>
void quick_sort(T *array, const int &size, int (*criteria)(T, T));

template <typename T>
void _merge_(T *array, const int &left, const int &right, const int &mid, int (*criteria)(T, T));

template <typename T>
void driverM(T *array, const int &left, const int &right, int (*criteria)(T, T));

template <typename T>
void merge_sort(T *array, const int &size, int (*criteria)(T, T));

template <typename T>
void insertion_sort(T *array, const int &size, int (*criteria)(T, T));

template <typename T>
void heap_sort(T *ar, int size, int (*criteria)(T, T));

template <typename T>
int sortMLR(T *ar, int left, int right, int (*criteria)(T, T));

template <typename T>
int partitionMO3(T *ar, int left, int right, int (*criteria)(T, T));

template <typename T>
void driverMO3_qsort(T *ar, int left, int right, int (*criteria)(T, T));

template <typename T>
void mo3_qsort(T *ar, int size, int (*criteria)(T, T));

template <typename T>
int binary_search(T *ar, T key, int left, int right, int (*criteria)(T, T));

template <typename T>
void binary_insertion_sort(T *ar, int size, int (*criteria)(T, T));

#include "sorts.cpp"
#endif