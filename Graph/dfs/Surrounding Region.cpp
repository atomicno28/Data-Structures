#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void DFS(int row, int col,vector<vector<int>>&visited,vector<vector<char>>&matrix)
    {
        visited[row][col] = 1;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && matrix[nrow][ncol]=='O')
            {
                DFS(nrow,ncol,visited,matrix); 
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<char>> matrix(mat.begin(),mat.end());
    
        
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && matrix[0][i]=='O') DFS(0,i,visited,matrix);
            if(!visited[n-1][i] && matrix[n-1][i]=='O') DFS(n-1,i,visited,matrix);
        }
        for(int i=1;i<n-1;i++)
        {
            if(!visited[i][0] && matrix[i][0]=='O') DFS(i,0,visited,matrix);
            if(!visited[i][m-1] && matrix[i][m-1]=='O') DFS(i,m-1,visited,matrix);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && matrix[i][j]=='O') matrix[i][j] = 'X';
            }
        }
        
        return matrix;
    }
};