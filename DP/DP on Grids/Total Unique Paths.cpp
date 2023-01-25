#include<iostream>
#include<vector>
using namespace std;
int recurs( int row, int col)
{
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;

    int up = recurs(row-1,col);
    int left= recurs(row,col-1);

    return up + left;
}
int memoization(vector<vector<int>>&dp,int row, int col)
{
    if(row==0 &&col==0) return 1;
    if(row<0 &&col<0) return 0;

    if(dp[row][col]!=-1) return dp[row][col];

    int up= memoization(dp,row-1,col);
    int left= memoization(dp,row,col-1);

    return dp[row][col] = up+left;
}
int main()
{
    int row,col; cin>>row>>col;

    // cout << recurs(row-1,col-1);

    // vector<vector<int>> dp(row,vector<int>(col,-1));
    // cout<<memoization(dp,row-1,col-1);

   vector<vector<int>> dp(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else
            {
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
   cout<<dp[row-1][col-1];
}