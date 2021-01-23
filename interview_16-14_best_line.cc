#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <cfloat>
#include <array>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    unsigned long long calc(vector<int>& a, vector<int>& b) {
        long long x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
        long long divisor = x1 - x2, dividend = y1 - y2;
        if (divisor == 0)
            return ((unsigned long long)x1 << 32) | 0; 
        if (dividend == 0)
            return (y1 & 0xffffffff);
        long long k = __gcd(divisor, dividend);
        return ((unsigned long long)(dividend / k) << 32) | ((divisor / k) & 0xffffffff);
    }
    
    vector<int> bestLine(vector<vector<int>>& points) {
        int n = points.size(), maxlen = 0;
        unordered_map<unsigned long long, pair<int, int>> slopes;
        vector<int> result(2);
        for (int i = 0; i < n; ++i) {
            int next_point = i, len = 0;
            for (int j = i + 1; j < n; ++j) {
                auto k = calc(points[i], points[j]);
                ++slopes[k].first;
                if (slopes[k].first == 1)
                    slopes[k].second = j;
                if (slopes[k].first > len) {
                    len = slopes[k].first;
                    next_point = slopes[k].second;
                }
            }
            if (len > maxlen) {
                result[0] = i;
                result[1] = next_point;
                maxlen = len;
            }
            slopes.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}
