// https://leetcode.com/problems/product-of-array-except-self/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), suffix(nums.size());
        prefix.front() = nums.front();
        for (int i = 1; i < nums.size(); ++i)
            prefix[i] = prefix[i - 1] * nums[i];
        
        suffix.back() = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i)
            suffix[i] = suffix[i + 1] * nums[i];

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = (i > 0 ? prefix[i - 1] : 1) * (i < nums.size() - 1 ? suffix[i + 1] : 1);
        }
        return res;
    }
};
