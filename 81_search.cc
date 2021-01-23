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
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l]) {
                ++l;
            } else if (nums[mid] == nums[r]) {
                --r;
            } else if (nums[l] >= nums[r]) {
                if (nums[mid] > nums[r]) {
                    if (target <= nums[r] || target > nums[mid])
                        l = mid + 1;
                    else if (target < nums[mid])
                        r = mid - 1;
                } else {
                    if (target > nums[mid] && target <= nums[r])
                        l = mid + 1;
                    else 
                        r = mid - 1;
                } 
            } else {
                if (target < nums[mid])
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
