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
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return false;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target)
                ++cnt;
        }
        return cnt > n / 2;
    }
};

int main()
{
    return 0;
}
