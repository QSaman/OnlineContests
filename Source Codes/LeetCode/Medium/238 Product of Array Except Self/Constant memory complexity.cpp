// https://leetcode.com/problems/product-of-array-except-self/description/

// In the first pass, we reuse the output vector to calculate prefix products.
// In the second pass, we use a new variable suffix to calculate suffix products
// and multply the result with the prefix producs which are already stored in
// the output vector

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] * nums[i - 1];
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            suffix *= nums[i + 1];
            res[i] *= suffix;
        }
        return res;
    }
};
