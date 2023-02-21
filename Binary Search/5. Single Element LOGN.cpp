#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                end = mid;
            } else {
                start = mid + 2;
            }
        }
        return nums[start];
    }
int main()
{
    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    cout << singleNonDuplicate(nums);
}