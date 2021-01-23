#include <cstdlib>
#include <iterator>
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = (l + r) / 2, nr = INT32_MIN, nl = INT32_MAX;
            int row = n - 1, col = 0;
            int cnt = 0;
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    nr = max(nr, matrix[row][col]);
                    ++col;
                } else {
                    nl = min(nl, matrix[row][col]);
                    cnt += col;
                    --row;
                }
            }
            cnt += (row + 1) * n;
            if (cnt == k)
                return nr;
            else if (cnt > k)
                r = nr;
            else
                l = nl;
        }
        return l;
    }
};

int main()
{
    return 0;
}
