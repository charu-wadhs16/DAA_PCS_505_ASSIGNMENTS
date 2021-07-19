#include<iostream>
#include<cmath>
using namespace std;
int binary_search(int *arr,int n,int key)
{
int low=0,high=n-1,c=0;
while(low<=high)
{
    int mid=(low+high)/2;
    c++;
    if(arr[mid]==key)
    {
        return c;
    }
    else if(arr[mid]>key)
    {
    high=mid-1;
    }
    else
    {
    low=mid+1;
    }
}
return -1;
}
int main()
{
    // for reading input from a text file
    freopen("input2.txt","r",stdin);
    // for writing output on a text file
    freopen("output2.txt","w",stdout);
    int t; 
    // t is the number of test cases
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    // n is the number of elments in the array
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    // key is the key element to find
    cin>>key;
    int c=binary_search(arr,n,key);
    if(c!=-1)
    cout<<"Present "<<c<<endl;
    else
    cout<<"Not Present "<<floor(log2(n))+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}