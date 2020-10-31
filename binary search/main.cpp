#include <iostream>
#include <string>

using namespace std;

int Binary_Tree(int A[], int l, int r, int x)
{
	int m;
	if (r >= l)
	{
		m = l + (r - l) / 2;
		if (x == A[m])
		{
			return m;
		}
		else
		{
			if (x > A[m])
			{ //scan right
				return Binary_Tree(A, m + 1, r, x);
			}
			if (x < A[m])
			{ //scan left
				return Binary_Tree(A, l, m - 1, x);
			}
		}
	}
	return -1;
}

int main()
{
	int x;
	int n;
	cout << "number of items:";
	cin >> n;
	int *A = new (nothrow) int[n];
	if (A == nullptr)
	{
		cout << "cannot allocate memory";
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]";
		cin >> A[i];
	}
	cout << "item to be found in array: ";
	cin >> x;
	int loc = Binary_Tree(A, 0, n - 1, x);
	if (loc == -1)
	{
		cout << "item cannot be found!!!";
		return -1;
	}
	cout << "location of " << x << " in array is: " << loc;
	delete[] A;
	return 0;
}