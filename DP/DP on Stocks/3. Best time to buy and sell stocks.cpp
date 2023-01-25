#include<iostream>
#include<vector>
using namespace std;
int recurs(int i,int buy, int cap, vector<int>&prices)
{
   if( cap==0 || i==prices.size())  return 0;

   if(buy)
   {
     return max(-prices[i]+recurs(i+1,0,cap,prices), 0 + recurs(i+1,1,cap,prices));
   }
   return max(prices[i]+recurs(i+1,1,cap-1,prices),0+recurs(i+1,0,cap,prices));

}
int memoiz(int i, vector<int> &prices, int buy, int cap, vector<vector<vector<int>>>&dp)
    {
        if(cap==0 || i==prices.size()) return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int ans=0;

        if(buy)
        {
            ans =  max(-prices[i]+memoiz(i+1,prices,0,cap,dp),0+memoiz(i+1,prices,1,cap,dp));
        }
        else ans = max(prices[i]+memoiz(i+1,prices,1,cap-1,dp),0+memoiz(i+1,prices,0,cap,dp));

        return dp[i][buy][cap] = ans;
    }

int tabul(vector<int>&prices)
{
   vector<vector<vector<int>>> dp (prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

   for(int i=prices.size()-1;i>=0;i--)
   {
    for(int buy=0;buy<2;buy++)
    {
        for(int cap=1;cap<3;cap++)
        {
            if(buy) dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
            else dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
        }
    }
   }
   return dp[0][1][2];  
}
int spaceOptimise(vector<int>& prices, int n)
{
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> after(2,vector<int>(3,0));
    
     for(int i=n-1;i>=0;i--)
   {
    for(int buy=0;buy<2;buy++)
    {
        for(int cap=1;cap<3;cap++)
        {
            if(buy) curr[buy][cap] = max(-prices[i]+ after[0][cap],0+after[1][cap]);
            else curr[buy][cap] = max(prices[i]+ after[1][cap-1],0+after[0][cap]);
        }
    }
         after=curr;
   }
   return after[1][2];  
}
int main()
{
    int n; cin>>n;
    vector<int> prices(n);

    for(int i=0;i<n;i++) cin>>prices[i];

    // cout << recurs(0,1,2,prices);

    // vector<vector<vector<int>>> dp (n,vector<vector<int>>(2,vector<int>(3,-1)));
    // cout << memoiz(0,prices,1,2,dp);

    // cout <<tabul(prices);

    cout << spaceOptimise(prices,prices.size());

}