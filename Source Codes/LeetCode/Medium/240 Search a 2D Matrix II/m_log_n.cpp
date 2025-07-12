// This is O(m * log(n)) approach

#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int row = 0; row < matrix.size(); ++row)
		{
			int left = 0;
			int right = matrix[0].size() - 1;
			while (left <= right)
			{
				const auto mid = (left + right) >> 1;
				if (target == matrix[row][mid])
					return true;
				else if (target < matrix[row][mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return false;
	}
};
