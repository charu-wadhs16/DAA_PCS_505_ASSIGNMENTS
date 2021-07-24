#include<iostream>
#include<algorithm>
using namespace std;
int count_pairs(int a[],int n,int k)
{   
    sort(a,a+n);
    int c=0;
    int left=0;
    int right=0;
    while(right<n)
    {
        if(a[right]-a[left]==k)
        {
        c++;
        left++;
        right++;
        }
        else if(a[right]-a[left]>k)
        left++;
        else
        right++;
    }
    return c; 
}
int main()
{
    int t;
    // t is the number of test cases
    cin>>t;
    while(t--)
    {
    int n,k;
    // n is the size of array
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>k;  // k is the key element
    //function to find three indices such that a[i]+a[j]==a[k]
    cout<<count_pairs(a,n,k)<<endl;
    }
}
