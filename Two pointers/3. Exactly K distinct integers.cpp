#include<iostream>
#include<vector>
#include<map>
using namespace std;
int atmost(vector<int>&v, int n,int k)
{

    if(k<0) return 0;
    
    int ans=0;
    int i=0,j=0;

    map<int,int> mp;

    while(j<n)
    {
        
        mp[v[j]]++;

        // if map size exceeds K.
        while(mp.size()>k)
        {
            mp[v[i]]--;
            if(mp[v[i]]==0) mp.erase(v[i]);
            i++;
        }

        // store the size of window.
        ans += (j-i+1);
        j++;
    }
    return ans;
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int k; cin>>k;

    // Exact(3) = Atmost(3) - Atmost(2)

    cout << atmost(v,n,k)-atmost(v,n,k-1);


}