#include<iostream>
#include<vector>
using namespace std;
void perm(int i, int n, int window, int sum, int target,vector<int>&arr, vector<int>&ds, vector<vector<int>>&res)
    {
        if(sum==target && ds.size()==window) {res.push_back(ds); return;}
        if (sum>target) return;
        if(i==n)
        {
            if(sum==target && ds.size()==window) res.push_back(ds);
            return;
        }
        if(sum<=target)
        {
            ds.push_back(arr[i]);
            perm(i+1,n,window,sum+arr[i],target,arr,ds,res);
            ds.pop_back();
        }
        perm(i+1,n,window,sum,target,arr,ds,res);

    }

int main()
{
    int window; cin>>window;
    int target; cin>>target;

    vector<int> arr(9);
    for(int i=0;i<9;i++) arr[i]=i+1;

    vector<vector<int>> res;
    vector<int> ds;

    perm(0,9,window,0,target,arr,ds,res);

    for(auto i: res)
    {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }

}