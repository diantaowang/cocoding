#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace::std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        int start = 0, left, right;
        while (start < nums.size() && nums[start] <= 0) {
            left = start + 1;
            right = nums.size() - 1;
            while (left < right) {
                int sum = nums[start] + nums[left] + nums[right];
                if (sum == 0) {
                    results.push_back({nums[start], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    --right;
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
            while (start + 1 < nums.size() && nums[start] == nums[start + 1])
                ++start;
            ++start;
        }
        return results;
    }
};

int main()
{
    Solution solu;
    vector<int> nums {-1, 0, 1, 2, -1, -4};
    solu.threeSum(nums);
    return 0;
}
