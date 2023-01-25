#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int algo(string s)
{
    if(s.size()<2) return s.size();
    deque<char> dq;
    dq.push_back(s[0]);
    int ans=0;
    int j=1;
    while(j<s.size())
    {
        if(find(dq.begin(),dq.end(),s[j])==dq.end()) dq.push_back(s[j]);
        else
        {
            while(dq.front()!=s[j]) dq.pop_front();
              dq.pop_front();
              dq.push_back(s[j]);
        }
        ans = (dq.size()>ans)? dq.size():ans;
        j++;
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout << algo(s);
}