#include<iostream>
#include<vector>
using namespace std;
int recurs(int ind, vector<int>&profit, vector<int>&weight, int target)
{
    if(ind==0)
    {
        return ((target/weight[0])*profit[0]);
    }

    int nottake = recurs(ind-1,profit,weight,target);
    int take = 0;
    if(target>=weight[ind]) take = recurs(ind,profit,weight,target-profit[ind]);

    return max(take,nottake);
}
int memoiz(int ind, vector<int>&profit, vector<int>&weight, int target,vector<<vector<int>>&dp)
{
    if(ind==0)
    {
        return ((target/weight[0])*profit[0]);
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int nottake = recurs(ind-1,profit,weight,target,dp);
    int take = 0;
    if(target>=weight[ind]) take = recurs(ind,profit,weight,target-profit[ind],dp);

    return dp[ind][target] =  max(take,nottake);
}
int main()
{
    int n; cin>>n; vector<int> profit(n),weight(n);
    for(int i=0;i<n;i++) cin>>profit[i];
    for(int i=0;i<n;i++) cin>>weight[i];

    int target; cin>>target;

    // cout<<  recurs(n-1,profit,weight,target);

    // vector<vector<int>> dp (n,vector<int>>(target+1,-1));
    // cout << memoiz(n-1,profit,weight,target);
   
     vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=weight[0];i<=w;i++)
  {
     dp[0][i] = ((int)(i/weight[0]))*profit[0];
  }
  for(int i=1;i<n;i++)
 {
    for(int j=0;j<=w;j++)
         {
          int nottake = dp[i-1][j];
          int take = 0;
          if(weight[i]<=j) take = profit[i] + dp[i][j-weight[i]];
          dp[i][j] = max(take,nottake);
         }
 }
    cout << dp[n-1][w];

}