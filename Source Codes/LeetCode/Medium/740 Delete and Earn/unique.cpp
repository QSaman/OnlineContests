// Let's assume nums are unique and sorted in ascending order:
// dp[i] = max(dp[i - 1], nums[i] + (nums[i - 1] == (nums[i] - 1) ? dp[i - 2] : dp[i - 1]))
// If nums is not unique, we create a new array named unique and freq. The first one only
// has the unique numbers in ascending order and the second one contains the frequencies of
// unique elements:
// dp[i] = max(dp[i - 1], unique[i] * freq[i] + (unique[i - 1] == (unique[i] - 1) ? dp[i - 2] : dp[i - 1]))

#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n * log(n))
        vector<int> unique;
        vector<int> freq;
        unique.reserve(nums.size());
        freq.reserve(nums.size());

        for (int left = 0, right = 1; left < nums.size(); left = right) // O(n)
        {
            for (right = left + 1; right < nums.size() && nums[left] == nums[right]; ++right);
            unique.push_back(nums[left]);
            freq.push_back(right - left);
        }

        int prev1 = unique[0] * freq[0]; // dp[i - 1]
        int prev2 = 0; // dp[i - 2]
        for (int i = 1; i < unique.size(); ++i) // O(n)
        {
            const int cur = max(prev1, unique[i] * freq[i] + (unique[i - 1] == (unique[i] - 1) ? prev2 : prev1));
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};