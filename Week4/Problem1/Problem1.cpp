#include <bits/stdc++.h>
using namespace std;
struct store
{
    int comparisons=0;
}s;
int mergeSort(int arr[], int left, int right,int n);
int merge(int arr[], int temp[], int left, int mid,int right);
void printArray(int a[],int n);
int mergeSort(int arr[], int left, int right,int n)
{
    int temp[n];
    int mid;
    int inversions=0;
    if (right > left) 
    {
        mid = (right + left) / 2;
        inversions += mergeSort(arr, left, mid,n);
        inversions += mergeSort(arr, mid + 1, right,n);
        inversions += merge(arr,temp,left, mid + 1, right);
    }
    return inversions;
}
int merge(int arr[], int temp[], int left, int mid,int right)
{
    int i, j, k;
    int inversions=0;
    int comparisons=0;
    i = left; 
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
            comparisons++;

        }
        else 
        {
            temp[k++] = arr[j++];
            inversions = inversions + (mid - i);
            comparisons++;
        }
    }
    while (i <= mid - 1)
    temp[k++] = arr[i++];
    while (j <= right)
    temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
    arr[i] = temp[i];
    s.comparisons+=comparisons;
    return inversions;
}
void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int comparisons=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int l=0,r=n-1;
    int inv=mergeSort(arr,0,n-1,n);
    printArray(arr,n);
    cout<<"Comparisons = "<<s.comparisons<<endl;
    cout<<"Inversions"<<" = "<<inv<<endl;
    s.comparisons=0;
    }
    return 0;
}