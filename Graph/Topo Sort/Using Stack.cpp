#include<vector>
#include<stack>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void topSort(vector<bool>&visited, vector<int> adj[], int node, stack<int> &s)
	{
	    visited[node]=1;
	    for(auto i: adj[node])
	    {
	        if(!visited[i])
	        topSort(visited,adj,i,s);
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    vector<bool> visited(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            topSort(visited,adj,i,s);
	        }
	    }
	    
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};