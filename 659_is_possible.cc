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
    bool isPossible(vector<int>& nums) {
        int n = nums.size(), len1 = 0, len2 = 0, len3 = 0;
        int prev = nums[0], i = 0;
        for ( ; i < n && prev == nums[i]; ++i)
            ++len1;

        for (; i < n; ) {
            int cnt = 1;
            if (prev + 1 != nums[i] && (len1 || len2))
                return false;

            for (i += 1; i < n && nums[i] == nums[i - 1]; ++i)
                ++cnt;
            
            if (cnt < len1 + len2)
                return false;

            int res = cnt - len1 - len2;
            int tmp = min(len3, res);
            if (prev + 1 != nums[i - 1])
                tmp = 0;
            len3 = len2 + tmp;
            len2 = len1;
            len1 = res - tmp;
            prev = nums[i - 1];
        }
        return len1 == 0 && len2 == 0;
    }
};

int main()
{
    return 0;
}
