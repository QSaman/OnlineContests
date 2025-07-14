// Similar to 198. The solution is max(dp[0..nums.size() - 2], dp[1..nums.size() - 1])

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 1; i < nums.size(); ++i) // dp[1..nums.size() -1]
        {
            const int cur = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        int res = prev1;
        prev1 = nums[0];
        prev2 = 0;
        for (int i = 1; i < nums.size() - 1; ++i) // dp[0..nums.size() - 2]
        {
            const int cur = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        return max(res, prev1);
    }
};
