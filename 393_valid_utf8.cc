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
    bool judge(vector<int>& data, int l, int len) {
        if (l + len > data.size())
            return false;
        for (int i = l; i < l + len; ++i) {
            if (((data[i] >> 6) & 0x3) != 0x2)
                return false;
        }
        return true;
    } 

    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ) {
            if (((data[i] >> 7) & 0x1) == 0x0) {
                ++i;
            } else if (((data[i] >> 5) & 0x7) == 0x6) {
                if (!judge(data, i + 1, 1))
                    return false;
                i += 2;
            } else if (((data[i] >> 4) & 0xf) == 0xe) {
                if (!judge(data, i + 1, 2))
                    return false;
                i += 3;
            } else if (((data[i] >> 3) & 0x1f) == 0x1e) {
                if (!judge(data, i + 1, 3))
                    return false;
                i += 4;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
