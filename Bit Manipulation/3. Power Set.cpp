#include<iostream>
#include<vector>
using namespace std;

void algo(vector<vector<int>>&res, vector<int>&v,int bits)
{
    for(int i=1;i<bits;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if((i>>j)&1)
            {
                res[i].push_back(v[j]);
            }
        }
    }
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    // either print the all possible subsequence
    // or store in 2-D vector;

    int bits = 1<<n;
    vector<vector<int>> res(bits);
    algo(res,v,bits);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout <<endl;
    }
}