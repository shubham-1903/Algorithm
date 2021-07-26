#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int x[100];
bool f = true;
int s = 0;
void write(int n,int x[])
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (j == x[i])
        cout << "Q ";
      else
        cout << "_ ";
    }
    cout<<endl;

  }
}
bool place(int k, int i, int x[])
{
  for (int j = 1; j < k; j++)
  {
    if ((x[j] == i) or (abs(x[j] - i) == abs(j - k)))
    {
      return false;
    }
  }
  return true;
}
void n_queen(int k, int n, int x[])
{
  for (int i = 1; i <= n; i++)
  {
    if (place(k, i, x))
    {
    x[k] = i;
      if (k == n)
      {
        f = false;
        cout << "Solution Array " << ++s << "= ";
        for (int j = 1; j <= n; j++)
          cout << x[j] << " ";
        cout << endl;
        write(n,x);
      }
      else
      {
        n_queen(k + 1, n, x);
      }
    }
  }
}
int main()
{
  int n;
  cin >> n;
  int x[n + 1];
  n_queen(1, n, x);
  if (f)
    cout << "No solution possible";
  return 0;
}