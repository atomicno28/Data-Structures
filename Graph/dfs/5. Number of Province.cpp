#include<iostream>
#include<vector>
using namespace std;
void dfs(int node, vector<bool>&visited,vector<vector<int>>&adjMat)
{
     visited[node]=1;
        for(int i=0;i<adjMat.size();i++)
        {
            if(i==node) continue;
            else
            {
               if(i==node) continue;
               else if(adjMat[node][i])
               {
                   if(!visited[i]) dfs(i,visited,adjMat);
               }
            }
        }
}
int main()
{
    int n; cin>>n;
    vector<vector<int>> adjMat(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>adjMat[i][j];
    }

    int count =0;

    vector<bool> visited(n,0);

    for(int i=0;i<n;i++)
    {
        if(!visited[i]) dfs(i,visited,adjMat),count++;
    }

    cout << count;

}