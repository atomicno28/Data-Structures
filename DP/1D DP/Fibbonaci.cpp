#include<iostream>
#include<vector>
using namespace std;
int fibbo(int n, vector<int> &dp){
    if( n<=1) return 1;
    
    if(dp[n]!=-1) return dp[n]; // check for overlapping subproblems.

    return dp[n] = fibbo(n-1,dp) + fibbo(n-2,dp);
}
int main()
{

    int n; cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<< fibbo(n,dp);


    // iterative approach 
     int prev=0;
     int prev1 =1;
     for(int i=2;i<= n;i++)
     {
        int curr=prev+prev1;
        prev=prev1;
        prev1=curr;
     }

     cout<< prev1;

}