#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> res(n);
    int pos=0,neg=1;
    

    for(auto i:arr)
    {
        if(i>0) res[pos]=i,pos+=2;
        if(i<0) res[neg]=i,neg+=2;
    }

    for (auto i:res) cout<< i<<" ";
}