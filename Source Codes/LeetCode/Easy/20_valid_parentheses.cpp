// https://leetcode.com/problems/valid-parentheses/description/
#include <stack>

class Solution {
public:
    bool valid(char close, char unmatched)
    {
        return (close == ')' && unmatched == '(') || (close == ']' && unmatched == '[') || (close == '}' && unmatched == '{');
    }
    bool isValid(string s) {
        stack<char> unmatched;
        for (const auto& ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
                unmatched.push(ch);
            else if (unmatched.empty())
                return false;
            else if (valid(ch, unmatched.top()))
                unmatched.pop();
            else
                return false;
        }
        return unmatched.empty();
    }
};
