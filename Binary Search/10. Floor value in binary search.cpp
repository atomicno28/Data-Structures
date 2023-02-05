#include<iostream>
#include<vector>
using namespace std;
void flooR(vector<int>&arr, int target, int n, int &res)
{
    int start =0;
    int end =n-1;
    

    while(start<=end)
    {
        int mid = start + (end-start)>>1;
        if(arr[mid]==target){res=mid; return;}
        if(target>arr[mid]){res=mid;start=mid+1;}
        else end = mid-1;
       
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
    flooR(arr,target,n,res);
    cout << res;
}