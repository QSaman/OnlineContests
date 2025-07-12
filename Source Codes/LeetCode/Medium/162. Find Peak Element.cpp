// if nums[mid] < nums[mid + 1]: The right half has at least one peak: [mid + 1, right]
// if nums[mid] > nums[mid + 1]: The left half has at least one peak: [left, mid]

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            const auto mid = (left + right) >> 1;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;                
    }
};
