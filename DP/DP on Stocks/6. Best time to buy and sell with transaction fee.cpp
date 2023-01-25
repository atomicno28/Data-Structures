#include<iostream>
#include<vector>
using namespace std;
int recurs(int i, int buy, vector<int>&prices, int n,int fee)
{
    if(i==n) return 0;

    if(buy) return max(-prices[i]+recurs(i+1,0,prices,n,fee),0+recurs(i+1,1,prices,n,fee));

    // because transaction fee will be deducted only in the case of buy and sell combo!    
    return max(prices[i]+recurs(i+1,1,prices,n,fee)-fee,0+recurs(i+1,0,prices,n,fee));
}
int memoiz(int i, int buy, vector<int>&prices, int n, vector<vector<int>>&dp, int fee)
{
    if(i==n) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];

    int ans=0;

    if(buy) ans = max(-prices[i]+memoiz(i+1,0,prices,n,dp,fee),0+memoiz(i+1,1,prices,n,dp,fee));

    // because transaction fee will be deducted only in the case of buy and sell combo!
    else ans = max(prices[i]+memoiz(i+1,1,prices,n,dp,fee)-fee,0+memoiz(i+1,0,prices,n,dp,fee));

    return dp[i][buy]= ans;
}
int tabul(vector<int>&prices,int n, int fee)
{
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy)
            {
                dp[i][buy] = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
            }
            // because transaction fee will be deducted only in the case of buy and sell combo!
            else dp[i][buy] = max(prices[i]+ dp[i+1][1] - fee, 0 + dp[i+1][0]);
        }
    }
    return dp[n][1];
}
int main()
{
    int n; cin>>n;
    int fee; cin>>fee;
    vector <int> prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];

    // cout << recurs(0,1,prices,n,fee);

    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // cout << memoiz(0,1,prices,n,dp,fee);

    cout<<tabul(prices,n,fee);
}