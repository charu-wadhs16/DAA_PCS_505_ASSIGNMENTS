#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
using namespace std;

bool myCmp(pair <int, int> a, pair <int, int> b)
{
	return (a.second < b.second);
}

void maxActivities(int start[],int end[], int n)
{

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back(make_pair(start[i],end[i]));
    }
    vector<int> act;
    sort(arr.begin(),arr.end(),myCmp);
	int prev = 0;
	int res = 1;
	for(int curr = 1; curr < n; curr++)
	{
		if(arr[curr].first >= arr[prev].second)
		{
			res++;
            act.push_back(arr[curr].first);
            act.push_back(arr[prev].second);
			prev = curr;
		}
	}
    cout<<"No. of non-conflicting activities : "<<res<<endl;
    cout<<"List of selected activities : ";
    sort(act.begin(),act.end());
    for(auto i : act)
    {
        cout<<i<<", ";
    }

}
int main()
{
	int n;
    cin>>n;
    int start[n];
    int end[n];
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>end[i];
    }
	maxActivities(start,end,n); 

	return 0;
}