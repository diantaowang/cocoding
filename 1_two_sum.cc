#include <vector>
#include <algorithm>
#include <iostream>

using namespace::std;

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        for (int i = 0; i < nums.size(); ++i) {
            auto pos = find(nums.begin(), nums.end(), target - nums[i]);
            if (pos != nums.end()) {
                int j = pos - nums.begin();
                if (i != j) {
                    results.push_back(i);
                    results.push_back(j);
                }
            }
        }
        return results;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2), nums_sort = nums;
        sort(nums_sort.begin(), nums_sort.end());
        int i = 0, j = 0;
        for (i = 0; i < (int)nums_sort.size(); ++i) {
            auto pos = lower_bound(nums_sort.begin(), nums_sort.end(), target - nums_sort[i]);
            if (pos != nums_sort.end() && (*pos + nums_sort[i] == target)) {
                j = pos - nums_sort.begin();
                if (i != j)
                    break;
            }
        }
        int find = 0;
        for (int k = 0; k < (int)nums.size(); ++k) {
            if (find == 0 && nums[k] == nums_sort[i]) {
                result[0] = k;
                find = 1;
            } else if (nums[k] == nums_sort[j])
                result[1] = k;
        }
        return result;
    }
};

int main()
{
    vector<int> nums{2, 5, 5, 11};
    Solution solu;
    solu.twoSum(nums, 9);
}
