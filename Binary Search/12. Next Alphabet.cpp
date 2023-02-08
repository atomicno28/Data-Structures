#include<iostream>
#include<string>
#include<vector>
using namespace std;
void nextAlphabet(int target, int n, vector<char> &arr, int &res)
{
    int start=0,end = n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==target)start=mid+1;
        if(target>arr[mid]) start= mid+1;
        else{
            res=mid;
            end=mid-1;
        }
    }
    
}
int main()
{
    int n; cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    char target; cin>>target;

    int res=-1;
    nextAlphabet(target,n,arr,res);
    cout << res;
}