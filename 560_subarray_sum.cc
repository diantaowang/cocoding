#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        unordered_map<int, int> presum;
        ++presum[0];
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (presum.find(sum - k) != presum.end())
                cnt += presum[sum - k];
            ++presum[sum];
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
