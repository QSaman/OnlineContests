#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int res = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == ')') // ()()
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i > 1 ? dp[i - 2] : 0 ) + 2;
                }
                else if (const auto parentIndex = i - dp[i - 1] - 1; parentIndex >= 0 && s[parentIndex] == '(') // (())
                {                    
                    dp[i] = dp[i - 1] + 2 + (parentIndex - 1 > 0 ? dp[parentIndex - 1] : 0);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
