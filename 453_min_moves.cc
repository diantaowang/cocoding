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
    int minMoves(vector<int>& nums) {
        long long sum = 0, minval = INT32_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            minval = min(minval, (long long)nums[i]);
        }
        return sum - minval * n;
    }
};

int main()
{
    return 0;
}
