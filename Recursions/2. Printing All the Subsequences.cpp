#include<iostream>
#include<vector>
using namespace std;
void subseq(vector<int>&arr, int i,int j, vector<int>&ds)
{
    if(i>=j)
    {
        for(auto i:ds) cout<<i<<" ";
        cout<<endl;
        return;
    }
    
    //pick
    ds.push_back(arr[i]);
    subseq(arr,i+1,j,ds);
    
    //notpick
    ds.pop_back();
    subseq(arr,i+1,j,ds);
}
int main()
{
   int n; cin>>n;
   vector<int> arr(n);
   
   for(int i=0;i<n;i++) cin>>arr[i];
   
   vector<int> ds;
   
   subseq(arr,0,n,ds);
}