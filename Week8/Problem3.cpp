#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
	  int n;
      cin >> n;
      int graph[n][n];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            cin >> graph[i][j];
        }
      }
	  int V=n;
      int key[V];
	  int res=0; 
	  fill(key,key+V,INT_MIN);
	  bool mSet[V]; 
	  fill(mSet,mSet+V,false);
	  key[0]=0;
	  for (int count = 0; count < V ; count++) 
	  { 
		int u = -1; 
        for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]>key[u]))
		        u=i;
		mSet[u] = true; 
		res+=key[u];
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && mSet[v] == false) 
				key[v] = max(key[v],graph[u][v]); 
	  }
	  cout<<"Maximum Spanning Weight : "<<res; 

	 return 0; 
} 
