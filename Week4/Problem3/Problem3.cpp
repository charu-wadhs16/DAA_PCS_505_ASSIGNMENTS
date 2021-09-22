#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int partition(int arr[], int l, int r, int k);
int kthSmallest(int arr[], int l, int r, int k)
{
      while(l<=r)
      {
        int p=partition(arr,l,r,k);
        if(p==k-1)
            return arr[p];
        else if(p>k-1)
            return kthSmallest(arr,l,p-1,k);
        else
            return kthSmallest(arr,p+1,r,k);
      }
      return -1;
}
int partition(int arr[], int l, int r, int x)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>k;
    cout<<kthSmallest(arr,0,n-1,k)<<endl;
    }
    return 0;
}
