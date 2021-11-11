#include <bits/stdc++.h>
using namespace std;
int find(int i,vector<int> & parent)
{
    while (parent[i] != i)
    i = parent[i];
    return i;
}
void union1(int i, int j,vector<int> & parent)
{
    int a = find(i,parent);
    int b = find(j,parent);
    parent[a] = b;
}
void kruskalMST(const vector<vector<int>> & cost,int V)
{
    int mincost = 0; 
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
    parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min =INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i,parent)!= find(j,parent) && cost[i][j] < min) 
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
      
        union1(a, b,parent);
        edge_count++;
        mincost += min;
    }
    cout<<"Minimum Spanning Weight : "<< mincost;
}
 
int main()
{ 
    int V;
    cin>>V;
    vector<vector<int>> cost(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=INT_MAX;
        }
    }
    kruskalMST(cost,V);
    return 0;
}