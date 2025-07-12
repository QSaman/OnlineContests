// https://leetcode.com/problems/search-a-2d-matrix/

// For a O(log(m * n)) appraoch, we should consider 2-d array as one-dimensional

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        const auto m = matrix.size();
        const auto n = matrix[0].size(); 
        int left = 0;
        int right = m * n - 1;
        while (left <= right)
        {            
            const auto mid = (left + right) >> 1;
            const int row = mid / n;
            const int col = mid % n;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
