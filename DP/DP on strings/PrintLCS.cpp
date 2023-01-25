#include<iostream>
#include<vector>
using namespace std;
void printLCS(string &s1,string&s2,string&result)
{
    int m=s1.size();
    int n= s2.size();

    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int i=0;i<=n;i++) dp[0][i]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
              if(s1[i-1]==s2[j-1]) dp[i][j]= 1 + dp[i-1][j-1];
              else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){ result.push_back(s1[i-1]); i--,j--;}
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }

    reverse(result.begin(),result.end());
}
int main()
{
    string s1, s2; cin>>s1>>s2;
    
    string result="";

    printLCS(s1,s2,result);

    cout << result;
}