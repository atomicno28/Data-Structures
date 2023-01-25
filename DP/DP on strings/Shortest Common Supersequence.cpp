#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LCS(string &s1, string &s2)
{
            
    int n= s1.size();
    int m= s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    
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
    string a,b; cin>>a>>b;

    // to print the length of string we'll follow
    //cout << a.size()+b.size()-LCS(a,b);

     int n= a.size();
    int m= b.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string result="";

    int i=m,j=n;
    while(i>0 &&j>-0)
    {
        if(a[i-1]==b[j-1])
        {
            result.push_back(a[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            result.push_back(a[i-1]);
            i--;
        }
        else
        {
           result.push_back(b[j-1]);
           j--;
        }
    }
    while(i>0) result.push_back(a[i-1]);
    while(j>0) result.push_back(b[j-1]);

    reverse(result.begin(),result.end());

    cout <<result;  
    
}