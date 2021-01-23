#include <cstdint>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int max_num(const int &a, const int &b) {
        return  a > b ? a : b;
    }
    int lengthOfLIS_slow(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 1);
        for (unsigned i = 1; i != nums.size(); ++i) {
            for (unsigned j = i; j > 0; --j) {
                if (nums[i] > nums[j - 1]) 
                    dp[i] = max_num(dp[i], dp[j - 1] + 1);
            }
        }
        int max_len = 0;
        for (const auto &i : dp)
            max_len = max_num(max_len, i);
        return max_len;
    }
    int lengthOfLIS(vector<int> &nums) 
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(1, nums[0]);
        for (unsigned i = 1; i < nums.size(); ++i) {
            auto elem = nums[i];
            auto pos = find_if(dp.rbegin(), dp.rend(), 
                    [elem] (const int &a) { return elem > a;});
            if (pos == dp.crbegin())
                dp.push_back(elem);
            else
                *--pos = elem;
        }
        return dp.size();
    }
};


int main()
{
    vector<int> nums;
    int a = 0;
    while(cin >> a)
        nums.push_back(a);
    Solution solu;
    cout << solu.lengthOfLIS(nums) << endl;
    return 0;
}
