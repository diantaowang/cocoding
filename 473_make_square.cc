#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& sum, int n, int avg) {
        if (n == (int)nums.size())
            return sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3];

        for (int i = 0; i < 4; ++i) {
            if (sum[i] + nums[n] <= avg) {
                sum[i] += nums[n];
                if (dfs(nums, sum, n + 1, avg))
                    return true;
                sum[i] -= nums[n];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
		int all = 0;
        for (const auto& e: nums)
            all += e;
        if (all % 4 != 0 || nums.size() < 4)
            return false;
        vector<int> sum(4, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sum, 0, all / 4);
    }
};

int main()
{
    Solution solu;
    vector<int> nums;
    int val;
    while (cin >> val)
        nums.push_back(val);
    cout << solu.makesquare(nums) << endl;
    return 0;
}
