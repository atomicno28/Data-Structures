class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // make adjaceney list.
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        // make array.
        vector<int> ans(n+1,1e9);

        // make source to zero. (huehuehue)
        ans[0]=0;
        ans[k]=0;

        priority_queue<pair<int,int>> q;
        q.push({0,k});

        while(!q.empty())
        {
            int dist = q.top().first;
            int node = q.top().second;

            q.pop();

            for(auto it: adj[node])
            {
                // if current path is shorter than the previous path.
                if(dist + it.second < ans[it.first])
                {
                    ans[it.first] = dist + it.second;
                    q.push({ans[it.first],it.first});
                }
            }
        }
        int maxi=0;
      
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            // if any path is notreachable.
            if(ans[i]==1e9) return -1;
            // choose the max time taken.
            maxi= max(maxi,ans[i]);
        }
        return maxi;
        
    }
};
