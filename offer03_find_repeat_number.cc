#include <functional>
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
    int findRepeatNumber(vector<int>& nums) {
	    vector<int> has(nums.size(), 0);
        for (const auto& e : nums) {
            if (has[e])
                return e;
            else
                has[e] = 1;
        }
        return 0;
    }
};

int main()
{
    return 0;
}
