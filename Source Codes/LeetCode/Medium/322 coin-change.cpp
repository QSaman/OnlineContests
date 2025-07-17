// This is unbound knapsack problem:
// dp[i][j]: minimum number of coins to make sum j using first i coins (coins[0..i-1])
// dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1) for j >= coins[i - 1]
// dp[i][0] = 0
// dp[0][j] = infinity for j > 0
//
// Note that for 0/1 knapsack the forumula is:
// dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - coins[i - 1]] + 1)

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int inf = 1e4 + 1;
        vector<int> dp(amount + 1, inf);
        dp[0] = 0;

        for (const auto coin : coins)
        {
            for (int i = coin; i <= amount; ++i) // It's importnat to go from left to right
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return (dp[amount] == inf ? -1 : dp[amount]);
    }
};
