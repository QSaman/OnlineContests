// https://leetcode.com/problems/group-anagrams/description/

// This solution is simple we use the sorted word as the key for an unordered_map

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        for (const auto& str : strs)
        {
            string key(str);
            sort(key.begin(), key.end());
            anagram[key].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(anagram.size());
        for (const auto& [key, value] : anagram)
            res.push_back(value);
        return res;
    }
};
