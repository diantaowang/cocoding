#include <c++/7/bits/c++config.h>
#include <cwctype>
#include <type_traits>
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
    void dfs(vector<int>& candidates, int sum, int start, int target) {
        int n = candidates.size();
        for (int i = start; i < n; ++i) {
            if (sum + candidates[i] > target) {
                break;
            } else if (sum + candidates[i] == target) {
                ans.push_back(candidates[i]);
                res.push_back(ans);
                ans.pop_back();
                break;
            } else {
                sum += candidates[i];
                ans.push_back(candidates[i]);
                dfs(candidates, sum, i + 1, target);
                ans.pop_back();
                sum -= candidates[i];
            }
            while (i < n - 1 && candidates[i] == candidates[i + 1])
                ++i;
        } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
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
