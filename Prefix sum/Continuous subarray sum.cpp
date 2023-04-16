#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>&nums,int k)
{
    for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0 && nums[i-1]==0) return 1;
        }

        for(int i=1;i<nums.size();i++)
        {
            nums[i]= nums[i-1] + nums[i];
            if(nums[i]%k==0) return 1;

            int j=i-2;
            while(j>=0 && nums[i]-nums[j]>=k)
            {
                if((nums[i]-nums[j])%k==0) return 1;
                j--;
            }
        }
        return 0;
}
int main()
{
    int n,k; cin>>n>>k;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    check(nums,k);
}