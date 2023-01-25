#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool recurs(int i,int j, string&s,string&p)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int ind=0;ind<=i;ind++)
            {
              if(s[ind]!='*') return false;
            }
            return true;
        }
        
        if(s[i]==p[j] || s[i]=='?') return  recurs(i-1,j-1,s,p);
        if(s[i]=='*') return recurs(i-1,j,s,p) || recurs(i,j-1,s,p);
        return false;
        
    }
bool memoiz(int i,int j, string&s,string&p,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int ind=0;ind<=i;ind++)
            {
              if(s[ind]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || s[i]=='?') return dp[i][j] = memoiz(i-1,j-1,s,p,dp);
        if(s[i]=='*') return dp[i][j] = memoiz(i-1,j,s,p,dp) || memoiz(i,j-1,s,p,dp);
        return  dp[i][j]= false;
        
    }
int main()
{
    string a,b; cin>>a>>b;

    int m = a.size();
    int n = b.size(); 

    // cout << recurs(m-1,n-1,a,b)? "YES":"N0";

//    vector<vector<int>>dp(m,vector<int>(n,-1));
//    cout<< memoiz(m-1,n-1,a,b,dp)? "YES":"NO";

   

}