#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mod=1e9+7;
int recurs( int i, vector<int> &res, int j)
{
    if(i<j) return 0;

    int mini = INT_MAX;

    for (int k=i;k<=j;k++)
    {
        int cost = res[j+1] - res[i-1] + recurs(i,res,k-1)%mod + recurs(k+1,res,j)%mod;
        mini = min(mini,cost);
    }
    return mini;
}
int memoiz( int i, vector<int> &res, int j,vector<vector<int>>&dp)
{
    if(i<j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini = INT_MAX;

    for (int k=i;k<=j;k++)
    {
        int cost = res[j+1] - res[i-1] + memoiz(i,res,k-1,dp)%mod + memoiz(k+1,res,j,dp)%mod;
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
int tabul(vector<int>&cuts, int c)
{
     vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            
            if(i>j) continue;
            
            int mini = INT_MAX;
    
            for(int ind=i; ind<=j; ind++){
        
                int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
        
                mini = min(mini, ans);
        
            }
    
            dp[i][j] = mini;
        }
    }
    
    return dp[1][c];
}
int main()
{
    int n; cout<<"Enter the size of array: ";cin>>n;
    vector<int> arr(n);

    int size; cout<<"Enter the size of stick: ";cin>>size;

    for(int i=0;i<n;i++) cin>>arr[i];

    // Add '0' and 'size' in the array!
    // Sort them!

    arr.push_back(0);
    arr.push_back(size);

    sort(arr.begin(),arr.end());

    // cout << recurs(1,arr,arr.size()-2);

    // vector<vector<int>> dp(res.size(),vector<int>(res.size(),-1));
    // cout<< memoiz(1,arr,arr.size()-2,dp);

    int c= arr.size()-2;
    cout << tabul(arr,c);

}