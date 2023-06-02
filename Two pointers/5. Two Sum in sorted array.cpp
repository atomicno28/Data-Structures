#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    int target; cin>>target;

    int i=0,j=n-1;

    vector<int> v;

    while(i!=j)
    {
        if(nums[i]+nums[j]>target) j--;
        else if(nums[i]+nums[j]<target) i++;
        else 
        {
            v.push_back(i+1);
            v.push_back(j+1);
            break;
        }
    }

    cout <<v[0]<<"  "<<v[1];
}