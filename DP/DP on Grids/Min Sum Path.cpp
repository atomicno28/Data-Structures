#include<iostream>
#include<vector>
using namespace std;
int recurs(int row,int col, vector<vector<int>>&arr){
    
    if(row==0 && col==0) return arr[row][col];
    if(row<0 || col<0) return 1e9;


    int up = arr[row][col] + recurs(row-1,col,arr);
    int left = arr[row][col] + recurs(row,col-1,arr);

    return min(up,left);
}

int memoiz(int row, int col, vector<vector<int>>&dp, vector<vector<int>>&arr)
{
    if(row==0 && col==0) return arr[row][col];
    if(row<0 || col<0) return 1e9;

    if(dp[row][col]!=-1) return dp[row][col];

    int up = arr[row][col] + memoiz(row-1,col,dp,arr);
    int left = arr[row][col] + memoiz(row,col-1,dp,arr);

    return dp[row][col] = min(up,left);
}
int main()
{
    int row,col; cin>>row>>col;
    vector<vector<int>> arr(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

//    cout <<  recurs(row-1,col-1,arr);

//    vector<vector<int>> dp(row,vector<int>(col,-1));

//    cout << memoiz(row-1,col-1,dp,arr);

 vector<vector<int>>dp(row,vector<int>(col));

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 && j==0) dp[row][col] = arr[row][col];
            else
            {
                int up=arr[i][j],left=arr[i][j];
                if(i>0) up += dp[i-1][j];
                else up+= 1e9;
                if(j>0) left+= dp[i][j-1];
                else left+= 1e9;
                dp[i][j]= min(up,left);
            }
        }
    } 
    cout<< dp[row-1][col-1];
}