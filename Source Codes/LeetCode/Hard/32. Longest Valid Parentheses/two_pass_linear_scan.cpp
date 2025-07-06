#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0, right = 0;
        for (const auto& ch : s)
        {
            if (ch == '(')
                ++left;
            else
                ++right;
            if (left == right)
                res = max(res, left + right);
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;
        for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
        {
            const auto& ch = *iter;
            if (ch == '(')
                ++left;
            else
                ++right;
            if (left == right)
                res = max(res, left + right);
            else if (left > right)
                left = right = 0;
        }
        return res;
    }
};
