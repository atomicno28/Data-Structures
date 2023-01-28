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
                return arr[mid];
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
        return arr[0];
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // array must be sorted;

    cout << count(v,n);
}