// !having issue in this code solving soon
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// vector<int> b(10); //d ok
// int b[10];
void merge(int low,int mid,int high,vector<int> v)
{
  vector<int> b(20);
  int k=low,i=low,j=mid+1;
  while(i<=mid and j<= high)
  {
    if(v[i]<=v[j]){ // 
      b[k]=v[i];i+=1;
    }
    else{
      b[k]=v[j];j+=1;
    }
    k+=1;
  }
  while(i<=mid){
    b[k]=v[i];i+=1;k+=1;
  }
  while(j<=high){
    b[k]=v[j];j+=1;k+=1;
  }
  // cout<<"b[]: ";
  for(int i=low;i<=high;i++){
    cout<<b[i]<<" ";
    v[i]=b[i];
    cout<<endl;
    
  }
}
void recursive_merge_sort(int low,int high,vector<int> v)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    recursive_merge_sort(low,mid,v);
    recursive_merge_sort(mid+1,high,v);
    merge(low,mid,high,v);
  }
}
int main()
{
  vector<int> v={3,7,8,5,2,1,9,5};
  recursive_merge_sort(0,8,v);
  for(auto x:v)
    cout<<x<<" ";
  return 0;
}

//! Without using vector<int> Working correct
// #include <iostream>
// using namespace std;
// void merge(int arr[], int low, int mid, int high)
// {
//   int i = low, j = mid + 1, k = low, z[20];
//   while (i <= mid && j <= high)
//   {
//     if (arr[i] <= arr[j])
//       z[k++] = arr[i++];
//     else
//       z[k++] = arr[j++];
//   }
//   while (i <= mid)
//     z[k++] = arr[i++];
//   while (j <= high)
//     z[k++] = arr[j++];
//   for (i = low; i <= high; i++)
//     arr[i] = z[i];
// }
// void mergeSort(int *arr, int low, int high)
// {
//   if (low < high)
//   {
//     int mid = (low + high) / 2;
//     mergeSort(arr, low, mid);

//     mergeSort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }
// int main()
// {
//   int n;
//   cin >> n;
//   int *arr = new int[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   mergeSort(arr, 0, n - 1);
//   cout << "Sorted array is" << endl;
//   for (int i = 0; i < n; i++)
//     cout << arr[i] << " ";

//   return 0;
// }
