// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// In rotated sorted array either the left half or the right half is sorted. We use this fact
// to find the target in O(logn):
//
// if (nums[left] < nums[mid] < nums[right]): all array is sorted
// if (nums[left] < nums[mid] > nums[right]): The left half is sorted
// if (nums[left] > nums[mid] < nums[right]): The right half is sorted
// if (nums[left] > nums[mid] > nums[right]): invalid. At least one half should be sorted

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {            
            int mid = (left + right ) >> 1;
            if (target == nums[mid])
                return mid;
            if (nums[mid] < nums[right]) // The right half is sorted
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else    // The left half is sorted
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid +1;
            }
        }
        return -1;
    }
};
