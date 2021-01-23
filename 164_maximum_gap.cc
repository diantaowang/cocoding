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
    int maximumGap(vector<int>& nums) {
        int n = nums.size(), maxval = 0, len = 0;
        if (n < 2)
            return 0;
        for (const auto& e : nums)
            maxval = max(maxval, e);
        while (maxval > 0) {
            ++len;
            maxval /= 10;
        }
        vector<int> cnts(10, 0);
        vector<int> tmp(n, 0);
        long long base = 1;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = (nums[j] / base) % 10;
                ++cnts[v];
            }
            int precnt = cnts[0];
            cnts[0] = 0;
            for (int j = 1; j < 10; ++j) {
                int t = cnts[j]; 
                cnts[j] = precnt;
                precnt += t;
            }
            for (int j = 0; j < n; ++j) {
                int v = (nums[j] / base) % 10;
                tmp[cnts[v]] = nums[j];
                ++cnts[v];
            }
            for (auto& e : cnts)
                e = 0;
            swap(tmp, nums);
            base *= 10;
        }
        int result = 0;
        for (int i = 0; i < n - 1; ++i)
            result = max(result, nums[i + 1] - nums[i]);
        return result;
    }
};

int main()
{
    return 0;
}
