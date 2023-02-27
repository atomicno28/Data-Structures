#include<iostream>
#include<vector>
using namespace std;
bool check(vector<vector<int>>&arr, int m, int n, int target)
{
    int i=0,j=n-1;
    
    // we'll check from the top right element!
    
    while(j>=0 && i<n)
    {
        if(target==arr[i][j]) return 1;
        else if(target>arr[i][j]) i++;
        else j--;
    }
    
    return 0;
}
int main()
{
    int m,n; cin>>m>>n;
    
    vector<vector<int>> arr(m,vector<int>(n));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    
    int target; cin>>target;
    
    if(check(arr,m,n,target)) cout<<"Present";
    else cout<<"Not Present";
    
}