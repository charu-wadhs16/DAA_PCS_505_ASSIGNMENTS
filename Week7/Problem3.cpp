#include <bits/stdc++.h>
using namespace std;
int main()
{
   
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    int source, dest, k;
    cin >> source >> dest;
    cin >> k;
    int dp[n][n][k+1];
    memset(dp, 0, sizeof(dp));
    for(int len=1;len<=k;len++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][len] = 1e8;
                for(int x=0;x<n;x++){
                    if(g[x][j] != 0 and (x != i or len == 1)){
                        dp[i][j][len] = min(dp[i][j][len], dp[i][x][len-1] + g[x][j]);
                    }
                }
            }
        }
    }
    if(dp[source-1][dest-1][k] >= 1e8) 
    cout << "No paths of length " << k << " from " << source << " to " << dest << " exists\n";
    else
    cout << "Weight of shortest path from " << source << " to " << dest<< " with " << k << " edges: " << dp[source-1][dest-1][k] << '\n'; 
    return 0;
}