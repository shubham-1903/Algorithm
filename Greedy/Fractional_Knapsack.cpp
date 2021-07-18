#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Knapsack(vector<int> profit, vector<int> weight, int n, int W)
{
  vector<pair<double, int>> ratio;
  for (int i = 0; i < n; i++)
  {
    double x = (profit[i] * 1.0) / (weight[i] * 1.0); //280 100 120 120
                                                      //40 10 20 24
    ratio.push_back({x, i});                          // 7 10 6 5
  }
  sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
  int w = 0;
  double ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (w + weight[ratio[i].second] <= W)
    {
      ans += profit[ratio[i].second];
      w += weight[ratio[i].second];
    }
    else
    {
      double x = (W - w) * 1.0;
      ans += (x * ratio[i].first);
      break;
    }
  }
  cout << " " << ans << endl;
}
int main()
{
  ifstream infile;
  infile.open("knap.txt", ios::in);
  vector<int> profit;
  vector<int> weight;
  int n;
  infile >> n;
  for (int i = 0; i < n; i++)
  {
    int p, w;
    infile >> p >> w;
    profit.push_back(p);
    weight.push_back(w);
  }
  int W;
  infile >> W;
  cout<<"Profit: ";
  for (auto x : profit)
    cout << x << " ";
  cout << endl;
  cout<<"Weight: ";
  for (auto y : weight)
    cout << y << " ";
  cout<<"\nTotal Profit:" ;
  Knapsack(profit, weight, n, W);
  return 0;
}