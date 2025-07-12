// https://leetcode.com/problems/search-a-2d-matrix/

// This is O(log(m) + log(n)) approach which is faster than the required solution O(log(m * n))

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;

        while (top <= bottom)
        {
            const auto midRow = (top + bottom) >> 1;
            if (target >= matrix[midRow].front() && target <= matrix[midRow].back())
            {       
                int left = 0;
                int right = matrix[0].size() - 1;                         
                while (left <= right)
                {
                    const auto midCol = (left + right) >> 1;
                    if (matrix[midRow][midCol] == target)
                        return true;
                    if (matrix[midRow][midCol] < target)
                        left = midCol + 1;
                    else
                        right = midCol - 1;

                }
                return false;
            }
            else if (target < matrix[midRow].front())
                bottom = midRow - 1;
            else
                top = midRow + 1;
        }
        return false;
    }
};
