#include <cmath>
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
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int res = 0, base = pow(2, n - 1);
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; ++j)
                    A[i][j] ^= 0x1;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 1)
                    ++cnt;
            }
            cnt = max(cnt, m - cnt);
            res += cnt * base;
            base >>= 1;
        }
        return res;
    }
};

int main()
{
    return 0;
}
