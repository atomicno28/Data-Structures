#include<iostream>
#include<vector>
using namespace std;
int findPeakElement(vector<int>& nums) 
{
        if(nums.size()==1) return 0;
        int start=0,end=nums.size()-1;
        while(start<=end)
        {
            int mid= start + (end-start)/2;
            if(mid>0 && mid<nums.size()-1)
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
                else if(nums[mid-1]>nums[mid]) end = mid-1;
                else start=mid+1;
            }
            else if(mid==0)
            {
                return (nums[0]>nums[1])?0:1;
            }
            else if(mid==nums.size()-1)
            {
                return (nums[nums.size()-1]>nums[nums.size()-2])? nums.size()-1:nums.size()-2;
            }
        }
        return -1;
}
int findPeakElement2(vector<int> &nums)
{
    int start=0,end=nums.size()-1;
    int ans = -1;

    while(start<end)
    {
         int mid = start + (end-start)/2;
         if(nums[mid+1]>nums[mid]) start=mid+1,ans=mid+1;
         else end=mid;
    }
    return ans;
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
    
    //cout << findPeakElement(v);

    cout << findPeakElement(v);
}