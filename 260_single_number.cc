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
    vector<int> singleNumber(vector<int>& nums) {
		int val = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            val ^= nums[i];
        int mask = val & (-val);
        int v0 = 0, v1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & mask)
                v0 ^= nums[i];
            else 
                v1 ^= nums[i];
        }
        return {v0, v1};
    }
};

int main()
{
    return 0;
}
