#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int KthSmallest(vector<int>&v, int target)
{
   priority_queue<int> maxHeap;
   
   for(auto i:v)
   {
      maxHeap.push(i);
      if(maxHeap.size()>target) maxHeap.pop();
   }
   return maxHeap.top();
}

int KthLargest(vector<int>&v, int target)
{
      priority_queue<int,vector<int>,greater<int>> minHeap;

      for(auto i:v)
      {
         minHeap.push(i);
         if(minHeap.size()>target) minHeap.pop();
      }
      return minHeap.top();
}
int main()
{
   int n; cin>>n;
   vector<int> v(n);

   for(int i=0;i<n;i++) cin>>v[i];

   int target; cin>>target;

   cout << KthSmallest(v,target);

   cout<< KthLargest(v,target);
}
