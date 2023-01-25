#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int recurs(int row, int col, vector<vector<int>>&matrix)
{
    if(col<0 || col>=matrix[0].size()) return -1e8;
    if(row==0) return matrix[0][col];
    
    int up = matrix[row][col] + recurs(row-1,col,matrix);
    int upl = matrix[row][col] + recurs(row-1,col-1,matrix);
    int upr = matrix[row][col] + recurs(row-1,col+1,matrix);

    return  max(up,max(upl,upr));
}

int memoiz(int row, int col, vector<vector<int>>&matrix,vector<vector<int>> &dp)
{
    if(col<0 || col>=matrix[0].size()) return -1e8;
    if(row==0) return matrix[0][col];
    
    if(dp[row][col]!=-1) return dp[row][col];

    int up = matrix[row][col] + memoiz(row-1,col,matrix,dp);
    int upl = matrix[row][col] + memoiz(row-1,col-1,matrix,dp);
    int upr = matrix[row][col] + memoiz(row-1,col+1,matrix,dp);

    return dp[row][col] = max(up,max(upl,upr));
}
int main()
{
    int row,col; cin>>row>>col;
    vector<vector<int>> matrix(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int maxi= -1e8;
    // for(int j=0;j<col;j++)
    // {
    //    maxi= max(maxi,recurs(col-1,j,matrix));
    // }
    
    // cout<<maxi;

    // vector<vector<int>>dp(row,vector<int>(col,-1));

    // for(int j=0;j<col;j++)
    // {
    //    maxi= max(maxi,memoiz(col-1,j,matrix,dp));
    // }

    int dp[row][col];
    for(int i=0;i<col;i++) dp[0][i] = matrix[0][j];

    for(int i=1;i<row;i++)
    {
        for(int j=0;j<n;j++)
        {  
            int upl=matrix[i][j],upr=matrix[i][j];
            int up = mat[i][j] + dp[i-1][j];
         if(j>=1)   upl += dp[i-1][j-1];
         else upl+= maxi;
         if(j+1<n)  upr += dp[i-1][j+1];
         else uplr+=maxi;
            dp[i][j] max(up,max(upl,upr));
        }
    }
}