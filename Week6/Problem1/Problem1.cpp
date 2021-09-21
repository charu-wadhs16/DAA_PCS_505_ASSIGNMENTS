#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool isPath(vector<vector<int>> v,int s,int d)
{
int n=v.size();
if(s==d)
return true;
vector<bool> visited(n,false);
stack<int> st;
visited[s]=true;
st.push(s);
while(!st.empty())
{
    s=st.top();
    st.pop();
    for(int i=0;i<n;i++)
    {
        if(v[s][i]&&i==d)
        return true;
        if(v[s][i]&&!visited[i])
        {
            visited[i]=true;
            st.push(i);
        }
    }
}
return false;
}
int main()
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
    int s;
    int d;
    cin>>s>>d;
    s--;
    d--;
    if(isPath(v,s,d))
    cout<<"Yes Path Exists";
    else
    cout<<"No Such Path Exists";
    cout<<endl;
}