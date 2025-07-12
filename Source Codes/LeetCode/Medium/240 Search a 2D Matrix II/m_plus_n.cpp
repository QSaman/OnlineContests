// This is O(m + n) approach. The key element here is to start either
// from matrix[m - 1][0] or from matrix[0][n - 1] so in each step
// either a row or col is elimianted. Please note that in binary
// search, the middle element is the max element in the left half
// and min element in the right half. It's the same principal here
// matrix[m - 1][0] is min element in the last row and it's max
// element in the first column. A similar argument for
// matrix[0][n - 1]. In other words, the following list is sorted:
// matrix[0][0..m-1], matrix[m - 1][0..n - 1]

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size())
        {
            if (target == matrix[row][col])
                return true;
            else if (target < matrix[row][col])
                --row;
            else
                ++col;
        }
        return false;
    }
};
