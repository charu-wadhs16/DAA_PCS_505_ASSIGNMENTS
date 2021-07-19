#include<iostream>
using namespace std;
int linear_search(int *arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
          return (i+1);
        }
    }
    return -1;
}
int main()
{

    // for reading input from a text file
    freopen("input.txt","r",stdin);
    // for writing output on a text file
    freopen("output.txt","w",stdout);
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
    int c=linear_search(arr,n,key);
    if(c!=-1)
    cout<<"Present "<<c<<endl;
    else
    cout<<"Not Present "<<n<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}