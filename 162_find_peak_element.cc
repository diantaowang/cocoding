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
    int findPeakElement(vector<int>& nums) {
		int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid == 0) {
                if (nums[0] > nums[1])
                    return 0;
                l = mid + 1;
            } else if (mid == n - 1) {
                if (nums[n - 1] > nums[n - 2])
                    return n - 1;
                r = mid - 1;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return nums[mid];
            } else if (nums[mid] < nums[mid - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main()
{
    return 0;
}
