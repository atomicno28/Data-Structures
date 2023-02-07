#include<iostream>
#include<map>
#include<string>
using namespace std;
//variable sized window
int numberofSubstr(string &s, int n)
{
    if(n<3) return 0;
    map<char,int> mp;
    int i=0,j=0,ans=0;
    while(j<n)
    {
        mp[s[j]]++;
        if(mp.size()<3) j++;
        else if(mp.size()==3)
        {
            while(mp.size()==3)
            {
                ans = ans + s.size() -j;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;

    cout << numberofSubstr(s,s.size());
}