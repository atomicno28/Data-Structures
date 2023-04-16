#include<iostream>
#include<vector>
using namespace std;
void fix(vector<int>&nums)
{
        int n = nums.size();
        vector<int> left(n); left[0]=0;
        vector<int> right(n); right[n-1]=0;

         for(int i=1;i<n;i++)
         {
             left[i]=nums[i-1] +left[i-1];
         }
         for(int i=n-2;i>-1;i--)
         {
             right[i]=right[i+1] + nums[i+1];
         }

         for(int i=0;i<n;i++) nums[i] = abs(left[i]-right[i]);

}
int main()
{
    int n; cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    fix(nums);

    for(auto i:nums) cout<<i<< ' ';
}