#ifndef SORTS_HPP
#define SORTS_HPP

#include <bits/stdc++.h>

template <typename T>
void Swap(T &a, T &b);

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

#include "sorts.cpp"
#endif
