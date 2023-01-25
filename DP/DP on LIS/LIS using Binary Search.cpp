#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// this will take time in 0(N*logN)
int bsearch(vector<int>&heights, int n)
{
    vector<int> temp;
    temp.push_back(heights[0]);

    int length=1;

    for(int i=1;i<n;i++)
    {
        if(heights[i]>temp.back()) 
        {
            length++;
            temp.push_back(heights[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(),temp.end(),heights[i])-temp.begin();
            temp[ind]=heights[i];
        }
    }

    return length;
}
int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cout << bsearch(v,n);
}