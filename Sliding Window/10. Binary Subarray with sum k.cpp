#include<iostream>
#include<vector>
using namespace std;
int algo(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int i=0,j=0,res=0,sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        return res;
    }
int numSubarraysWithSum(vector<int>& nums, int goal) 
{
       return algo(nums,goal)-algo(nums,goal-1);   
}
int main()
{
    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    int goal; cin>>goal;

    cout << numSubarraysWithSum(nums,goal);
}