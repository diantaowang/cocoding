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
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int> (n));
        int l = 0, r = n - 1, u = 0, d = n - 1, val = 0;
        while (l <= r) {
            for (int j = l; j <= r; ++j)
                result[u][j] = ++val;
            for (int i = u + 1; i <= d; ++i)
                result[i][r] = ++val;
            for (int j = r - 1; j >= l; --j)
                result[d][j] = ++val;
            for (int i = d - 1; i >= u + 1; --i)
                result[i][l] = ++val;
            ++l;
            --r;
            ++u;
            --d;
        }
        return result;
    }
};


int main()
{
    return 0;
}
