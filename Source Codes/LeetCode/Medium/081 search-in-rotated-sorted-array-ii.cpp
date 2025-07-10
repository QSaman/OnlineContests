// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// In a rotated sorted array either the left half or the right half is sorted. Because there may 
// be duplication, there are cases that we don't know which half is sofrted. For example:
// [1, 0, 1, 1, 1] or [1, 1, 1, 0, 1]. However in [1, 1, 0, 1, 1] the right half is sorted. In genral:
// if (nums[left] == nums[right] && nums[mid] < nums[right]): The right half is sorted
// if (nums[left] == nums[right] && nums[mid] > nums[left]): The left half is sorted
// if (nums[left] == nums[right] && nums[mid] == nums[left]): Either left or right half is sorted

#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            const int mid = (left + right ) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) // In [3, 3, 0, 3, 3], the right half is sorted
                ++left, --right;
            else if (nums[left] <= nums[mid]) // left half is sorted
            {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else    //right half is sorted
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;        
    }
};
