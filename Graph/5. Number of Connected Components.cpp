#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col, int m, int n,vector<vector<int>> &matrix, vector<vector<int>>&visited)
{

        // make it visited
        visited[row][col]=1;

        int drow[]= {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && matrix[nrow][ncol])
            {
                dfs(nrow,ncol,m,n,matrix,visited);
            }
        }
}
int main()
{
    int m,n; cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> visited(m,vector<int>(n,0));
    int count = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] && matrix[i][j])
            {
                dfs(i,j,m,n,matrix,visited);
                count++;
            }
        }
    }
    cout << count;
}