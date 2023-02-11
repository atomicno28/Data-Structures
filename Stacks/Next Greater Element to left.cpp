#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextGreaterElement(int n, vector<int>&res)
{
    vector<int> v;
    stack <int> s;
    
    for(int i=0;i<n;i++)
    {
        if(s.empty()) v.push_back(-1);
        else if(!s.empty() && s.top()>res[i]) v.push_back(s.top());
        else if(!s.empty() && s.top()<=res[i])
        {
            while(!s.empty() && s.top()<=res[i])
            {
                s.pop();
            }
            if(s.empty()) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(res[i]);
        cout<< v.back()<<" ";
    }

}
int main()
{
    int n; cin>>n; 
    vector<int> res(n);

    for(int i=0;i<n;i++) cin>>res[i];

    nextGreaterElement(n,res);
}