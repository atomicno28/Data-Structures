#include<iostream>
#include<string>
#include<vector>
using namespace std;
int MOD = 1e9+7;
int recurs(int ind1,int ind2, string&s, string&t)

    {
        if(ind2<0) return 1;
        if(ind1<0) return 0;
                
        if(s[ind1]==t[ind2])
        {
            return recurs(ind1-1,ind2-1,s,t) + recurs(ind1-1,ind2,s,t);
        }
        else return recurs(ind1-1,ind2,s,t);
        
    }
int memoiz(int ind1,int ind2, string&s, string&t,vector<vector<int>>&dp)

    {
        if(ind2<0) return 1;
        if(ind1<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2])
        {
            return dp[ind1][ind2] = memoiz(ind1-1,ind2-1,s,t,dp) + memoiz(ind1-1,ind2,s,t,dp);
        }
        else return dp[ind1][ind2] = memoiz(ind1-1,ind2,s,t,dp);
        
    }

int tabul(string&s,string&t)
{
    int m=s.size();
    int n=t.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i=0;i<=m;i++) dp[i][0]=1;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]= ((dp[i-1][j-1]+dp[i-1][j])%MOD);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}
int main()
{
    string s,t; cin>>s>>t;
    int m=s.size();
    int n=t.size();

    // cout<< recurs(m-1,n-1,s,t);

    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout << memoiz(m-1,n-1,s,t,dp);

    cout<<tabul(s,t);

}