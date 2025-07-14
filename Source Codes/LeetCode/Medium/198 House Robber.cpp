// Let's say dp[i] is the optimal solution for nums[0..i]:
// dp[i] = max(dp[ i - 2] + nums[i], dp[i - 1]): nums[i] is either in solution
// (dp[i - 2] + nums[i]) or is absent (dp[i - 1]). We can also convert O(n) memory
// complexity to O(1) because we only need that last 2 elements

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0; // dp[ i - 1]
        int prev2 = 0; // dp[i - 2]

        for (const auto num : nums)
        {
            const int cur = max(prev2 + num, prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1; 
    }
};