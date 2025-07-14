// Let's assume nums are unique and sorted in ascending order:
// dp[i] = max(dp[i - 1], nums[i] + (nums[i - 1] == (nums[i] - 1) ? dp[i - 2] : dp[i - 1]))
// If nums is not unique, we create a new array named unique and freq. The first one only
// has the unique numbers in ascending order and the second one contains the frequencies of
// unique elements:
// dp[i] = max(dp[i - 1], unique[i] * freq[i] + (unique[i - 1] == (unique[i] - 1) ? dp[i - 2] : dp[i - 1]))
// Instead of creating unique and freq vectors, we can also create sum[i] which is the sum of all i in the
// nums. By doing that no sort is required. The time complexity is O(n + m). n is the size of nums and m is
// the maximum element in nums:
// dp[i] = max(dp[i - 1], sum[i] + dp[i - 2])

#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        const auto maxElement = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxElement + 1, 0);
        for (const auto num : nums) // O(n)
            sum[num] += num;

        int prev1 = sum[1]; // dp[i - 1]. Note that nums[i] >= 1 so sum.length() >= 2
        int prev2 = sum[0]; // dp[i - 2]
        for (int i = 2; i < sum.size(); ++i) // O(m)
        {
            const int cur = max(prev1, sum[i] + prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};