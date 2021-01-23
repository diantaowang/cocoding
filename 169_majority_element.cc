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
    int majorityElement(vector<int>& nums) {
 		int n = nums.size();
        if (!n) return 0;
        int val = nums[0], cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (cnt == 0) {
                val = nums[i];
                cnt = 1;
            } else if (nums[i] == val) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return val;
    }
};

int main()
{
    return 0;
}
