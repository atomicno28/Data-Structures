#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }

    priority_queue<int,vector<int>,greater<int>> minH;
    vector<int> res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                minH.push(arr[i][j]);
            }
        }
        while(!minH.empty())
        {
            res.push_back(minH.top());
            minH.pop();
        }
        
        for(auto i: res) cout<<i<<" ";
}