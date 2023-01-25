#include<iostream>
#include<vector>
using namespace std;
int tabul(vector<int>&v, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int prev=i-1;prev>=-1;prev--)
        {
            int pick =0;
            if(prev==-1 || v[i]>v[prev+1]) pick = 1 + dp[i+1][i+1];
            int notpick =  0 + dp[i+1][prev+1];
            dp[i][prev+1] = max(pick,notpick);
        }
    }
    return dp[0][0];
}
int spaceOptimised(vector<int>&v, int n)
{
    vector<int>dp(n,1);

    int maxi=0;

    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(dp[prev]<v[i]) dp[i] = max(dp[i],1+dp[prev]);
            maxi = max(dp[i],maxi);
        }
    }

    return maxi;
}
int main()
{
    int n; cin>>n; vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // cout << tabul(v,n);

    cout <<spaceOptimised(v,n);
}