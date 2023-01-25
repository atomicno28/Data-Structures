#include<iostream>
#include<vector>
#include<string>
using namespace std;
int ans(string&s, string&a)
{
     int m= s.size();
        int n= a.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=0;i<=n;i++) dp[0][i]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==a[j-1]) dp[i][j]= 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
}
int main()
{
    string s; cin>>s;
    string a=s;
    reverse(a.begin(),a.end());

    cout << ans(s,a);
}