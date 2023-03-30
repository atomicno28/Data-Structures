#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector <int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int mini=1e9;
    int maxi=0;

    for(auto i: arr)
    {
        mini= min(mini,i);
        maxi= max(maxi,i-mini);
    }

    cout<<maxi<<endl;

}