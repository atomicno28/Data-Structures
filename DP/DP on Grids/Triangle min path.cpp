#include<iostream>
#include<vector>
using namespace std;
int recurs(int row, int col, int size, vector<vector<int>>&triangle)
{
    if(row==size-1) return triangle[size-1][col];
    
    int down = triangle[row][col] + recurs(row+1,col,size,triangle);
    int downr = triangle[row][col] + recurs(row+1,col+1,size,triangle);

    return min(down,downr);
}

int memoiz(int row, int col, vector<vector<int>>&dp, int size, vector<vector<int>>&triangle)
{
    if(row==size-1) return triangle[row][col];
    if(dp[row][col]!=-1) return dp[row][col];

    int down = triangle[row][col] + memoiz(row+1,col,dp, size,triangle);
    int downr = triangle[row][col] + memoiz(row+1,col+1, dp, size, triangle);
 
    return dp[row][col] = min(down,downr);
}

int main()
{
    int n; cin>>n; 
    vector<vector<int>>triangle;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j)
        {
            int temp; cin>>temp;
            triangle[j].push_back(temp);
        }
    }

    // cout << recurs(0,0,n,triangle);

    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // cout << memoiz(0,0,dp,n,triangle);

    vector<vector<int>>dp;

    for(int j=0;j>n;j++)
    {
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int downr = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,downr);
        }
    }

    cout<< dp[0][0];

}