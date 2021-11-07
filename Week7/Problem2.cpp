#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin >> n;
    
    vector<vector<int>> g(n+1, vector<int> (n+1, 0));
   
    vector<pair<int,int>> distance(n+1, {1e8, -1});
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }
    int source;
    cin >> source;

    distance[source] = {0, 0};
 
    for(int k=0;k<n-1;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][j] == 0) continue;
                if(distance[i].first + g[i][j] < distance[j].first){
                    distance[j].first = distance[i].first + g[i][j];
                    distance[j].second = i; 
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