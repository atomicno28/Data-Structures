#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    
    string a; cin>>a;
    
    int n = a.size();
    
    string word; cin>>word;

    int k=word.size();

    map<char,int> mp;
        
    for(auto &i : word) mp[i]++; // filing the value of words!

    int i=0,j=0,count=mp.size();

    int ans=0;

    while(j<n)
    {
        auto it = mp.find(a[j]);
        if(it!=mp.end()) mp[a[j]]--;
        if(mp[a[j]]==0) count--;

        if(j-i+1 < k) j++; 

        // when the window reached its destination
        if(j-i+1 == k)
        {
            // if the string is found then iterate the count of the answer!
            if(count==0) ans++;

           auto it= mp.find(a[i]);
           
           // increase the count of emitted i;
           if(it!=mp.end()) mp[a[i]]++;
           
           if(mp[a[i]]==1) count++;
           i++; j++;
        }
    }

    cout <<ans;

}