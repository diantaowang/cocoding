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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i <= n - 4; ++i) {
            if (target >= 0 && nums[i] > target)
                break;
            if (target < 0 && nums[i] >= 0)
                break;
            
            for (int j = i + 1; j <= n - 3; ++j) {
                if (target >= 0 && nums[i] + nums[j] > target)
                    break;
                if (target < 0 && nums[i] + nums[j] > target && nums[j] >= 0)
                    break;
                
                int val = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int tmp = nums[l] + nums[r];
                    if (tmp == val) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            ++l;
                        while (r > l && nums[r] == nums[r - 1])
                            --r;
                        ++l;
                        --r;
                    } else if (tmp > val) {
                        --r;
                    } else {
                        ++l;
                    }
                }

                if (nums[j + 1] + nums[j + 2] > val)
                    break;
            
                while (j <= n - 2 && nums[j] == nums[j + 1])
                    ++j;
            }
            
            while (i <= n - 3 && nums[i] == nums[i + 1])
                ++i;
        }
        return result;
    }

    void dfs(vector<int>& nums, int sum, int cnt, int start, int target) {
        if (cnt == 4) {
            if (sum == target)
                res.push_back(ans);
            return;
        }
        int n = nums.size();
        for (int i = start; i < n; ++i) {
            if (target >= 0 && sum + nums[i] > target)
                return;
            if (target < 0 && sum + nums[i] > target && nums[i] > 0)
                return;
            ans.push_back(nums[i]);
            dfs(nums, sum + nums[i], cnt + 1, i + 1, target);
            ans.pop_back();
            while (i < n - 1 && nums[i] == nums[i + 1])
                ++i;
        }
    }
    
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, 0, target);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> ans;
};

int main()
{
    return 0;
}
