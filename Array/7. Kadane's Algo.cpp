#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int sum=0,maxi=-1e9;

    for(auto i: arr)
    {
        sum+=i;
        maxi=max(maxi,sum);

        // just add this one line to handle negative edge cases.
        if(sum<0) sum=0;
    }

    cout << maxi<<endl;
}