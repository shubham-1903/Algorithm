#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int partition1(vector<int> &v, int low, int high)
{
  int pivot = v[low];
  int i = low, j = high + 1;
  do
  {
    cout << "f1" << endl;
    do
    {
      i += 1;
      cout << "f2" << endl;
    } while (v[i] >= pivot);

    do
    {
      cout << "f3 " << v[j] << endl;
      j -= 1;
    } while (v[j] <= pivot);

    // if (i < j)
    //   swap(v[i], v[j]);
    if (i < j)
    {
      int t = v[i];
      v[i] = v[j];
      v[j] = t;
    }
  } while (i >= j);
  v[low] = v[j];
  v[j] = pivot;
  return j;
}
int partition2(vector<int> &v, int low, int high)
{
  int i = low + 1;
  int pivot = v[low];
  for (int j = low + 1; j <= high; j++)
  {
    if (v[j] < pivot)
    {
      int t = v[i];
      v[i] = v[j];
      v[j] = t;
      i += 1;
    }
  }
  v[low] = v[i - 1];
  v[i - 1] = pivot;
  return i - 1;
}
void quick_sort(vector<int> &v, int low, int high)
{
  if (low < high)
  {
    int j = partition2(v, low, high);
    quick_sort(v, low, j - 1);
    quick_sort(v, j + 1, high);
  }
}
void PrintVector(vector<int> v)
{
  for (auto x : v)
    cout << x << " ";
  cout << endl;
}
int main()
{
  vector<int> v = {3, 7, 8, 5, 2, 1, 9, 5};
  quick_sort(v, 0, v.size() - 1);
  cout<<"Sorted Array is: ";
  PrintVector(v);
  return 0;
}