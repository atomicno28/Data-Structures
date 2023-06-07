class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src, vector<bool>&visited, vector<int> adj[])
    {
        queue<pair<int,int>> q;
        visited[src]=1;
        
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neighbour: adj[node])
            {
                if(!visited[neighbour])
                {
                    q.push({neighbour,node});
                    visited[neighbour]=1;
                }
                else if(parent!=neighbour) return 1;
            }
        }
        
        return 0;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0);
        
        // for disconnecting components.
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,visited,adj)) return 1;
            }
        }
        return 0;
    }
};