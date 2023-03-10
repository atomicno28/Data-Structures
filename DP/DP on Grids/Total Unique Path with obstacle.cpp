#include<iostream>
#include<vector>
using namespace std;
int mod= (int)(2e9+7);
int memo(int ro,int co,vector<vector<int>>&mat)
{
   vector<vector<int>> dp(ro,vector<int>(co));
   for(int i=0;i<ro;i++)
    {
        for(int j=0;j<co;j++)
        {
            if(mat[i][j]==-1) return 0;
            else if(i==0 && j==0) return 1;
            else{
                int up=0,left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j]= up+left;
            }
        }
    }
    return dp[ro-1][co-1];
   
}
int main()
{
    int ro,co;
     cin>>ro>>co;
     vector<vector<int>> mat(ro, vector<int>(co));
    for(int i=0;i<ro;i++)
    {
        for(int j=0;j<co;j++)
        {
            cin>>mat[ro][co];
        }
    }

  cout<<memo(ro,co,mat);
   

}