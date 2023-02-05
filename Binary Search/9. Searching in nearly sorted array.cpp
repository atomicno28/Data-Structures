#include<iostream>
#include<vector>
using namespace std;
int searching(vector<int> &arr, int n, int target)
{
    int start=0,end=n-1;

    while(start<=end)
    {
        int mid = start + (end-start)>>1;

        if(target==arr[mid]) return mid;
        if(mid-1>=start && arr[mid-1]==target) return mid-1;
        if(mid+1<=end && arr[mid+1]==target) return mid+1;

        else if(target<arr[mid]) end=mid-2;
        else if(target>arr[mid]) start=mid+2;
    }

    return -1;
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int target; cin>>target;

    cout << searching(arr,n,target);
}