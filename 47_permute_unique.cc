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
    void dfs(vector<int>& nums, vector<int>& ans, vector<bool>& visited, int deep) {
        int n = nums.size();
        if (deep == n) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                ans.push_back(nums[i]);
                dfs(nums, ans, visited, deep + 1);
                ans.pop_back();
                visited[i] = false;
                while (i < n - 1 && nums[i] == nums[i + 1])
                    ++i;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())
            return result;
        vector<int> ans;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, ans, visited, 0);
        return result;
    }
private:
    vector<vector<int>> result;
};

int main()
{
    return 0;
}
