#include<iostream>
using namespace std;
int partition(int *a,int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int p=a[i+1];
    a[i+1]=a[high];
    a[high]=p;
    return i+1;
}
void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
void check_duplicates(int *a,int n)
{ 
    int f=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
        f=1;
        cout<<"YES"<<endl;
        break;
        }
    }
    if(f==0)
    cout<<"NO"<<endl;
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
        quicksort(a,0,n-1);
        check_duplicates(a,n);
    }
}