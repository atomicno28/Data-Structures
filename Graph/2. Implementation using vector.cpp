#include<bits/stdc++.h>
using namespace std;
class Graph
{
   public:
   void addEdge(int n,int m,vector<vector<int>> & edges, vector <vector<int>> &v)
   {
      // ADDING EDGES 

      vector<int> ans[n];
      for (int i = 0; i < m; i++)
      {
        int u= edges[i][0];
        int v= edges[0][i];
        ans[u].push_back(v);
        ans[v].push_back(u);
      }
      
      // ADJACENCY LIST

      for(int i=0; i<n;i++)
      {
         v[i].push_back(i);
         for (int j = 0; j < ans[i].size(); j++)
         {
            /* code */
            v[j].push_back(ans[i][j]);
         } 
      }
   }
};
int main()
{
  vector <vector<int>> v;
}