#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int sum; cin>>sum;

    // subarrays less than k.
    
    int i=0,j=0;
    int currsum=0;

    int ans=0;

    while(j<n)
    {
        currsum+= v[j];

        while(currsum>=sum)
        {
            currsum-=v[i++];
        }

        // add the window size each time.
        ans += (j-i+1);

    }

    cout << ans;


}