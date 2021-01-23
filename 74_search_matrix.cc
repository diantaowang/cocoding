#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>

using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        if (!n) return false;
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (matrix[l][0] == target)
            return true;
        else if (matrix[l][0] < target)
            l = m - 1;
        else if (l > 0)
            --l;
        int l2 = 0, r2 = n - 1;
        while (l2 < r2) {
            int mid = (l2 + r2) / 2;
            if (matrix[l][mid] < target)
                l2 = mid + 1;
            else
                r2 = mid;
        }
        return matrix[l][l2] == target;
    }
};

int main()
{
    return 0;
}
