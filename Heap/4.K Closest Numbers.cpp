#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    int k; cin>>k;
    int x; cin>>x;
    
    priority_queue<pair<int,int>> maxHeap;
    
    for(int i=0;i<n;i++)
    {
        maxHeap.push({abs(v[i]-x),v[i]});
        
        if(maxHeap.size()>k) maxHeap.pop();
    }
    
    while(!maxHeap.empty())
    {
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
    
    
}