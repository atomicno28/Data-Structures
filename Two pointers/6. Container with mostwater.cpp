#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int start=0,end=n-1;
    int area=0,maxarea=0;

    while(start<end)
    {
        // find minimum b/w start and end, then store in the multiply by the separation.
        area=((long long)min(arr[start],arr[end])*(end-start))%INT_MAX;
        
        if(area>maxarea) maxarea=area;

        // iterate on the basis of minimum.
        if(arr[start]<=arr[end]) start++;
        else end--;
    }

    cout << maxarea;

}