#include <iostream>

using namespace std;

int find_max(int *ar, int n)
{
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ar[i] > t)
            t = ar[i];
    }
    return t;
}

void Merge(int *ar, int left, int right, int mid, int max)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (ar[i] <= ar[j])
        {
            ar[k] += (ar[i] % max) * max;
            ++k;
            ++i;
        }
        else
        {
            ar[k] += (ar[j] % max) * max;
            ++k;
            ++j;
        }
    }
    while (i <= mid)
    {
        ar[k] += (ar[i] % max) * max;
        ++k;
        ++i;
    }
    while (j <= right)
    {
        ar[k] += (ar[j] % max) * max;
        ++k;
        ++j;
    }
    for (int l = left; l <= right; ++l)
        ar[l] %= max;
}

void MergeSort(int *ar, int left, int right, int max)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(ar, left, mid, max);
        MergeSort(ar, mid + 1, right, max);
        Merge(ar, left, right, mid, max);
    }
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    MergeSort(ar, 0, n - 1, find_max(ar, n));
    for (int i = 0; i < n; ++i)
        cout << ar[i];
    delete[] ar;
}