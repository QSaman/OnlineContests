#include <vector>
#include <algorithm>

// best[i]: The best LIS of size i + 1. The best LIS is the one that its last element is 
// minimum among all other LIS with size i + 1.
// Let's say mid is the index of the middle element of best:
// if nums[i] > best[mid]: nums[i] can extend best LIS of at least size mid + 2 so we
//                         should eliminate the left half
// if nums[i] <= best[mid]: nums[i] cannot extend any LIS with size at least mid + 1.
//                          So we should elminiate the right half
// The goal is to find the first element in sorted array best in such away that
// nums[i] < best[j]:
// If such j exists: best[j] = nums[i]
// If it doesn't exists: we should append it to best. So it size increases by 1 

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> best;
        best.reserve(nums.size());
        for (const auto num: nums)
        {
            auto iter = lower_bound(best.begin(), best.end(), num);
            if (iter == best.end())
                best.push_back(num);
            else
                *iter = num;
        }
        return best.size();
    }
};