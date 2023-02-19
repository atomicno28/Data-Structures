#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>&nums)
{
    int ans=0;
    for(int i=0;i<nums.size();i++) ans= (ans^i^nums[i]);
    ans = ans^nums.size();
    return ans;
}
int main()
{
     int n; cin>>n;
     vector<int> nums(n);

     for(int i=0;i<n;i++) cin>>nums[i];
     
     cout << missingNumber(nums);
}