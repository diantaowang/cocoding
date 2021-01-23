#include <exception>
#include <vector>
#include <algorithm>
#include <string>

using namespace::std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[r] > nums[l]) {
                if (target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (nums[mid] > nums[r]) {
                    if (target < nums[mid] && target > nums[r])
                        r = mid - 1;
                    else 
                        l = mid + 1;
                } else {
                    if (target > nums[mid] && target <= nums[r])
                        l = mid + 1;
                    else 
                        r = mid - 1;
                }
            }
        }
        if (nums[l] == target)
            return l;
        else 
            return -1;
    }
};
