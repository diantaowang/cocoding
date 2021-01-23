#include <type_traits>
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n < 2)
            return;
        int l = 0, r = n - 1, u = 0, d = n - 1;
        while (l < r) {
            int y0 = l, x1 = u, y2 = r, x3 = d;
            for (int i = l; i < r; ++i) {
                int tmp = matrix[u][y0];
                matrix[u][y0] = matrix[x3][l];
                matrix[x3][l] = matrix[d][y2];
                matrix[d][y2] = matrix[x1][r];
                matrix[x1][r] = tmp;
                ++y0;
                --x3;
                --y2;
                ++x1;
            }
            ++l;
            --r;
            ++u;
            --d;
        }
    }
};

int main()
{
    return 0;
}
