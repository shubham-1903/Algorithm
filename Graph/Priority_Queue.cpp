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
    for (int i = 1; i <= n; i++)
      v[i] = c.at(i-1);
  }
  void printheap()
  {
    cout << "heap print: ";
    for (int i = 1; i <= heapSize; i++)
      cout << v[i] << " ";
    cout << endl;
  }
  void heapAdjust(int i, int n)
  {
    cout << "heapAdjust" << endl;
    int j, key;
    key = v[i];
    j = 2 * i;
    while (j <= n )
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
    for (int i = n / 2; i >= 1; i--)
      heapAdjust(i, n);
    cout << "\nHeap Make: ";
    for (int i = 1; i <= n; i++)
      cout << v[i] << " ";
  }
  int parent(int i)
  {
    if(i==1) return 1;
    cout << "parent( " << i << " ): " << i/2<< endl;
    return i/2;
  }
  int getMinimum() { return v[1]; }
  int extractMin()
  {
    if (heapSize <= 0)
      return INT_MAX;
    if (heapSize == 1)
    {
      heapSize -= 1;
      return v[1];
    }
    int m = v[1];
    v[1] = v[heapSize];
    heapSize -= 1;
    heapAdjust(1, heapSize);
    return m;
  }
  void decreaseKey(int i, int newVal)
  {
    v[i] = newVal;
    printheap();
    while (i >= 1 and v[parent(i)] > v[i])
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
  pq ptq(v, n);
  for (auto x : v)
    cout << x << " ";
  cout << endl;
  ptq.makeHeap(n );
  ptq.printheap();
  cout << "Get Min: " << ptq.getMinimum() << endl;
  cout << "Extract Min: " << ptq.extractMin() << endl;
  cout << "Get Min: " << ptq.getMinimum() << endl;
  ptq.printheap();

  ptq.decreaseKey(2, 1);
  ptq.printheap();

  return 0;
}