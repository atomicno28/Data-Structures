#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string s; cout<<"Enter the String: ";cin>>s;

    int k; cout<<"Enter the value of K: "; cin>>k;

    int maxi=-1;
    int i=0,j=0;
    map<char,int> mp;
    while(j<s.size())
    {
        if(mp.find(s[j])==mp.end()) mp.insert({s[j],1});
        else mp[s[j]]++;

        if(mp.size()<k) j++;

        else if(mp.size()==k)
        {
            maxi=max(maxi,j-i+1);
            j++;
        }
        else
        {
            while(mp.size()>k)
            {
                if(mp[s[i]]==1) mp.erase(s[i]);
                else mp[s[i]]--;
                i++;
            }
            j++;
        }
    }

   cout << maxi;
}