#include<iostream>
using namespace std;
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void insertion_sort(int *a,int n)
{
int i,j,k,comparisons=0,shifts=0;
for(int i=1;i<n;i++)
{
    k=a[i];
    j=i-1;
    while(j>=0&&a[j]>k)
    {
        comparisons++;
        a[j+1]=a[j];
        shifts++;
        j=j-1;
    }
    a[j+1]=k;
    shifts++;
}
print(a,n);
cout<<"comparisons = "<<comparisons<<endl;
cout<<"shifts = "<<shifts<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        insertion_sort(a,n);
    }
}