#include <bits/stdc++.h>
using namespace std;
void pair_with_sum(int arr[],int sum, int n)
{
  int low = 0;
  int high = n - 1;
  int c=0;
  sort(arr,arr+n);
  while (low < high)
  {
    if (arr[low] + arr[high] == sum)
    {
      c=1;
      cout <<arr[low] << "  " <<arr[high] << ",";
    }
    if (arr[low] + arr[high] > sum)
    {
      high--;
    }
    else
    {
      low++;
    }
  }
  if(c==0)
  cout<<"No Such pair Exist";
  cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum;
    cin>>sum;
    pair_with_sum(arr,sum,n);
    }
    return 0;
}