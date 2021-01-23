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
    int singleNumber(vector<int>& nums) {
		int val = 0;
        for (const auto& e : nums)
            val ^= e;
        return val;
    }
};

int main()
{
    return 0;
}
