#include<iostream>
#include<vector>
using namespace std;
int algo(vector<int>&nums, int k)
{
        if(k<0) return 0;
        int i=0,j=0,cnt=0,ans=0;
        while(j<nums.size())
        {
            if(nums[j]&1) cnt++;
            while(cnt>k)
            {
                if(nums[i]&1) cnt--;
                i++;
            }
            ans+= (j-i+1);
            j++;
        }
        return ans;
}
int numberOfSubarrays(vector<int>& nums, int k) 
{
        return algo(nums,k)-algo(nums,k-1);
}
int main()
{
    int n; cin>>n;
    vector<int>nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    int target; cin>>target;

    cout << numberOfSubarrays(nums,target);

}