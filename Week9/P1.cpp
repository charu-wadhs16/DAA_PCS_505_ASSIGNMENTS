// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<int>> & dist);
void floydWarshall(vector<vector<int>> & graph)
{
    int V=graph.size();
	vector<vector<int>> dist(V,vector<int>(V,0));
    int i, j, k,INF=9999;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}

void printSolution(vector<vector<int>> & dist)
{ 
    int INF=9999;
    int V=dist.size();
	cout<<"Shortest Distance Matrix :\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF  "
					<< "  ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}
int main()
{   
    int V;
    cin>>V;
    vector<vector<int>> graph(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
	
	floydWarshall(graph);
	return 0;
}
