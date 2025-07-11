// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// if (nums[left] == nums[mid] == nums[right]): Either left or right half is sorted
// if (nums[left] == nums[mid] < nums[right]): The entire array is sorted
// if (nums[left] == nums[mid] > nums[right]): The left half is sorted
// if (nums[left] < nums[mid] == nums[right]): The entire array is sorted
// if (num[left] < nums[mid] < nums[right]): The entire array is sorted
// If (nums[left] < nums[mid] > nums[right]): The left half is sorted
// if (nums[left] > nums[mid] == nums[right]): The right half is sorted
// if (nums[left] > nums[mid] < nums[right]): The right half is sorted
// if (nums[left] > nums[mid] > nums[right]): Invalid: because at least one half should be sorted
//
// We can simply if as:
// if (nums[left] == nums[mid] == nums[right]): Either left or right half is sorted
// else if (nums[left] <= nums[mid]): The left half is sorted
// else: The right half is sorted

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
