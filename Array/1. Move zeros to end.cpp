#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int pointer=0;

    for(int i=0;i<n;i++)
    {
        if(v[i]!=0) swap(v[i],v[pointer]),pointer++;
    }

    for(auto i:v) cout<<i<<" ";
}