    #include<iostream>
    #include<vector>
    using namespace std;
    bool recurs(int i, int target, vector<int>&arr)
    {
        if(target==0) return true;
        if(i==0) return (arr[0]==target);

        bool nottake = recurs(i-1,target,arr);
        bool take= false;
        
        if(target>=arr[i])
        {
            take = recurs(i-1,target-arr[i],arr);
        }

        return take || nottake;
    }
    bool memoiz (int i, int target, vector<int>&arr, vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(i==0) return (a[i]==target);

        if(dp[i][target]!=-1) return dp[i][target];

        bool nottake = memoiz(i-1,target,arr,dp);
        bool take = false;

        if(target>=arr[i])
        {
            take = memoiz(i-1,target-arr[i],arr,dp);
        }

        return dp[i][target] = take || nottake;
    }
    int main()
    {
        int n; cin>>n; vector><int> arr(n);
        for(int i=0;i<n;i++) cin>>arr;
    
        int target; cin>>target;
        // recurs(n-1,target,arr);

        // vector<vector<int> dp(n+1, vector<int>(target+1,-1));
        // memoiz(n-1,target,arr,dp);

        vector<vector<bool>dp(n+1,,vector<bool>(target+1,0));
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(arr[0]<=target)dp[0][arr[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                bool nottake = dp[i-1][j];
                bool take = false;

                if(arr[i]<=target) take = dp[i-1][j-arr[i]];
                dp[i][j] = take || nottake;
            }
        }

        cout<< dp[n-1][target-1];

    }