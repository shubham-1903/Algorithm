#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class job_items
{
public:
  int id, deadline, profit;
};
void merge(job_items *job, int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  job_items z[high+1];
  while (i <= mid && j <= high)
  {
    if (job[i].profit <= job[j].profit)
    {
      z[k++] = job[i++];
    }
    else
    {
      z[k++] = job[j++];
      // z[k].deadline = job[i].deadline;
      // z[k].id = job[i].id;
      // k++;
      // j++;
    }
  }
  while (i <= mid)
  {
    z[k++] = job[i++];
    // z[k].deadline = job[i].deadline;
    // z[k].id = job[i].id;
    // k++;
    // i++;
  }
  while (j <= high)
  {

    z[k++] = job[j++];
    // z[k].deadline = job[j].deadline;
    // z[k].id = job[j].id;
    // k++;
    // j++;
  }
  for (i = low; i <= high; i++)
  {
    // job[i].profit = z[i].profit;
    // job[i].deadline = z[i].deadline;
    // job[i].id = z[i].id;
    job[i] = z[i];
  }
}
void mergeSort(job_items *job, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(job, low, mid);

    mergeSort(job, mid + 1, high);
    merge(job, low, mid, high);
  }
}
void job_scheduling(job_items *job, int n)
{
  cout << "before" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << job[i].id << " " << job[i].deadline << " " << job[i].profit << endl;
  }
  mergeSort(job, 0, n - 1);
  cout << "After" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << job[i].id << " " << job[i].deadline << " " << job[i].profit << endl;
  }
  job_items rjob[n];
  for(int i = 0; i < n; i++)
  {
    rjob[i]=job[n-i-1];
  }
  cout<<"rjob:"<<endl; 
  for (int i = 0; i < n; i++)
  {
    cout << rjob[i].id << " " << rjob[i].deadline << " " << rjob[i].profit << endl;
  }
  bool slot[n]={false};
  job_items x[n];
  for(int i = 0; i < n; i++)
  {
    cout << "hi\n";
    for(int j=min(n,rjob[i].deadline);i>=0;j--)
    {
      if(slot[j]==false)
      {
        cout<<"if\n";
        x[j]=rjob[i];
        slot[j]=true;
        break;
      }
    }
  }
  cout<<"Result: "<<endl;
	int ans=0;

	for(int i=1 ; i<n ; ++i)
	{
		ans+=x[i].profit;
		cout<<x[i].id<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
  
}
int main()
{
  ifstream infile;
  infile.open("job.txt", ios::in);
  int n;
  infile >> n;
  job_items job[n];
  for (int i = 0; i < n; i++)
  {
    infile >> job[i].id >> job[i].deadline >> job[i].profit;
  }
  // job_items *job = new job_items[n];
  // int M;
  // infile >> M;
  job_scheduling(job, n);
  return 0;
}