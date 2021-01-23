#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int start = 0, minimum = INT32_MAX, result = 0;
        sort(nums.begin(), nums.end());
        while (start < nums.size()) {
            int left = start + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[start] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if (diff < minimum) {
                    minimum = diff;
                    result = sum;
                }
                if (sum < target) 
                    ++left;
                else if (sum > target)
                    --right;
                else
                    return target;
            }
            ++start;
        }
        return result;
    }
};

int main()
{

    return 0;
}
