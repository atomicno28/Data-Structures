#include<iostream>
#include<vector>
using namespace std;
int RbSearch(vector<int> &v,int target, int n)
{
    int start=0,end=n-1;

    // this way we can prevent the integer overflow issue!
    int mid = (start+((end-start)/2));
    while(start<=end)
    {
        if(v[mid]==target) return mid;
        else if(v[mid]<target) end=mid-1;
        else start=mid+1;                         
    
        mid = (start+((end-start)/2));
    }
    return -1;
}
int bSearch(vector<int> &v,int target, int n)
{
    int start=0,end=n-1;

    // this way we can prevent the integer overflow issue!
    int mid = (start+((end-start)/2));
    while(start<=end)
    {
        if(v[mid]==target) return mid;
        else if(v[mid]<target)  start=mid+1;
        else end=mid-1;          
        
        mid = (start+((end-start)/2));
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int target; cin>>target;

    int index=-1;
    
    if(v[0]<v[n-1]) index = bSearch(v,target,n);
    else  index = RbSearch(v,target,n);

    cout << index;

  
}