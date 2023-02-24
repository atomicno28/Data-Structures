#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void replaceWithRank(vector<int> &arr, int N,vector<int> &res){
     
     vector<int> dummy(arr);

     // we can use minHeap for sorting aswell!
     sort(arr.begin(),arr.end());
     
     
     int cnt=1;

     for(int i=0;i<N;i++)
     {
         if(res.size()==0) res.push_back(cnt++);
         else if(arr[i]==arr[i-1]) res.push_back(cnt);
         else res.push_back(cnt++);
     }
     
     map<int,int> mp;
     for(int i=0;i<res.size();i++)
     {
         mp.insert({arr[i],res[i]});
     }
     
     for(int i=0;i<N;i++)
     {
         res[i] = mp[dummy[i]];
     }
     

    }

int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> res;

    replaceWithRank(arr,n,res);

    for(auto i:res) cout<<i<<" ";


}