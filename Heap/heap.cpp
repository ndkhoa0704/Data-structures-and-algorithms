#include <iostream>

using namespace std;

struct node
{
    int key;
    node *left, *right, *prev;
    node() : left(0), right(0), prev(0){};
};

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = a;
}

node *MaxHeap(int *ar, int n)
{
    node *root = new node;
    root->key = ar[0];
    node *cur = root;
    int nodes = 1;
    node *newNode;
    for (int i = 1; i < n; ++i)
    {
        newNode = new node;
        newNode->key = ar[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int *ar = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    delete[] ar;
}