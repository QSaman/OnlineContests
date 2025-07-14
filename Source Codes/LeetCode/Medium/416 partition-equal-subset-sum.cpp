// This is a variant of 1-0 knapsack. Let's say sum is the sum of all elements
// in nums. If sum is odd, the answer is false. If we can solve 1-0 knapsack
// for sum / 2, then the remaining elements sum is sum / 2:
// dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
// We can remove one dimension:
// dp[j] = dp[j] || dp[j - nums[i]]
// Note we should update dp from right to left because j - nums[i] < j

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const auto sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        const auto target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (const auto num : nums)
        {
            for (int i = target; i >= num; --i)
                dp[i] = dp[i] || dp[i - num];
        }
        return dp[target];
    }
};
