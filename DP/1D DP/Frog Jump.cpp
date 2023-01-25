#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization method!
int frogjump(int n, vector<int> &heights, vector<int> &dp){
   if(n==0) return 0;

   if(dp[n]!=-1) return dp[n];

   int left= frogjump(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
   int right=INT_MAX;
   if(n>1) right = frogjump(n-2,heights,dp) + abs(heights[n]-heights[n-2]);

   return dp[n]= min(left,right);
}

// bottom up
int frogjump(int n,vector<int> &heights){
    
    vector<int> dp(n);
    dp[0]=0;
    int first=0,second=INT_MAX;
    for(int i=1;i<n;i++){
      first= dp[i-1]  + abs(heights[i]-heights[i-1]);
      if(i>1) second = dp[i-2] +abs(heights[i]=heights[i-2]);

      dp[i]= min(first,second);
    }

    return dp[n-1];
}
int main(){
    int n; cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    vector<int>dp(n+1,-1);
    cout<< frogjump(n-1,heights,dp);
}