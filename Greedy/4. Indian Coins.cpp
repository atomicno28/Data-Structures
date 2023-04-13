#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    int arr[] = {2000,500,200,100,50,20,10,5,2,1};

    int n = 10;

    int target; cin>>target;

    vector<int> res;

    int i=0;

    while(i<n && target)
    {
        if(arr[i]>target) i++;
        else
        {
            res.push_back(arr[i]);
            target -= arr[i];
        }
    }

    for(auto i: res) cout<<i<<" ";
}