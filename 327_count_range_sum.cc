#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <set>

using namespace::std;

class Solution {
public:
    int count(vector<long long>& prefix, int l, int r, int lower, int upper) {
        if (l == r)
            return prefix[l] >= lower && prefix[l] <= upper;
        int mid = (l + r) / 2, result = 0;
        result += count(prefix, l, mid, lower, upper);
        result += count(prefix, mid + 1, r, lower, upper);
        for (int i = mid + 1; i <= r; ++i) {
            long long minval = prefix[i] - upper, maxval = prefix[i] - lower;
            auto begin = prefix.begin() + l, end = prefix.begin() + mid + 1;
            auto pos1 = lower_bound(begin, end, minval);
            auto pos2 = upper_bound(begin, end, maxval);
            if (pos1 != end)
                result += pos2 - pos1;
        }
        
        vector<long long> tmp(prefix.begin() + mid + 1, prefix.begin() + r + 1);
        int i = r - mid - 1, j = mid, k = r;
        while (i >= 0 && j >= l) {
            if (prefix[j] > tmp[i])
                prefix[k] = prefix[j--];
            else 
                prefix[k] = tmp[i--];
            --k;
        }
        while (i >= 0)
            prefix[k--] = tmp[i--];
        while (j >= l)
            prefix[k--] = prefix[j--];
        return result;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), result = 0;
        if (!n) return 0;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i];
        return count(prefix, 0, n - 1, lower, upper);
    }
};

int main()
{
    return 0;
}
