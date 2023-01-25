#include<iostream>
#include<vector>
using namespace std;

//memoization
int nonadj(int n, vector<int> &nums, vector<int> &dp)
{
     if(n==0) return nums[n];
     if(n<0) return 0;

     if(dp[n]!=-1) return dp[n];

     int pick = nums[n] + nonadj(n-2,nums,dp);
     int nonpick = 0 + nonadj(n-1,nums,dp);

     return dp[n] = max(pick,nonpick);
}
int main()
{
   int n; cin>>n; vector<int> nums(n); for(int i=0;i<n;i++) cin>> nums[i];
   vector<int> dp(n,-1);

   cout<< nonadj(n-1,nums,dp);

}