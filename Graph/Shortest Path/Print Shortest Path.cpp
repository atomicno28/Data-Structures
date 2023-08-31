#include<vector>
#include<set>
using namespace std;
class Solution
{
	public:
	//Function to print the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        // declare set.
        set<pair<int,int>>st;
        vector<int> ans(V,1e9);
        vector<int> parent(V);

        // it'll tell that from where the node is coming from.
        for(int i=0;i<V;i++) parent[i]=i;
        

        // STEP - 1;
        st.insert({0,S});
        ans[S]=0;
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int distance = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto it: adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];
                
                if(distance + weight < ans[adjNode])
                {
                    // if node has smaller path other than infinity, then remove it from the set.
                    if(ans[adjNode]!=1e9) st.erase({ans[adjNode],adjNode});
                    
                    ans[adjNode] = distance + weight;
                    st.insert({ans[adjNode],adjNode});
                    parent[adjNode]=node;
                }
                
            }
        }

        // store the path 
        vector<int> path;
        int node = V-1;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};