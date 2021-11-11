#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
using namespace std;
bool myCmp(pair <int, int> a, pair <int, int> b)
{
	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;
	return r1 > r2;
}
void fKnapS(int wt[],int val[],int n,int W)
{
    vector<pair<int,int>> arr;
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++)
    {
        arr.push_back(make_pair(val[i],wt[i]));
    }
	sort(arr.begin(),arr.end(),myCmp);
	double  res1 = 0.0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i].second <= W)
		{
			res1 += arr[i].first;
            W = W - arr[i].second;
            res.push_back(make_pair(arr[i].first,arr[i].second));
		}
		else
		{
			res1+= arr[i].first * ((double) W / arr[i].second);
            res.push_back(make_pair(arr[i].first,((double) W / arr[i].second)));
            break;
		}
	}
    cout<<"Maximum value : "<<res1;
    cout<<"\nitem - weight\n";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" - "<<res[i].second<<endl;
    }
	
}
int main()
{
	int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int W;
    cin>>W;
	fKnapS(wt,val,n,W);
	return 0;
}