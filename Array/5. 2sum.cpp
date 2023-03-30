#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp.insert({nums[i],{i}});
            }
            else mp[nums[i]].push_back(i);
        }
        for(auto i:mp)
        {
            if((target-(i.first))==i.first && i.second.size()>=2) return {i.second[0],i.second[1]};
            else if(mp.find(target-(i.first))!=mp.end()) return {i.second[0],mp[target-i.first][0]};
        }
        return {};
    }
int main()
{
    int n; cin>>n;

    vector<int > arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int target; cin>>target;

    vector<int> ans(twoSum(arr,target));

    cout<< ans[0]<<" "<<ans[1];

}