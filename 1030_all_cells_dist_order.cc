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
    inline int inBound(int R, int C, int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        int len = 0, has = 1;
        while (has) {
            has = 0; 
            for (int dx = 0; dx <= len; ++dx) {
                int dy = len - dx;
                if (inBound(R, C, r0 + dx, c0 + dy)) {
                    ++has;
                    result.push_back({r0 + dx, c0 + dy});
                }
                if (inBound(R, C, r0 + dx, c0 - dy) && dy) {
                    ++has;
                    result.push_back({r0 + dx, c0 - dy});
                }
                if (inBound(R, C, r0 - dx, c0 - dy) && dx && dy) {
                    ++has;
                    result.push_back({r0 - dx, c0 - dy});
                }
                if (inBound(R, C, r0 - dx, c0 + dy) && dx) {
                    ++has;
                    result.push_back({r0 - dx, c0 + dy});
                }
            }
            ++len;
        }
        return result;
    }
};

int main()
{
    return 0;
}
