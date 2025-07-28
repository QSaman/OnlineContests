// https://leetcode.com/problems/longest-increasing-subsequence/description/
// dp[i]: LIS that its last element is nums[i]
// The time complexity is O(n^2) and memory complexity is O(n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());        
    }
};
