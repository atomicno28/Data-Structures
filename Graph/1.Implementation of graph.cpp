#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template <typename T> // generic version of graph using unordered map
class Graph
{
    public:
    unordered_map<T,list<T>> m;
    void addEdge(T u, T v, bool ch)
    {
        m[u].push_back(v);
        if(ch)
        {
            m[v].push_back(u);
        }
    }
    void printEdge()
    {
        for(auto i: m)
        {
            cout<<i.first<<"-> ";
            for(auto j: i.second)
            {
                cout<<j<<" ";
            }
        }
    }

};
int main()
{
    Graph <int> g;
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,1,1);
    g.printEdge();
}