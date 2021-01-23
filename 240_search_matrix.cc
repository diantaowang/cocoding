#include <cstddef>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        if (!n) return false;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --i;
            else
                ++j;
        }
        return false;
    }
};

int main()
{
    return 0;
}
