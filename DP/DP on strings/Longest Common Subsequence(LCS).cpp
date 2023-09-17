#include<iostream>
#include<vector>
using namespace std;
 int recurs(int ind1, int ind2, string &s1, string &s2)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        
        
        if(s1[ind1]==s2[ind2])  return 1 + recurs(ind1-1,ind2-1,s1,s2);
        else return 0 + max(recurs(ind1-1,ind2,s1,s2),recurs(ind1,ind2-1,s1,s2));
    }
 int memoiz(int ind1, int ind2, string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])  return dp[ind1][ind2] =  1 + memoiz(ind1-1,ind2-1,s1,s2,dp);
        else return dp[ind1][ind2] = 0 + max(memoiz(ind1-1,ind2,s1,s2,dp),memoiz(ind1,ind2-1,s1,s2,dp));
    }

int tabul(string &s1, string &s2)
{
            
    int n= s1.size();
    int m= s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    // eliminating these two operations.
    //for(int i=0;i<=n;i++) dp[i][0] = 0;
    //for(int i=0;i<=m;i++) dp[0][i] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[n][m];   
}

int main()
{
    string s1,s2; cin>>s1>>s2;
    int ind1 = s1.size(), ind2 = s2.size();

    // cout << recurs(ind1-1,ind2-1,s1,s2);

    // vector<vector<int>> dp(ind1, vector<int>(ind2,-1));
    // cout << memoiz(ind1-1,ind2-1,s1,s2,dp);

    cout << tabul(s1,s2);

}