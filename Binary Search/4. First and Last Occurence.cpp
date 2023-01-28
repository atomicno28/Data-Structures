#include<iostream>
#include<vector>
using namespace std;
int bSearch(vector<int> &v, int target, int n, int flag, int &res)
{
    int start=0,end=n-1,mid=(start+((end-start)/2));
    while(start<=end)
    {
        if(target==v[mid])
    {
        res=mid;
        if(flag) start=mid+1;
        else end=mid-1;
    }
    else if(target<v[mid]) end=mid-1;
    else start=mid+1;
    mid= (start+((end-start)/2));

    }

    return res;
}
int main()
{
    int n; cin>>n; 
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];
    
    int target; cin>>target;

    int res=-1;
    int low= bSearch(v,target,n,0,res);
    res =-1;
    int high= bSearch(v,target,n,1,res);

    cout << low << " " << high;
}