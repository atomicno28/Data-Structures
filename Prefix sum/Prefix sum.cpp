#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    
    // an optimised approach.
    for(int i=1;i<n;i++) arr[i]= arr[i]+ arr[i-1];

    for(auto i: arr) cout<<i<<" ";
}