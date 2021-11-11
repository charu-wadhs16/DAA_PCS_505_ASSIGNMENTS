#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

double findmedian(int arr[],int n)
{
    sort(arr,arr+n);
    if (n % 2 != 0)
    return (double)arr[n / 2];
    return (double)(arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
}
int findMajority(int arr[], int n)
{
	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}

    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
}
int main() 
{
	 int n;
	 cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     
     if(findMajority(arr, n)!=-1)
     cout<<"Yes"<<endl;
     else
     cout<<"No"<<endl;
     cout<<findmedian(arr,n);
    
}