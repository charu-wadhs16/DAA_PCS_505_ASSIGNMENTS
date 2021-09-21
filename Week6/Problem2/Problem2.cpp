#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isBipartite(vector<vector<int>> v,int s)
{
    // value -1 indicates no color
    // value 1 indicates first color
    // value 0 indicates second color
    int n=v.size();
    int color[n];
    for (int i = 0; i < n;i++)
    color[i] = -1;
    color[s] = 1;
    queue <int> q;
    q.push(s);
    while (!q.empty())
    {
        
        int u = q.front();
        q.pop();
        if (v[u][u] == 1)
        return false;
        for (int i = 0; i < n;i++)
        {
            if (v[u][i] && color[i] == -1)
            {
                color[i] = 1 - color[u];
                q.push(i);
            }
            else if (v[u][i] && color[i] == color[u])
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    if(isBipartite(v,0))
    cout<<"Yes Bipartite";
    else
    cout<<"Not Bipartite";
    cout<<endl;
    }
}