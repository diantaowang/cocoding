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
    static bool cmp(const int& a, const int& b) {
        int t0 = a, t1 = b;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < 14; ++i) {
            cnt0 += t0 & 0x1;
            cnt1 += t1 & 0x1;
            t0 >>= 1;
            t1 >>= 1;
        }
        if (cnt0 == cnt1)
            return a < b;
        return cnt0 < cnt1;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};


int main()
{
    return 0;
}
