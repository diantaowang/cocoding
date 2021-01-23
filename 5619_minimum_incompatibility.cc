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
    int dfs(vector<int>& res, vector<int>& used, vector<int>& nums, int k, int state) {
        if (state == 0)
            return 0;
        if (res[state] != -2)
            return res[state];

        int n = nums.size();
        res[state] = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i])
                continue;
            
            int prev = nums[i], cnt = 1;
            int next = 1 << i;
            int minval = nums[i], maxval = nums[i]; 
            
            for (int j = i + 1; j < n && cnt < k; ++j) {
                if (!used[j] && nums[j] != prev) {
                    prev = nums[j];
                    next |= (1 << j);
                    ++cnt;
                    minval = min(minval, nums[j]);
                    maxval = max(maxval, nums[j]);
                }
            }
          
            if (cnt != k)
                break;
            
            for (int mask = 1, j = 0; mask < (1 << n); mask <<= 1, ++j) {
                if (next & mask)
                    used[j] = 1;
            }

            int subval = dfs(res, used, nums, k, state & (~next));
            if (subval != -1 && res[state] != -1)
                res[state] = min(res[state], maxval - minval + subval);
            else if (subval != -1)
                res[state] = maxval - minval + subval;

            for (int mask = 1, j = 0; mask < (1 << n); mask <<= 1, ++j) {
                if (next & mask)
                    used[j] = 0;
            }
            
            while (i < n - 1 && nums[i + 1] == nums[i])
                ++i;
        }
        return res[state];
    }

    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(1 << n, -2);
        vector<int> used(n, 0);
        sort(nums.begin(), nums.end());
        return dfs(res, used, nums, n / k, (1 << n) - 1); 
    }
};

int main()
{
    Solution solu;
    vector<int> nums;
    int k, t;
    cin >> k;
    while (cin >> t)
        nums.push_back(t);
    cout << solu.minimumIncompatibility(nums, k) << endl;;
    return 0;
}
