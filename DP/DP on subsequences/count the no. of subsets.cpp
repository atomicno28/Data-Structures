#include<iostream>
#include<vector>
using namespace std;
int recurs(int i,int target, vector<int>&nums)
{
    if(target==0) return 1;
    if(i==0) return nums[0]==target;

    int nottake = recurs(i-1,target,nums);
    int take = 0;

    if(target>=nums[i]) take = recurs(i-1,target-nums[i],nums);

    return take + nottake;
}
int memoiz(int i,int target, vector<int>&nums,vector<vector<int>>&nums)
{
    if(target==0) return 1;
    if(i==0) return nums[0]==target;

    if(dp[i][target]!=-1) return dp[i][target];

    int nottake = memoiz(i-1,target,nums,dp);
    int take = 0;

    if(target>=nums[i]) take = memoiz(i-1,target-nums[i],nums,dp);

    return dp[i][target] = take + nottake;
}
int main()
{
    int n; cin>>n; vector<int> nums; for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    //  cout<< recurs(n-1,target,nums);

//    vector<vector<int>> dp(n,vector<int>(target+1,-1));
//    cout <<memoiz(n-1,target,nums,dp);

   vector<vector<int>> dp(n,vector<int>(target+1,-1));
   for(int i=0;i<n;i++) dp[i][0] = 1;
   if(target>=nums[0]) dp[0][nums[0]] =1;

   dp[0][0] = (num[0]==0)? 2:1;

   for(int i=1;i<n;i++)
   {
    for(int j=0;j<=target;j++)
    {
        int nottake = dp[i-1][j];
        int take =0;
        if(target>=nums[i]) take = dp[i][j-nums[i]];
        dp[i][j]=take+nottake;
    }
   }
   cout<< dp[n-1][target]; 
}