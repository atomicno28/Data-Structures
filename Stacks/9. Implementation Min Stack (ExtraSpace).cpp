#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int>s;
stack<int>ss;
void push(int a)
{
    s.push(a);
    if(ss.empty() || a>=ss.top()) ss.push(a);
}
int pop()
{
    if(s.empty()) return -1;
    int tmp = s.top();
    s.pop();
    if(tmp==ss.top()) ss.pop();
    return tmp;
}
int getMin()
{
    if(ss.empty()) return -1;
    return ss.top();
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++) cin>>v[i];
    
    for(int i=0;i<n;i++)
    {
        push(v[i]);
    }
}