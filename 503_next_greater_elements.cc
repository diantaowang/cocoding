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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n - i; ++j) {
                while (!stk.empty() && nums[j] > nums[stk.top()]) {
                    ans[stk.top()] = nums[j];
                    stk.pop();
                }
                if (i == 0)
                    stk.push(j);
            }
        }
        while (!stk.empty()) {
            ans[stk.top()] = -1;
            stk.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}
