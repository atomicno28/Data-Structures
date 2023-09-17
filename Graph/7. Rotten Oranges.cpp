#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& gridd) {
        int m = gridd.size();
        int n = gridd[0].size();

        vector<vector<int>> grid(gridd.begin(),gridd.end());
        vector<vector<int>> visited(m,vector<int>(n,0));

        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }
        int count = 0;
        
        int drow[] = {-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty())
        {

            int row = q.front().second.first;
            int col = q.front().second.second;

            int steps = q.front().first;
 
            count = max(steps,count);
            
            visited[row][col] = 1;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    q.push({count+1,{nrow,ncol}});
                    grid[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) if(grid[i][j]==1) return -1;
        }
      return count;

    }
};