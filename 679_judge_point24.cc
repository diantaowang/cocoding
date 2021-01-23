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
	bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1 && abs(nums[0] - 24) < 0.000001)
            return true;
        if (n == 1)
            return false;

        vector<double> subnums, newelems(6);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        subnums.push_back(nums[k]);
                }
                newelems[0] = nums[i] + nums[j];
                newelems[1] = nums[i] - nums[j];
                newelems[2] = nums[i] * nums[j];
                newelems[3] = nums[i] / nums[j];
                newelems[4] = nums[j] - nums[i];
                newelems[5] = nums[j] / nums[i];
                for (int k = 0; k < 6; ++k) {
                    subnums.push_back(newelems[k]);
                    if (dfs(subnums))
                        return true;
                    subnums.pop_back();
                }
                subnums.clear();
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> mynums(4);
        for (int i = 0; i < 4; ++i)
            mynums[i] = nums[i];
        return dfs(mynums);	
    }
};

int main()
{
    return 0;
}
