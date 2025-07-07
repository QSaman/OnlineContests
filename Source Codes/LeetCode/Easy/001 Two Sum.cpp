// https://leetcode.com/problems/two-sum/description/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // key is number and value is index
        for (int i = 0; i < nums.size(); ++i) // O(n)
            if (const auto iter = mp.find(target - nums[i]); iter != mp.end())
                return {i, iter->second};
            else
                mp[nums[i]] = i;
        return {0, 0};
    }
};
