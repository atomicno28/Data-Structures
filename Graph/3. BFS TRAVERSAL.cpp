
//  1. MAKE A QUEUE
//
//  2. MAKE A UNORDERED_MAP ON <INT,BOOL> VISITED;
//
//  3. EXPLORE ADJACENY LIST LIKEWISE.
//
//
//  ( PROCEDURE )
//  
//  1. check for visit!
//  2. if not then call bfs(i)
//  3. make queue, push(i), true , check until q isn't empty!
//  4. while q!= empty ( front=q.front,pop, push front in ans, )


//   TC -> 0(n)

#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> m;
    vector<int> ans;
    void addEdge()
    {
            int start;
            cout<<"Enter the starting index: ";
            cin>> start;
            int end;
            cout<<"Enter the ending index: ";
             cin>> end;
            m[start].push_back(end);
            m[end].push_back(start);
    } 
    void printEdge()
    {
        for(auto i: m)
        {
            cout<<i.first<<" -> ";
            for( auto j: i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
void bfs(unordered_map<int,list<int>> &m,unordered_map<int,bool> &visited,int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int frontNode= q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: m[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }

    }

}
   void bfstraversal()
   {
    unordered_map<int,bool> visited;
    for(int i=0;i<m.size();i++)
    {
        if(!visited[i])
        {
            bfs(m,visited,i);
        }
    }
   }
};
int main()
{
    int n;
    cin>>n;
    Graph g[n];
    for(int i=0;i<n;i++)
    {
       g[i].addEdge();
    }
}