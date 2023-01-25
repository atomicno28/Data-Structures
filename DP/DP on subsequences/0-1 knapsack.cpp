#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int recurs(vector<int>&wt, vector<int>&profit, int n, int bag)
{

    if(n==0)
    {
        if(wt[n]<=bag) return value[n];
        else return 0;
    }

    int nottake = 0 + recurs(wt,profit,n-1,bag);
    int take = INT_MIN;

    if(weight[n]<=bag)
    {
        take = value[n] + recurs(wt,profit,n-1,bag-weight[n]);
    }

    return max(take,nottake);

}
int memoiz(vector<int>&wt, vector<int>&profit, int n, int bag,vector<vector<int>>&dp)
{

    if(n==0)
    {
        if(wt[n]<=bag) return value[n];
        else return 0;
    }

    if(dp[n][bag]!=-1) return dp[n][bag];

    int nottake = 0 + memoiz(wt,profit,n-1,bag,dp);
    int take = INT_MIN;

    if(weight[n]<=bag)
    {
        take = value[n] + memoiz(wt,profit,n-1,bag-weight[n],dp);
    }

    return dp[n][bag] = max(take,nottake);

}

int main()
{
    int n; cin>>n;
    vector<int> wt(n),profit(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    
    int bag; cin>>bag;

    // cout << recurs(wt,profit,n-1,bag);

    // vector<vector<int>> dp(n,vector<int>(bag+1,-1));
    // cout << memoiz(wt,profit,n-1,bag,dp);

    int dp[n][bag+1];
    for(int i=0;i<n;i++) dp[i][0] = 0;
    dp[0
}