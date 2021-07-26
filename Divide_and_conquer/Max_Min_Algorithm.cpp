#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//?Naive Solution
void naive_max_min(int* v,int n)
{
  int maximum = v[0];
  int minimum = v[0];
  for(int i=1;i<n;i++)
  {
    if(maximum < v[i]) maximum = v[i];
    if(minimum > v[i]) minimum = v[i];
  }
  cout <<"Maximum number is: "<< maximum << "\n" <<"Minimum number is: "<< minimum << "\n"; 
}
//? Divide and Conquer Approach
void max_min(int *v,int i,int j,int &maximum,int &minimum)
{
  if(i==j) maximum = minimum = v[i];
  else if(i==j-1)
  {
    if(v[i]<v[j]){
      minimum = v[i];
      maximum = v[j];
    }else{
      minimum = v[j];
      maximum = v[i];
    }
  }
  else{
    int mid=(i+j)/2;
    max_min(v,i,mid,maximum,minimum);
    int maximum1,minimum1;
    max_min(v,mid+1,j,maximum1 ,minimum1);

    if(maximum < maximum1) maximum=maximum1;
    if(minimum > minimum1) minimum=minimum1;
  }

}
int main()
{
  // vector<int> v={5,4,1,2,6};
  int n=5;
  int v[5]={5,4,1,2,6};
  naive_max_min(v,n); //?
  int maximum=INT_MIN,minimum=INT_MAX;
  max_min(v,0,n-1,maximum,minimum);
  cout<<"Maximum is: "<< maximum <<"\n" <<"Minimum is: "<< minimum<<endl;

  return 0;
}