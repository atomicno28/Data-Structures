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
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    int j=0;
    for(int i=0;i<n;i++)
    {
        minHeap.push(v[i]);
        if(minHeap.size()>k)
        {
            v[j]=minHeap.top();
            minHeap.pop();
            j++;
        }
    }
    while(!minHeap.empty())
    {
        v[j]=minHeap.top();
        minHeap.pop();
        j++;
    }
    for(auto i:v) cout<<i<<" ";
}