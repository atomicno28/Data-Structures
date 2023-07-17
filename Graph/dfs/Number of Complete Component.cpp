#include<vector>
#include<iostream>
using namespace std;
class Graph
{
public:

void dfs(int &countEdge, int &countVertex,int node, vector<int>&visited,vector<vector<int>>&adj)
{
    visited[node] = 1;

    countVertex++;
    countEdge = adj[node].size();

    for(auto it:adj[node])
    {
        if(!visited[it]) dfs(countEdge,countVertex,it,visited,adj);
    }


}
int ans(int n,vector<vector<int>>adj)
{
    vector<int> visited(n,0);

    int result = 0;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int countEdge=0, countVertex=0;
            dfs(countEdge,countVertex,i,visited,adj);
            if(countEdge==countVertex*(countVertex-1)) result++;
        }
    }

    return result;
}
};