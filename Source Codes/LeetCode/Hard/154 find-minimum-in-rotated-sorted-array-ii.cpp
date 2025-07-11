// if nums[left] == nums[mid] == nums[right]: [left + 1, right - 1]
// if nums[left] == nums[mid] < nums[right]: [left, mid - 1]
// if nums[left] == nums[mid] > nums[right]: [mid + 1, right]
// if nums[left] < nums[mid] == nums[right]: [left, mid - 1]
// if nums[left] < nums[mid] < nums[right]: [left, mid - 1]
// if nums[left] < nums[mid] > nums[right]: [mid + 1, right]
// if nums[left] > nums[mid] == nums[right]: [mid + 1, right]
// if nums[left] > nums[mid] < nums[right]: [left + 1, mid]
// if nums[left] > nums[mid] > nums[right]: invalid

//We can simply to:

// if nums[left] == nums[mid] == nums[right]: [left + 1, right - 1]: [left + 1, right - 1]
// else if nums[mid] <= nums[right]: [left , mid]
// else [mid +1, right]

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
            if (nums[left] == nums[mid] && nums[mid] == nums[right])
                ++left, --right;
            else if (nums[mid] <= nums[right])
                right = mid;
            else
                left = mid + 1;
            
        }
        return nums[left];        
    }
};