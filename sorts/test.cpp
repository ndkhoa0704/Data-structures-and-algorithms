#include "sorts.hpp"

using namespace std;

int cond(int a, int b)
{
    if (a > b)
        return 1;
    if (a == b)
        return 0;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    mo3_qsort(ar, n, cond);
    for (int i = 0; i < n; ++i)
        cout << ar[i] << " ";
    cout << endl;
}