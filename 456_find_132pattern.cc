#include <cstdint>
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
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), subval = INT32_MIN;
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < subval)
                return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                subval = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    return 0;
}
