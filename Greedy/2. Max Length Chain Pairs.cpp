#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// comparator that checks the array.
static bool comp(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}
int main()
{
    int n; cin>>n;

    vector<vector<int>> arr(n,vector<int>(2));

    for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1];

    // sort the array on the basis of 2nd element.
    sort(arr.begin(),arr.end(),comp);

    int count=1;
    int start= arr[0][1];

    for(int i=1;i<n;i++)
    {
        if(arr[i][0]>start)
        {
            count++;
            start=arr[i][1];
        }
    }
    cout << count;
}