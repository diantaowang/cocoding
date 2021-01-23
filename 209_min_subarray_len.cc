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
    int minSubArrayLen(int s, vector<int>& nums) {
		int minlen = INT32_MAX;
        int l = 0, r = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            r = i;
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, r - l + 1);
                sum -= nums[l];
                ++l;
            }
        }
        return minlen == INT32_MAX ? 0 : minlen;
    }
};

int main()
{
    return 0;
}
