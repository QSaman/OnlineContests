#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

template<>
struct hash<array<int, 26>>
{
    /// hash_combine from boost: https://www.boost.org/doc/libs/1_55_0/doc/html/hash/reference.html#boost.hash_combine
    /// @note It's very importatn that the operator() is defined as const:
    size_t operator()(const array<int, 26>& v) const
    {
        size_t h = 0;
        for (const auto& item : v)
            h ^= hash<int>{}(item) + 0x9e3779b6 + (h << 6) + (h >> 2);
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>> anagram;
        for (const auto& str : strs)
        {
            array<int, 26> key {0};
            for (const auto ch : str)
                ++key[ch - 'a'];
            anagram[key].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(anagram.size());
        for (const auto& [key, value] : anagram)
            res.push_back(value);
        return res;
    }
};
