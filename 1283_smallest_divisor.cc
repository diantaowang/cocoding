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
    int smallestDivisor(vector<int>& nums, int threshold) {
		int n = nums.size();
        int l = 1, r = nums[0], result = 1;
        for (int i = 1; i < n; ++i)
            r = max(r, nums[i]);
        while (l <= r) {
            int sum = 0, mid = (l + r) / 2;
            for (int i = 0; i < n; ++i) {
                if (nums[i] % mid == 0)
                    sum += nums[i] / mid;
                else
                    sum += nums[i] / mid + 1;
            }
            if (sum <= threshold) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
