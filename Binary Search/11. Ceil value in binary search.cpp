#include<iostream>
#include<vector>
using namespace std;
void cieL(vector<int>&arr, int n, int target, int &res)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==target) {
            res=mid;
            return;
        }
        if(target<arr[mid])
        {
            res=mid;
            end=mid-1;
        }
        else start = mid+1;
    }
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target; cin>>target;

    int res=-1;
    cieL(arr,n,target,res);
    cout <<res;
}