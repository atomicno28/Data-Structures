#include<iostream>
#include<vector>
using namespace std;
int countsubs(vector<int>&arr,int i, int j, int s, int sum)
{
     if(s>sum) return 0;
     if(i==j)
     {
        if(s==sum) return 1;
        return 0;
     }

     int l = countsubs(arr,i+1,j,s+arr[i],sum);
     int r = countsubs(arr,i+1,j,s,sum);

     return l+r;
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    int sum; cin>>sum;

    cout << countsubs(arr,0,n,0,sum);
}