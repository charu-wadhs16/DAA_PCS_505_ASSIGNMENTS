#include<iostream>
using namespace std;
int find(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
          cout<<"Key element found at index "<<i<<endl;
          return (i+1);
        }
    }
    cout<<"Key element not found"<<endl;
    return n;
}
int main()
{
    #ifndef ONLINE_JUDGE
      // for reading input from a text file
      freopen("input.txt","r",stdin);
      // for writing output on a text file
      freopen("output.txt","w",stdout);
    #endif 
        
    int t; 
    // t is the number of test cases
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)
       cin>>arr[i];
       int key;  // key is the key element to find
       cin>>key;
       int c=find(arr,n,key);
       cout<<"Number of comparisons performed : "<<c<<endl;
    }
    return 0;
}