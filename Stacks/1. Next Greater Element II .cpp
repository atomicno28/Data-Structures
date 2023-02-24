#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
 void nextGreaterElements(vector<int>& nums, vector<int>&v) {
        int n = nums.size();
        stack<int> s;

        // just add this 2 lines of apporach!
        for(int i = n-1;i >= 0; i--){
            s.push(nums[i]);
        }

        
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                v.push_back(-1);
            }else if(!s.empty() && nums[i] >= s.top()){
                while(!s.empty() && nums[i] >= s.top()){
                    s.pop();
                }
                if(s.size() == 0){
                    v.push_back(-1);
                }else{
                    v.push_back(s.top());
                }
            }else if(!s.empty() && nums[i] < s.top()){
                v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
    }
int main()
{
    int n; cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0;i<n;i++) cin>>nums[i];
    
    vector<int> res;
    
    nextGreaterElements(nums,res);
    
    for(auto i:res) cout<<i<<" ";
    
    
    
    
}