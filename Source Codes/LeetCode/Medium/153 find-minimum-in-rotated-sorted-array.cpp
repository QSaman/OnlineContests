// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// nums[left] < nums[mid] < nums[right]: min is in [left, mid - 1]
// nums[left] < nums[mid] > nums[right]: min is in [mid + 1, right]
// num[left] > nums[mid] < nums[right]: min is in [left, mid]
// nums[left] > nums[mid] > nums[right]: invalid: either half left or half right should be sorted.
// In other words, min is either on the left or right half
// Based on above cases, we can simply it as:
// num[mid] > num[right]: min is in [mid + 1, right]
// num[mid] <= num[right]: min is in [left, mid]

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            const int mid = (left + right) >> 1;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
