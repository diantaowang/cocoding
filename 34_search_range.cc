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
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int first_pos = -1, second_pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                first_pos = mid;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                second_pos = mid;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return {first_pos, second_pos};
    }
};

int main()
{
    return 0;
}
