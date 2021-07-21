#include <iostream>
using namespace std;
int first_occurence(int *arr, int n, int key)
{
	int low = 0,high = n-1;
	while(low <= high)
	{
	int mid = (low + high) / 2;
    if(key> arr[mid])
	low = mid + 1;
    else if(key < arr[mid])
	high = mid - 1;
    else
	{
	if(mid == 0 || arr[mid - 1] != arr[mid])
	return mid;
    else
	high = mid - 1;
	}
    }
return -1;
}
int last_occurence(int *arr, int n, int key)
{
	int low = 0, high = n - 1;
    while(low <= high)
	{
	int mid = (low + high) / 2;
    if(key > arr[mid])
	low = mid + 1;
    else if(key < arr[mid])
	high = mid - 1;
    else
	{
	if(mid == n - 1 || arr[mid + 1] != arr[mid])
	return mid;
    else
	low = mid + 1;
	}
    }
return -1;
}

int count_occurence(int *arr, int n, int key)
{
	int f= first_occurence(arr, n, key);
    if(f==-1)
	return -1;
	else 
	return last_occurence(arr, n, key)- f+1;
}
int main()
{
    // for reading input from a text file
    freopen("input1.txt","r",stdin);
    // for writing output on a text file
    freopen("output1.txt","w",stdout);
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
   
    int c=count_occurence(arr,n,key);
    if(c!=-1)
    cout<<key<<" - "<<c<<endl;
    else
    cout<<"Key not present"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}