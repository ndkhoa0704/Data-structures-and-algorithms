#include <bits/stdc++.h>

using namespace std;

void heapConstruct(int *ar, int index, int last)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left > last)
        return;
    if (right > last)
    {
        if (ar[left] > ar[index])
            swap(ar[left], ar[index]);
    }
    else
    {
        if (ar[index] >= ar[left] && ar[index] >= ar[right])
            return;
        if (ar[right] >= ar[left])
            swap(ar[right], ar[index]);
        else
            swap(ar[left], ar[index]);
    }
}

void heap_sort(int *ar, int last)
{
    if (last <= 0)
        return;
    for (int i = last / 2; i >= 0; --i)
        heapConstruct(ar, i, last);
    swap(ar[last], ar[0]);
    heap_sort(ar, last - 1);
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    heap_sort(ar, n - 1);
    for (int i = 0; i < n; ++i)
        cout << ar[i] << " ";
    cout << endl;
    delete[] ar;
}