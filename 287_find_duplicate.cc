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
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int l = 1, r = size - 1;
        while (l < r) {
            int lcnt = 0;
            int mid = (l + r) / 2;
            for (int i = 0; i < size; ++i) {
                if (nums[i] <= mid)
                    ++lcnt;
            }
            if (lcnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    return 0;
}
