#include<bits/stdc++.h>
using namespace std;
void missingNduplicate(vector<int>&arr, int n)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]!=arr[arr[i]-1]) swap(arr[i],arr[arr[i]-1]);
        else i++;
    }
    for(int i=0;i<n;i++)
    {
        if(i+1!=arr[i])
        {
            cout<<"Missing Number: "<<i+1<<endl;
            cout<<"Duplicate Number: "<<arr[i];
            break;
        }
    }
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    missingNduplicate(arr,n);
}