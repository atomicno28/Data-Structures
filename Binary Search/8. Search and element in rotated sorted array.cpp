#include<iostream>
#include<vector>
using namespace std;
int count(vector<int> &arr, int n)
{
    if(n==1) return 0;
    if(arr[0]<arr[n-1]) return 0;

    int start=0;
    int end = n-1;
    int mid = start + (end-start)/2;
    

      while(start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if((arr[mid]<arr[next]) &&(arr[mid]<arr[prev])){
                return mid;
            }
            else if(arr[start]<=arr[mid] && arr[mid]<=arr[end]){
                end=mid-1;
            }
            else{
                if(arr[start]<=arr[mid]){
                start=mid+1;
                }
                else if(arr[mid]<=arr[end]){
                end=mid-1;
            }
            }
             
        }
        return -1;
}
int bsearch(vector<int>&v, int a,int b, int &target)
{
    int start=a,end=b;
    int mid=start+(end-start)>>1;

    while(start<=end)
    {
        if(v[mid]==target) return mid;
        else if(target<v[mid]) end = mid-1;
        else start = mid+1;
        mid = start + (end-start)>>1;
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // array must be sorted;

    int target; cin>>target;


    int ind =  count(v,n);
    int ans= bsearch(v,0,ind-1,target);

    if(ans==-1) cout << bsearch(v,ind,n-1,target);
    else cout << ans;
}