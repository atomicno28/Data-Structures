#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define pi pair<int,vector<int>>
using namespace std;
void kClosest(vector<vector<int>>& points, int k,vector<vector<int>>&res) {

       priority_queue<pi,vector<pi>, greater<pi>> minHeap;
       for(int i=0;i<points.size();i++)
       {
           minHeap.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
       }
       int m = k;
       
       while(m)
       {
           res.push_back({minHeap.top().second[0],minHeap.top().second[1]});
           minHeap.pop();
           m--;
       }
       
    }
int main()
{

  int n; cin>>n;
  vector<vector<int>>points(n,vector<int>(2));
  for(int i=0;i<n;i++)
  {
    cin>>points[i][0];
    cin>>points[i][1];
  }

  int k; cin>>k;
  vector<vector<int>>res;

  kClosest(points,k,res);

  for(int i=0;i<res.size();i++)
  {
    cout<<res[i][0]<<" "<<res[i][1]<<endl;
  }
}
