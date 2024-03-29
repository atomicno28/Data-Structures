#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
    
        // min heap.    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> ans(V,1e9);
        
        // step=1 make source value to 0.
        ans[S]=0;
        
        q.push({0,S});
        
        
        // LIKE BFS traverse while q isn't empty.
        while(!q.empty())
        {
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                int weight = it[1];
                int adjNode = it[0];
                if(distance + weight < ans[adjNode])
                {
                    ans[adjNode] = distance + weight;
                    q.push({ans[adjNode],adjNode});
                }
            }
        }
        return ans;  
    }
};