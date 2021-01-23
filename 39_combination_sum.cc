#include <cstdlib>
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
    void dfs(vector<int>& candidates, vector<int>& ans, int target, int idx) {
        if (target == 0)
            result.push_back(ans);
        if (target <= 0)
            return;
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                return;
            ans.push_back(candidates[i]);
            dfs(candidates, ans, target - candidates[i], i);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, ans, target, 0);
        return result;
    }
private:
    vector<vector<int>> result;
};

int main()
{
    return 0;
}
