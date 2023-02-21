#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[left];
    }
int main()
{
    int n; cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    cout << singleNonDuplicate(nums);
}