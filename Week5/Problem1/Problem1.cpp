/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and print
it. (Time Complexity = O(n)) (Hint: Use counting sort)*/

#include<iostream>
#include<cstring>
using namespace std;
void countSort(char arr[],int n)
{
    int count[256]={0};
    int i;
    for (i = 0;i<n;i++)
    count[arr[i]]++;
    int m=count[arr[0]];
    char c=arr[0];
    for(int i=0;i<n;i++)
    {
      if(count[arr[i]]!=0&&count[arr[i]]>m)
      {
          m=count[arr[i]];
          c=arr[i];
      }
    }
    if(m==1)
    cout<<"No Duplicates Present"<<endl;
    else
    cout<<c<<" - "<<m<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    countSort(arr,n);
    }
    return 0;
}