// There is no requirement in "VISITED" ARRAY.
#include<vector>
#include<queue>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	bool CycleDetected(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    // setting the indegrees
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	    
	    queue<int> q;
	    
        // pushing such nodes that have 0 indegree.
	    for(int i=0;i<V;i++)
	    {
	        if(!indegree[i]) q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty())
	    {
	        int front = q.front();
	        q.pop();
	        
            // answer storing...
	        ans.push_back(front);
	        for(auto i:adj[front])
	        {
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }

		return ans.size()==V;
	}
};