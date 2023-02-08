#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Memoization Approach
int kfrog(int n, int k, vector<int> &dp, vector<int> &heights){

    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int mini =INT_MAX;

    for(int i=1;i<=k;i++)
    {
         if(n>=i)
         {
            int minstep = kfrog(n-i,k,dp,heights) + abs(heights[n]-heights[n-i]);
            mini=min(mini,minstep);
         }
    }

    return mini;
}


// Tabulation
int kfrogtab(int n, int k, vector<int> &heights)
{
    vector<int> dp(n); 
    dp[0]=0; // base case

    for(int i=1;i<n;i++){
        int mini=INT_MAX;

        for(int j=1;j<=k;j++)
        {
            if(i<=j)
            {
                int jump=dp[i-j] +abs(heights[i]]-heights[i-j]);
                mini=min(mini,jump);
            }
        }
        dp[i] = mini;
    }

    return dp[n-1];
}
    int main()
{
    int n; cin>>n; vector<int> heights(n);

    for(int i=0;i<n;i++) cin>>heights[i];

    int k; cin>>k;

    vector <int> dp(n+1,-1);
    cout<<kfrog(n-1,k,dp,heights);
}