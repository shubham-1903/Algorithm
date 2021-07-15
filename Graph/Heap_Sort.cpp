#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
void heapAdjust(int a[], int i, int n)
{
  int j, key;
  j = 2 * i;
  key = a[i];
  while (j <= n)
  {
    if (j < n && a[j] < a[j + 1])
      j = j + 1;
    if (key >= a[j])
      break;
    a[(j / 2)] = a[j];
    j = 2 * j;
  }
  a[(j / 2)] = key;
}
void makeHeap(int a[], int n)
{
  for (int i = n / 2; i >= 1; i--)
    heapAdjust(a, i, n);
}
void heapSort(int arr[], int n)
{
  makeHeap(arr, n);
  for (int i = n; i >= 2; i--)
  {
    int t = arr[i];
    arr[i] = arr[1];
    arr[1] = t;
    cout << "Pass " << n-i+1 << ": ";
    printArray(arr, n);
    cout<<endl;
    heapAdjust(arr, 1, i - 1);
  }
}
int main()
{
  int n;
  int *arr = new int[n];
  cin>>n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  heapSort(arr, n);
  cout << "Sorted array: " << endl;
  printArray(arr, n);
  return 0;
}
// 80 90 10 20 50 60 40 70