#include<iostream>
using namespace std;
void find_indices(int a[],int n)
{   
    int c=0;
    for(int k=0;k<n;k++)
    {
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==a[k])
        {
         cout<<i+1<<", "<<j+1<<", "<<k+1<<endl;
         c++; 
         break;
        }
        else if(a[i]+a[j]>a[k])
        j--;
        else
        i++;
    }
    if(c>0)
    break;
   }
   if(c==0)
   {
    cout<<"No sequence found."<<endl;
   }
}
int main()
{
    int t;
    // t is the number of test cases
    cin>>t;
    while(t--)
    {
    int n;
    // n is the size of array
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    //function to find three indices such that a[i]+a[j]==a[k]
    find_indices(a,n);
    }
}