#include<iostream>
using namespace std;
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void selection_sort(int *a,int n)
{
    int i,j,c=0,s=0,p,t;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            c++;
            if(a[i]>a[j])
            {
            p=j;
            }
        }
        t=a[i];
        a[i]=a[p];
        a[p]=t;
        s++;
    }
    print(a,n);
    cout<<"comparisons = "<<c<<endl;
    cout<<"swaps = "<<s<<endl;
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
        selection_sort(a,n);
    }
}