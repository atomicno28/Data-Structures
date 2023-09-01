#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
    public:
    int minofmaxsum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // answer array.
        vector<vector<int>> ans(m,vector<int>(n,1e9));
        
        // min heap.
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;


        // source = {0,0};
        // destination = {m-1,n-1};
        
        ans[0][0]=0;
        q.push({0,{0,0}});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int dis = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;

            // if destination is reached.
            if(row==m-1 && col==n-1) return dis;

            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n)
                {
                    int effort = max(dis,abs(matrix[row][col]-matrix[nrow][ncol]));
                    if(effort<ans[nrow][ncol])
                    {
                        ans[nrow][ncol]= effort;
                        q.push({effort,{nrow,ncol}});
                    }
                }
            }
            
        }

        return 0;
    }

};