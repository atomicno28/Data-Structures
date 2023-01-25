#include<iostream>
#include<string>
#include<vector>
using namespace std;
int recurs(int i, int j, string&a,string&b)
    {
        
       if(i<0) return 1+j;
       if(j<0) return i+1;
        
        if(a[i]==b[j])
        {
            return  0 + recurs(i-1,j-1,a,b);
        }
        else return 1 + min(min(recurs(i-1,j,a,b),recurs(i-1,j-1,a,b)),recurs(i,j-1,a,b));
    }
int memoiz(int i, int j, string&a,string&b, vector<vector<int>>&dp)
    {
        
       if(i<0) return 1 + j ;
       if(j<0) return i + 1 ;
        
       if(dp[i][j]!=-1) return dp[i][j];
       if(a[i]==b[j])
        {
            return dp[i][j]= 0 + memoiz(i-1,j-1,a,b,dp);
        }
        else return dp[i][j] = 1 + min(min(memoiz(i-1,j,a,b,dp),memoiz(i-1,j-1,a,b,dp)),memoiz(i,j-1,a,b,dp));
    }
 int tabul(string&a,string&b)
    {
        int m=a.size();
        int n=b.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=0;i<=n;i++) dp[0][i]=i;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
int main()
{
    string a,b; cin>>a>>b;
    int m=a.size(),n=b.size();

    // cout << recurs(m-1,n-1,a,b);

    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout << memoiz(m-1,n-1,a,b,dp);

    cout <<tabul(a,b);
}