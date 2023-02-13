#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
void storeNSL(vector<int>&arr,vector<int>&NSL, int n)
{
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty()) NSL.push_back(-1);
        else if(!s.empty() && s.top().first<arr[i]) NSL.push_back(s.top().second);
        else if(!s.empty() && s.top().first>=arr[i])
        {
            while(!s.empty() && s.top().first>=arr[i]) s.pop();
            if(s.empty()) NSL.push_back(-1);
            else NSL.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    
}
void storeNSR(vector<int>&arr,vector<int>&NSR, int n)
{
    stack<pair<int,int>> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()) NSR.push_back(n+1);
        else if(!s.empty() && s.top().first<arr[i]) NSR.push_back(s.top().second);
        else if(!s.empty() && s.top().first>=arr[i])
        {
            while(!s.empty() && s.top().first>=arr[i]) s.pop();
            if(s.empty()) NSR.push_back(n+1);
            else NSR.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(NSR.begin(),NSR.end());
    
}
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> NSL;
    vector<int> NSR;
    
    storeNSL(arr,NSL,n);
    storeNSR(arr,NSR,n);
    
    vector<int> width;
    for(int i=0;i<n;i++) width.push_back(NSR[i]-NSL[i]-1);
    
    int maxi=-1e9;
    for(int i=0;i<n;i++) maxi=max(maxi,width[i]*arr[i]);
    cout<<maxi;
}