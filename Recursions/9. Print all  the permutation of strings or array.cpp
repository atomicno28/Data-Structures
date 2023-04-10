#include<iostream>
#include<vector>
using namespace std;
void perm(vector<int>&arr,vector<int>&ds,vector<vector<int>>&res,vector<int>&visited)
{
    // if the size of ds is full.
    if(ds.size()==arr.size())
    {
        res.push_back(ds);
        return;
    }
    
    for(int i=0;i<arr.size();i++)
    {
        if(!visited[i])
        {

            ds.push_back(arr[i]);

            // element is visited.
            visited[i]=1;
            perm(arr,ds,res,visited);

            // unset the visited.
            visited[i]=0;
            ds.pop_back();
        }
    }
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<vector<int>>res;
    vector<int> ds;

    // visited array.
    vector<int> visited(n,0);
    
    perm(arr,ds,res,visited);
    
    for(auto i:res)
    {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}