#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void summ(int i,int n, int sum, vector<int>&arr, vector<int>&res)
{
    if(i==n)
    {
        res.push_back(sum);
        return;
    }

    //pick the element.
    summ(i+1,n,sum+arr[i],arr,res);

    // do not pick.
    summ(i+1,n,sum,arr,res);
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> res;

    summ(0,n,0,arr,res);

    for(auto i:res) cout<<i<<' ';
}