#include <bits/stdc++.h>
using namespace std;
void print_common(int arr1[],int arr2[], int m,int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) 
    {
        if (arr1[i] < arr2[j])
           i++;
        else if (arr2[j] < arr1[i])
           j++;
        else if(arr1[i] == arr2[j])
        {
            if(m>n)
            cout << arr1[i] << " ";
            else
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int m;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++)
    cin>>arr1[i];
    int n;
    cin>>n;
    int arr2[n]; 
    for(int j=0;j<n;j++)
    cin>>arr2[j];
    print_common(arr1,arr2,m,n);
    }
    return 0;
}