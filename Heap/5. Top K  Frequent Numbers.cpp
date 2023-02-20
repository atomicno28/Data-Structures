#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
 void topKFrequent(vector<int>& nums, int k,vector<int>&ans) {
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>>> mini;
        
        auto it=mp.begin();
        while(it!=mp.end())
        {
            mini.push({it->second,it->first});
            if(mini.size()>k) mini.pop();
            it++;
        }
        while(!mini.empty())
        {
            ans.push_back(mini.top().second);
            mini.pop();
        }

 }
int main()
{
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

     int k; cin>>k;
    
    vector<int> res;
    topKFrequent(v,k,res);

    for(auto i:res) cout<<i<<" ";
}