// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Let's assume s[0..5] = "abcdce"
// Let's say the sliding window is s[0..3] = "abcd" . the next sliding window is s[0..4] = "abcdc" 
// which is not valid. Therefore the next sliding window should be s[3..5] = "dce". As you can see
// the right is always increses by 1, so we only need to have one for loop

#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen; // key is a character and value is the index
        int res = 0;
        int left = 0;
        int right = 0;
        for (; right < s.length(); ++right)
        {
            auto iter = last_seen.find(s[right]);
            if (iter == last_seen.end())
                last_seen[s[right]] = right;
            else
            {
                if (iter->second >= left)
                {
                    res = max(res, right - left);
                    left = iter->second + 1;
                }
                iter->second = right;
            }
        }
        res = max(res, right - left);
        return res;
    }
};
