#include<iostream>
#include<vector>
#include<map>
using namespace std;
int fruitIntoBasket(vector<int>&fruits,int  n)
{
    if(n<=2) return n;

    map <int, int > mp;
    int i=0,j=0,maxi=0;
    while(j<n)
    {
        mp[fruits[j]]++;
        if(mp.size()<=2) 
        {
            maxi=max(maxi,j-i+1);
            j++;
        }
        else if(mp.size()>2)
        {
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0) mp.erase(mp[fruits[i]]);
            i++; j++;
        }
    }
    return maxi;
}
int main()
{
    int n; cin>>n;
    vector<int> fruits(n);

    for(int i=0;i<n;i++) cin>>fruits[i];

    cout << fruitIntoBasket(fruits,n);
}