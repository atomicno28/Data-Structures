#include<iostream>
#include<vector>
using namespace std;
void combo(vector<int>&arr,int i, int n, int sum,vector<int>&ds)
{
    if(i==n)
    {
        if(sum==0) 
        {
            for(auto i:ds) cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    
    //pick
    if(arr[i]<=sum)
    {
        ds.push_back(arr[i]);
        
        //repitions allowed.
        combo(arr,i,n,sum-arr[i],ds);
        ds.pop_back();
    }
    
    combo(arr,i+1,n,sum,ds);
    
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    
    int sum; cin>>sum;
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> ds;
    
    combo(arr,0,n,sum,ds);
    
}