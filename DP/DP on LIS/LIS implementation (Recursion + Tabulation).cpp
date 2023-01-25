#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int recurs(int i, int prev, vector<int> &v)
{
    if(i==v.size()) return 0;

    int pick=0;
    if(prev==-1 || v[i]> v[prev]) pick = 1 + recurs(i+1,i,v);
    int notpick = 0 + recurs(i+1,prev,v);

    return max(pick,notpick);
}

int memoiz(int i, int prev, vector<int>&v, vector<vector<int>>&dp)
{
    if(i==v.size()) return 0;

    if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    int pick=0;
    if(prev==-1 || v[i]>v[prev]) pick = 1 + memoiz(i+1,i,v,dp);
    int notpick = 0 + memoiz(i+1,prev,v,dp);

    return dp[i][prev+1] = max(pick,notpick);
}

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // cout <<  recurs(0,-1,v);

    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout << memoiz(0,-1,v,dp);

    
}