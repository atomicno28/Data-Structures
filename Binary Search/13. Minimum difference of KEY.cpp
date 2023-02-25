#include<bits/stdc++.h>
using namespace std;
int minElement(vector<int>&arr, int target, int n)
{
    int start=0,end=n-1;
    int mid= start + (end-start)/2;
    
    while(start<=end)
    {
        if(target==arr[mid]) return arr[mid];
        else if(target>arr[mid]) start=mid+1;
        else end=mid-1;
        mid = start+(end-start)/2;
    }
    if(abs(target-arr[start])<abs(target-arr[end]))
    {
        return arr[start];
    }
    return arr[end];
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
    
    int target; cin>>target;
    
    cout<< minElement(v,target,n);
    
}