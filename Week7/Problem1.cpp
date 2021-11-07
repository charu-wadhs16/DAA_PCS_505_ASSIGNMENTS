#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> g(n+1, vector<int> (n+1, 0));
    vector<int> visited(n+1, 0);
    vector<pair<int,int>> distance(n+1, {INT_MAX, -1});
    priority_queue<pair<int,int>, vector<pair<int, int>>,  greater<pair<int,int>>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> g[i][j];
        }
    }
    int source;
    cin >> source;
    q.push({0, source});
    distance[source] = {0, 0};
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        visited[u] = 1;
        for(int i=1;i<=n;i++){
            if(g[u-1][i-1] != 0 and !visited[i]){
                int W = g[u-1][i-1];
                if(distance[u].first + W  < distance[i].first){
                    distance[i].first = distance[u].first+W;
                    distance[i].second = u;
                    q.push({distance[i].first, i});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        vector<int> path;
        int prev = distance[i].second;
        if(i != source){
            while(prev != 1){
                path.push_back(prev);
                prev = distance[prev].second;
            }   
        }
        path.push_back(source);
        cout << i << " ";
        for(auto &x: path){
            cout << x << ' ';
        }
        cout << ": " << distance[i].first << '\n';
    }    
    return 0;
}