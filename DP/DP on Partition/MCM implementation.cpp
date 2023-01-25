#include<iostream>
#include<vector>
using namespace std;

int recurs(vector<int>& arr, int i, int j)
    {
        if(i==j) return 0;
        
        int mini=1e9;

        //    k(i--->j-1)
        //  following the f(i,k) + f(k+1,j) procedure

        // OR, we can do the k(i+1--->j)
        // f(i,k-1) + f(k,j)

        for(int k=i;k<j;k++)
        {
            int steps = arr[i-1]*arr[k]*arr[j] + recurs(arr,i,k) + recurs(arr,k+1,j);
            mini=min(steps,mini);
        }
        return mini;
    }
int memoiz(vector<int>& arr, int i, int j,vector<vector<int>>&dp)
    {
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            int steps = arr[i-1]*arr[k]*arr[j] + memoiz(arr,i,k,dp) + memoiz(arr,k+1,j,dp);
            mini=min(steps,mini);
        }
        return dp[i][j] = mini;
    }

int tabul(vector<int>&arr, int N)
{
     vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i+1;j<N;j++)
        {
            int mini=1e9;
            for(int k=i;k<j;k++)
            {
                int ans = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini= min(mini,ans);
            }
            dp[i][j]=mini;
        }
    }

    return dp[1][N-1];
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // cout << recurs(arr,1,n-1);

    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // cout << memoiz(arr,1,n-1,dp);

    cout << tabul(arr,n);

}