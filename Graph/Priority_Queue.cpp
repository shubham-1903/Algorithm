#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class pq
{
public:
  int heapSize;
  int *v = new int;
  pq(vector<int> c, int n)
  {
    heapSize = n;
    for (int i = 0; i <= n; i++)
      v[i] = c.at(i);
  }
  void printheap()
  {
    cout << "heap print: ";
    for (int i = 0; i <= heapSize; i++)
      cout << v[i] << " ";
    cout << endl;
  }
  void heapAdjust(int i, int n)
  {
    cout << "heapAdjust" << endl;
    int j, key;
    key = v[i];
    j = 2 * i;
    while (j <= n - 1)
    {
      cout << "lp " << endl;
      if (j < n and v[j + 1] < v[j])
        j = j + 1;
      if (key <= v[j])
        break;
      v[(j / 2)] = v[j];
      j = 2 * j;
    }
    v[(j / 2)] = key;
  }
  void makeHeap(int n)
  {
    cout << "mk" << endl;
    for (int i = n / 2; i >= 0; i--)
      heapAdjust(i, n);
    cout << "Heap Make: ";
    for (int i = 0; i <= n; i++)
      cout << v[i] << " ";
  }
  int parent(int i)
  {
    cout << "parent( " << i << " ): " << ceil((float(i)/2)-1);
    return int(ceil((float(i)/2)-1));
  }
  int getMinimum() { return v[0]; }
  int extractMin()
  {
    if (heapSize <= 0)
      return INT_MAX;
    if (heapSize == 1)
    {
      heapSize -= 1;
      return v[0];
    }
    int m = v[0];
    v[0] = v[heapSize];
    heapSize -= 1;
    heapAdjust(0, heapSize);
    return m;
  }
  void decreaseKey(int i, int newVal)
  {
    v[i] = newVal;
    while (i >= 0 and v[parent(i)] > v[i])
    {
      cout<<"loop"<<endl;
      int t = v[parent(i)];
      v[parent(i)] = v[i];
      v[i] = t;
      i = parent(i);
    }
  }
};
int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  pq ptq(v, n - 1);
  for (auto x : v)
    cout << x << " ";
  cout << endl;
  ptq.makeHeap(n - 1);
  ptq.printheap();
  cout << "Get Min: " << ptq.getMinimum() << endl;
  cout << "Extract Min: " << ptq.extractMin() << endl;
  cout << "Get Min: " << ptq.getMinimum() << endl;
  ptq.decreaseKey(1, 3);
  ptq.printheap();

  return 0;
}