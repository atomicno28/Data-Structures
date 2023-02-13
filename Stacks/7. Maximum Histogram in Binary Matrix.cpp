#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int MAH(vector<int> arr, int n)
{
    vector<int> NSR,NSL;
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
    while(!s.empty()) s.pop();
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()) NSR.push_back(n);
        else if(!s.empty() && s.top().first<arr[i]) NSR.push_back(s.top().second);
        else if(!s.empty() && s.top().first>=arr[i])
        {
            while(!s.empty() && s.top().first>=arr[i]) s.pop();
            if(s.empty()) NSR.push_back(n);
            else NSR.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(NSR.begin(),NSR.end());
    
    vector<int> width;
    for(int i=0;i<n;i++) width.push_back(NSR[i]-NSL[i]-1);
    
    int maxi=-1;
    for(int i=0;i<n;i++) maxi=max(maxi,width[i]*arr[i]);
    return maxi;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    
    vector<int> temp(n);
    
    for(int i=0;i<n;i++) temp.push_back(arr[0][i]);
    
    int mx= MAH(temp,n);
    
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]) temp[j]+=arr[i][j];
            else temp[j]=0;
        }
      mx = max(mx,MAH(temp,n));
    }
    
    cout << mx;
}