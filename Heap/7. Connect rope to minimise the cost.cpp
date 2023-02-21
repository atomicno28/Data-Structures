#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    for(auto i: arr) minHeap.push(i);
    
    int cost = 0;
    
    while(minHeap.size()>=2)
    {
        int t= minHeap.top(); minHeap.pop();
        int t2 = t2=minHeap.top(); minHeap.pop();
        
        cost += (t+t2);
        minHeap.push(t+t2);
    }
    
    cout << cost;
}