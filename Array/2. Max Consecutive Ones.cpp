#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int cnt=0,maxi=0;

    for(auto i:v)
    {
       if(i==1) cnt++;
       else cnt=0;

       maxi=max(cnt,maxi);
    }

    cout << maxi;
}