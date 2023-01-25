#include<iostream>
#include<vector>
using namespace std;
int recurs(int ind, vector<int>&coins, int amount)
    {
       if(ind==0){ return (amount%coins[ind]==0);}
        
        int nottake = recurs(ind-1,coins,amount);
        int take = 0;
        if (coins[ind]<=amount) 
{take = recurs(ind,coins,amount-coins[ind]);}
        return take + nottake;
        
}
int memoiz(int ind, vector<int>&coins, int amount,vector<vector<int>>&dp)
    {
       if(ind==0){ return (amount%coins[ind]==0);}

       if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int nottake = recurs(ind-1,coins,amount);
        int take = 0;
        if (coins[ind]<=amount) take = recurs(ind,coins,amount-coins[ind]);
        return dp[ind][amount] = take + nottake;
        
}
int main()
{
    int n; cin>>n; vector<int> coins(n); for(int i=0;i<n;i++) cin>>coins[i];
    int amount; cin>>amount;

    //  cout<< recurs(n-1,coins,amount);

    // vector<vector<int>> dp (n,vector<int>(amount+1,-1));
    // cout << memoiz(n-1,coins,amount,dp);

    vector<vector<int>> dp (n,vector<int>(amount+1,0));
    for(int i=0;i<=amount;i++) dp[0][i] = (i%coins[0]==0);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            int nottake = 0 + dp[i-1][j];
        int take = INT_MAX;

        if(coins[i]<=j)
        {
            take = 1 + dp[i][j-coins[i]];
        }
        dp[i][j] = take+nottake;
        }
    }

    cout << dp[n-1][amount];

}