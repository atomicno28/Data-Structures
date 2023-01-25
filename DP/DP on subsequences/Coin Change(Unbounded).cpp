#include<iostream>
#include<vector>
using namespace std;
int recurs(int ind, vector<int>& coins, int amoun)
    {

        if(ind==0)
        {
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        
        // if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int nottake = 0 + recurs(ind-1,coins,amount);
        int take = INT_MAX;
        if(amount>=coins[ind])
        {
            take = 1 + recurs(ind,coins,amount-coins[ind]);
        }
        
        return  (take>=nottake)? nottake:take;
    }

    int memoiz(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp )
    {

        if(ind==0)
        {
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int nottake = 0 + recurs(ind-1,coins,amount,dp);
        int take = INT_MAX;
        if(amount>=coins[ind])
        {
            take = 1 + recurs(ind,coins,amount-coins[ind],dp);
        }
        
        return dp[ind][amount] = (take>=nottake)? nottake:take;
    }
    
    
int main()
{
    int n; cin>>n; vector<int> coins(n); for(int i=0;i<n;i++) cin>>coins[i];
    int amount; cin>>amount;

    // int result = recurs(n-1,coins,amount);
    // return (result>=1e9) -1:result;


    // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // int result = memoiz(n-1,coins,amount,dp);
    // return (result>=1e9)? -1:result;

   vector<vector<int>> dp(n,vector<int>(amount+1,0));
   for(int i=0;i<=amount;i++)
   {
    if(i%coins[0]==0) dp[0][i] = i/coins[0];
    else dp[0][i] = 1e9;
   }

   for(int i=1;i<n;i++)
   {
    for(int j=0;j<=target;j++)
    {
        int nottake = 0 + dp[i-1][j];
        int take = INT_MAX;

        if(coins[i]<=j)
        {
            take = 1 + dp[i][j-coins[i]];
        }
        dp[i][j] = min(nottake,take);
    }
   }

   int result = dp[n-1][amount];
   return (result>=1e9)? -1:result;

}
