#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int a=0,b=0,c=n-1;

    while(b<=c)
    {
        if(v[b]==0) swap(v[a],v[b]),a++,b++;
        else if(v[b]==1) b++;
        else swap(v[b],v[c]),c--;
    }

    for(auto i:v) cout<<i<<" ";

}