#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LCsubstring(string&a, string&b)
{
    int m = a.size();
    int n= b.size();

    int ans=0;

    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int i=0;i<=n;i++) dp[0][i]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
              if(a[i-1]==b[j-1]) 
              {
                dp[i][j] =  1 + dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
              }
              else dp[i][j] = 0;
        }
    }

    return ans;
}
int main()
{
    string a,b; cin>>a>>b;
    cout << LCsubstring(a,b);
}