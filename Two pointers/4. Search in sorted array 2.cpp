#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    int k=0;

    for(int i=2;i<n;i++)
    {
        if(nums[i]!=nums[k])
        {
            nums[k+2]=nums[i];
            k++;
        }
    }

    cout << k + 2;

    
}