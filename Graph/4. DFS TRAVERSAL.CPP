#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> m;
    vector<vector <int>> ans;
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
    void dfs(unordered_map<int, list<int>> &m, unordered_map<int,bool> & visited, int node,vector<int> & temp)
    {
        temp.push_back(node);
        visited[node]=1;
        
        for(auto i: m[node])
        {
            if(!visited[i])
            {
                dfs(m,visited,i,temp);
            }
        }
    }
    void dfstraversal()
    {
        unordered_map<int,bool> visited;
        for(int i=0;i<m.size();i++)
        {
            if(!visited[i])
            {
               vector<int> temp;
               dfs(m,visited,i,temp);
               ans.push_back(temp);
            }
        }
    }
};
int main()
{

}