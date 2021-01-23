#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (const auto& e : nums) {
            for (int i = e + 1; i < 101; ++i)
                ++cnt[i];
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            result[i] = cnt[nums[i]];
        return result;
    }
};

int main()
{
    return 0;
}
