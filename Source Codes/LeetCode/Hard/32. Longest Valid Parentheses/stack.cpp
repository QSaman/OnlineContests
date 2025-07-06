// https://leetcode.com/problems/longest-valid-parentheses/description/
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> open; // The bottom of the stack is always a fake or actual )
        open.push(-1); // for handling cases that the answer starts from s[0]
        int res = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                open.push(i);
            }
            else
            {
                open.pop(); // the close paranthesis should be match with the last open one
                if (open.empty())
                {
                    open.push(i);
                }
                else
                {
                    res = max(res, i - open.top());
                }
            }
        }
        return res;
    }
};
